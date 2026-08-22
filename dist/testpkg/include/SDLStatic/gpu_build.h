/**
 * @file gpu_build.h
 * @brief Heap builders for SDL's GPU descriptor structs.
 *
 * Original SDLStatic code (zlib).
 *
 * 182 of SDL's GPU functions were already bound into Lua and Ruby, and
 * almost none of them could be called: they take descriptor structs a C
 * caller fills in on the stack, and a script has no stack to put one on.
 * The same shape as SDL_Event and the joint definitions, at a larger scale.
 *
 *     -- a render pass, from Lua
 *     local target = GPUBuild.ColorTargetInfoCreate()
 *     GPUBuild.ColorTargetInfoSetTexture(target, swapchain)
 *     GPUBuild.ColorTargetInfoSetClearColor(target, 0.1, 0.1, 0.15, 1.0)
 *     GPUBuild.ColorTargetInfoSetOps(target, SDL.GPU_LOADOP_CLEAR,
 *                                    SDL.GPU_STOREOP_STORE)
 *     local pass = SDL.BeginGPURenderPass(cmd, target, 1, nil)
 *
 * Most of these are flat: create, set fields, pass to SDL, destroy. The
 * pipeline descriptor is not — it holds arrays of vertex buffers, vertex
 * attributes and colour targets — so it gets **append** functions instead
 * of setters, and owns the arrays it builds. That keeps a script from
 * having to allocate a C array, which is the thing it cannot do.
 *
 * C code should keep using stack structs; this exists for the languages
 * that cannot.
 */
#ifndef SDLSTATIC_GPU_BUILD_H
#define SDLSTATIC_GPU_BUILD_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

/* --- render pass targets --------------------------------------------------- */

extern SDL_GPUColorTargetInfo *SDLStatic_GPUColorTargetInfoCreate(void);
extern void SDLStatic_GPUColorTargetInfoDestroy(SDL_GPUColorTargetInfo *info);
extern void SDLStatic_GPUColorTargetInfoSetTexture(SDL_GPUColorTargetInfo *info,
                                                   SDL_GPUTexture *texture);
extern void SDLStatic_GPUColorTargetInfoSetClearColor(SDL_GPUColorTargetInfo *info, float r,
                                                      float g, float b, float a);
extern void SDLStatic_GPUColorTargetInfoSetOps(SDL_GPUColorTargetInfo *info,
                                               SDL_GPULoadOp load_op,
                                               SDL_GPUStoreOp store_op);
extern void SDLStatic_GPUColorTargetInfoSetMipLayer(SDL_GPUColorTargetInfo *info, Uint32 mip,
                                                    Uint32 layer_or_depth);
extern void SDLStatic_GPUColorTargetInfoSetCycle(SDL_GPUColorTargetInfo *info, bool cycle);

extern SDL_GPUDepthStencilTargetInfo *SDLStatic_GPUDepthStencilTargetInfoCreate(void);
extern void SDLStatic_GPUDepthStencilTargetInfoDestroy(SDL_GPUDepthStencilTargetInfo *info);
extern void SDLStatic_GPUDepthStencilTargetInfoSetTexture(SDL_GPUDepthStencilTargetInfo *info,
                                                          SDL_GPUTexture *texture);
extern void SDLStatic_GPUDepthStencilTargetInfoSetClear(SDL_GPUDepthStencilTargetInfo *info,
                                                        float depth, Uint8 stencil);
extern void SDLStatic_GPUDepthStencilTargetInfoSetOps(SDL_GPUDepthStencilTargetInfo *info,
                                                      SDL_GPULoadOp load_op,
                                                      SDL_GPUStoreOp store_op);

/* --- shaders ---------------------------------------------------------------- */

extern SDL_GPUShaderCreateInfo *SDLStatic_GPUShaderCreateInfoCreate(void);
extern void SDLStatic_GPUShaderCreateInfoDestroy(SDL_GPUShaderCreateInfo *info);
/** The compiled shader, as bytes. Copied, so a script's string may be
 *  collected immediately afterwards. */
extern void SDLStatic_GPUShaderCreateInfoSetCode(SDL_GPUShaderCreateInfo *info,
                                                 const void *code, int size);
extern void SDLStatic_GPUShaderCreateInfoSetEntrypoint(SDL_GPUShaderCreateInfo *info,
                                                       const char *entrypoint);
extern void SDLStatic_GPUShaderCreateInfoSetFormat(SDL_GPUShaderCreateInfo *info,
                                                   SDL_GPUShaderFormat format,
                                                   SDL_GPUShaderStage stage);
extern void SDLStatic_GPUShaderCreateInfoSetCounts(SDL_GPUShaderCreateInfo *info,
                                                   Uint32 samplers, Uint32 storage_textures,
                                                   Uint32 storage_buffers,
                                                   Uint32 uniform_buffers);

/* --- graphics pipelines ----------------------------------------------------- */

/**
 * The pipeline descriptor, which owns the arrays it builds.
 *
 * Vertex buffers, vertex attributes and colour targets are arrays in the C
 * struct. A script cannot allocate one, so these append instead — the
 * builder grows its own storage and points the descriptor at it, and frees
 * the lot on destroy. The descriptor must outlive the create call, which is
 * the ordinary rule for these anyway.
 */
extern SDL_GPUGraphicsPipelineCreateInfo *SDLStatic_GPUPipelineInfoCreate(void);
extern void SDLStatic_GPUPipelineInfoDestroy(SDL_GPUGraphicsPipelineCreateInfo *info);
extern void SDLStatic_GPUPipelineInfoSetShaders(SDL_GPUGraphicsPipelineCreateInfo *info,
                                                SDL_GPUShader *vertex,
                                                SDL_GPUShader *fragment);
extern void SDLStatic_GPUPipelineInfoSetPrimitive(SDL_GPUGraphicsPipelineCreateInfo *info,
                                                  SDL_GPUPrimitiveType primitive);
extern void SDLStatic_GPUPipelineInfoSetFillMode(SDL_GPUGraphicsPipelineCreateInfo *info,
                                                 SDL_GPUFillMode fill, SDL_GPUCullMode cull);

/** One vertex buffer slot: which slot, the stride in bytes, and whether it
 *  advances per vertex or per instance. */
extern bool SDLStatic_GPUPipelineInfoAddVertexBuffer(SDL_GPUGraphicsPipelineCreateInfo *info,
                                                     Uint32 slot, Uint32 pitch,
                                                     SDL_GPUVertexInputRate input_rate);

/** One attribute: shader location, which buffer slot it reads from, its
 *  format, and its byte offset within the vertex. */
extern bool SDLStatic_GPUPipelineInfoAddVertexAttribute(SDL_GPUGraphicsPipelineCreateInfo *info,
                                                        Uint32 location, Uint32 buffer_slot,
                                                        SDL_GPUVertexElementFormat format,
                                                        Uint32 offset);

/** One colour target format the pipeline writes to. Must match the render
 *  pass it is used in. */
extern bool SDLStatic_GPUPipelineInfoAddColorTarget(SDL_GPUGraphicsPipelineCreateInfo *info,
                                                    SDL_GPUTextureFormat format);

extern void SDLStatic_GPUPipelineInfoSetDepthStencil(SDL_GPUGraphicsPipelineCreateInfo *info,
                                                     SDL_GPUTextureFormat format, bool enabled);

extern SDL_GPUComputePipelineCreateInfo *SDLStatic_GPUComputePipelineInfoCreate(void);
extern void SDLStatic_GPUComputePipelineInfoDestroy(SDL_GPUComputePipelineCreateInfo *info);
extern void SDLStatic_GPUComputePipelineInfoSetCode(SDL_GPUComputePipelineCreateInfo *info,
                                                    const void *code, int size);
extern void SDLStatic_GPUComputePipelineInfoSetEntrypoint(SDL_GPUComputePipelineCreateInfo *info,
                                                          const char *entrypoint);
extern void SDLStatic_GPUComputePipelineInfoSetFormat(SDL_GPUComputePipelineCreateInfo *info,
                                                      SDL_GPUShaderFormat format);
extern void SDLStatic_GPUComputePipelineInfoSetThreadCount(
    SDL_GPUComputePipelineCreateInfo *info, Uint32 x, Uint32 y, Uint32 z);

/* --- bindings --------------------------------------------------------------- */

extern SDL_GPUBufferBinding *SDLStatic_GPUBufferBindingCreate(void);
extern void SDLStatic_GPUBufferBindingDestroy(SDL_GPUBufferBinding *binding);
extern void SDLStatic_GPUBufferBindingSet(SDL_GPUBufferBinding *binding, SDL_GPUBuffer *buffer,
                                          Uint32 offset);

extern SDL_GPUTextureSamplerBinding *SDLStatic_GPUTextureSamplerBindingCreate(void);
extern void SDLStatic_GPUTextureSamplerBindingDestroy(SDL_GPUTextureSamplerBinding *binding);
extern void SDLStatic_GPUTextureSamplerBindingSet(SDL_GPUTextureSamplerBinding *binding,
                                                  SDL_GPUTexture *texture,
                                                  SDL_GPUSampler *sampler);

/* --- copy pass -------------------------------------------------------------- */

extern SDL_GPUTransferBufferLocation *SDLStatic_GPUTransferBufferLocationCreate(void);
extern void SDLStatic_GPUTransferBufferLocationDestroy(SDL_GPUTransferBufferLocation *location);
extern void SDLStatic_GPUTransferBufferLocationSet(SDL_GPUTransferBufferLocation *location,
                                                   SDL_GPUTransferBuffer *buffer, Uint32 offset);

extern SDL_GPUBufferRegion *SDLStatic_GPUBufferRegionCreate(void);
extern void SDLStatic_GPUBufferRegionDestroy(SDL_GPUBufferRegion *region);
extern void SDLStatic_GPUBufferRegionSet(SDL_GPUBufferRegion *region, SDL_GPUBuffer *buffer,
                                         Uint32 offset, Uint32 size);

extern SDL_GPUBufferLocation *SDLStatic_GPUBufferLocationCreate(void);
extern void SDLStatic_GPUBufferLocationDestroy(SDL_GPUBufferLocation *location);
extern void SDLStatic_GPUBufferLocationSet(SDL_GPUBufferLocation *location,
                                           SDL_GPUBuffer *buffer, Uint32 offset);

extern SDL_GPUTextureTransferInfo *SDLStatic_GPUTextureTransferInfoCreate(void);
extern void SDLStatic_GPUTextureTransferInfoDestroy(SDL_GPUTextureTransferInfo *info);
extern void SDLStatic_GPUTextureTransferInfoSet(SDL_GPUTextureTransferInfo *info,
                                                SDL_GPUTransferBuffer *buffer, Uint32 offset,
                                                Uint32 pixels_per_row, Uint32 rows_per_layer);

extern SDL_GPUTextureRegion *SDLStatic_GPUTextureRegionCreate(void);
extern void SDLStatic_GPUTextureRegionDestroy(SDL_GPUTextureRegion *region);
extern void SDLStatic_GPUTextureRegionSet(SDL_GPUTextureRegion *region, SDL_GPUTexture *texture,
                                          Uint32 x, Uint32 y, Uint32 w, Uint32 h);

extern SDL_GPUTextureLocation *SDLStatic_GPUTextureLocationCreate(void);
extern void SDLStatic_GPUTextureLocationDestroy(SDL_GPUTextureLocation *location);
extern void SDLStatic_GPUTextureLocationSet(SDL_GPUTextureLocation *location,
                                            SDL_GPUTexture *texture, Uint32 x, Uint32 y,
                                            Uint32 z);

extern SDL_GPUBlitInfo *SDLStatic_GPUBlitInfoCreate(void);
extern void SDLStatic_GPUBlitInfoDestroy(SDL_GPUBlitInfo *info);
extern void SDLStatic_GPUBlitInfoSetSource(SDL_GPUBlitInfo *info, SDL_GPUTexture *texture,
                                           Uint32 x, Uint32 y, Uint32 w, Uint32 h);
extern void SDLStatic_GPUBlitInfoSetDestination(SDL_GPUBlitInfo *info, SDL_GPUTexture *texture,
                                                Uint32 x, Uint32 y, Uint32 w, Uint32 h);
extern void SDLStatic_GPUBlitInfoSetFilter(SDL_GPUBlitInfo *info, SDL_GPUFilter filter);

/* --- the swapchain ---------------------------------------------------------- */

/**
 * Acquire the window's swapchain texture.
 *
 * SDL's version returns the texture through an `SDL_GPUTexture **`, which
 * the generator cannot bind — so the one call every GPU frame starts with
 * was unreachable. This returns the texture instead, and reports the size
 * through SDLStatic_GPUSwapchainWidth/Height, which a script reads after.
 *
 * NULL is not an error: it means the swapchain is not ready this frame,
 * and the correct response is to skip the frame rather than to stop.
 */
extern SDL_GPUTexture *SDLStatic_GPUAcquireSwapchain(SDL_GPUCommandBuffer *command_buffer,
                                                     SDL_Window *window);

extern Uint32 SDLStatic_GPUSwapchainWidth(void);
extern Uint32 SDLStatic_GPUSwapchainHeight(void);

/** The blocking variant, which waits for the previous frame rather than
 *  returning NULL. Steadier pacing, less latency headroom; SDL recommends
 *  it for games that do not want to handle the skip. */
extern SDL_GPUTexture *SDLStatic_GPUWaitAndAcquireSwapchain(SDL_GPUCommandBuffer *command_buffer,
                                                            SDL_Window *window);

/* --- getting data onto the device ------------------------------------------ */

/**
 * Fill a transfer buffer from a block of bytes.
 *
 * SDL's route is SDL_MapGPUTransferBuffer, write through the pointer, then
 * unmap. The map returns a `void *`, which the generator cannot bind, so a
 * script had no way to get a single vertex onto the device — the API was
 * bound and inert. This does the map, the copy and the unmap together,
 * which is what the C call sites do anyway.
 *
 * In Lua the bytes are a string, so `string.pack("fff", x, y, z)` builds a
 * vertex; in Ruby, `[x, y, z].pack("f*")`.
 */
extern bool SDLStatic_GPUUploadToTransferBuffer(SDL_GPUDevice *device,
                                                SDL_GPUTransferBuffer *buffer, Uint32 offset,
                                                const void *data, int size, bool cycle);

/**
 * Read a transfer buffer back after a download pass.
 *
 * Returns an SDL_malloc'd copy — free it with SDL_free — or NULL. Scripts
 * get it as a string of bytes to unpack.
 */
extern void *SDLStatic_GPUReadTransferBuffer(SDL_GPUDevice *device,
                                             SDL_GPUTransferBuffer *buffer, Uint32 offset,
                                             int size);

/* --- storage bindings ------------------------------------------------------- */

/**
 * Bind one storage buffer or texture to a slot.
 *
 * SDL's versions take a `SDL_GPUBuffer *const *` — an array of pointers,
 * which a script cannot build. These bind a single slot, which is what the
 * overwhelming majority of call sites do; a shader wanting several calls
 * them once per slot.
 */
extern void SDLStatic_GPUBindVertexStorageBuffer(SDL_GPURenderPass *pass, Uint32 slot,
                                                 SDL_GPUBuffer *buffer);
extern void SDLStatic_GPUBindVertexStorageTexture(SDL_GPURenderPass *pass, Uint32 slot,
                                                  SDL_GPUTexture *texture);
extern void SDLStatic_GPUBindFragmentStorageBuffer(SDL_GPURenderPass *pass, Uint32 slot,
                                                   SDL_GPUBuffer *buffer);
extern void SDLStatic_GPUBindFragmentStorageTexture(SDL_GPURenderPass *pass, Uint32 slot,
                                                    SDL_GPUTexture *texture);
extern void SDLStatic_GPUBindComputeStorageBuffer(SDL_GPUComputePass *pass, Uint32 slot,
                                                  SDL_GPUBuffer *buffer);
extern void SDLStatic_GPUBindComputeStorageTexture(SDL_GPUComputePass *pass, Uint32 slot,
                                                   SDL_GPUTexture *texture);

/* --- compute passes --------------------------------------------------------- */

/**
 * The read-write bindings a compute pass begins with.
 *
 * SDL_BeginGPUComputePass takes two arrays of these. Same problem as the
 * pipeline descriptor and the same answer: append, and let the builder own
 * the storage.
 *
 *     local binds = GPUBuild.ComputeBindingsCreate()
 *     GPUBuild.ComputeBindingsAddBuffer(binds, output_buffer, true)
 *     local pass = GPUBuild.BeginComputePass(cmd, binds)
 */
typedef struct SDLStatic_GPUComputeBindings SDLStatic_GPUComputeBindings;

extern SDLStatic_GPUComputeBindings *SDLStatic_GPUComputeBindingsCreate(void);
extern void SDLStatic_GPUComputeBindingsDestroy(SDLStatic_GPUComputeBindings *bindings);
extern bool SDLStatic_GPUComputeBindingsAddBuffer(SDLStatic_GPUComputeBindings *bindings,
                                                  SDL_GPUBuffer *buffer, bool cycle);
extern bool SDLStatic_GPUComputeBindingsAddTexture(SDLStatic_GPUComputeBindings *bindings,
                                                   SDL_GPUTexture *texture, Uint32 mip_level,
                                                   Uint32 layer, bool cycle);

/** Begin a compute pass with those bindings. `bindings` may be NULL for a
 *  pass that writes nothing, which is legal and rare. */
extern SDL_GPUComputePass *SDLStatic_GPUBeginComputePass(SDL_GPUCommandBuffer *command_buffer,
                                                         SDLStatic_GPUComputeBindings *bindings);

/* --- fences ----------------------------------------------------------------- */

/** Wait for one fence. SDL's call takes an array; almost every caller has a
 *  single fence, and a script cannot build the array. */
extern bool SDLStatic_GPUWaitForFence(SDL_GPUDevice *device, SDL_GPUFence *fence);

/* --- render states (the 2D renderer's GPU hook) ----------------------------- */

extern SDL_GPURenderStateCreateInfo *SDLStatic_GPURenderStateInfoCreate(void);
extern void SDLStatic_GPURenderStateInfoDestroy(SDL_GPURenderStateCreateInfo *info);
extern void SDLStatic_GPURenderStateInfoSetShader(SDL_GPURenderStateCreateInfo *info,
                                                  SDL_GPUShader *fragment_shader);

/** An extra sampler the custom fragment shader reads from, appended in
 *  binding order. */
extern bool SDLStatic_GPURenderStateInfoAddSampler(SDL_GPURenderStateCreateInfo *info,
                                                   SDL_GPUTexture *texture,
                                                   SDL_GPUSampler *sampler);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_GPU_BUILD_H */
