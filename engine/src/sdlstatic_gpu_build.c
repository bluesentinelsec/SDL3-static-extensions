/*
 * sdlstatic_gpu_build.c — heap builders for SDL's GPU descriptors.
 * Original SDLStatic code (zlib).
 *
 * 182 GPU functions were bound and nearly none callable, because they take
 * descriptor structs a C caller fills in on the stack. Same shape as
 * SDL_Event and the Box2D joint defs, at a larger scale.
 *
 * Most are flat and mechanical. The pipeline descriptor is not: it points
 * at arrays of vertex buffers, attributes and colour targets, so its
 * builder owns those arrays and grows them as a script appends.
 */
#include <SDLStatic/gpu_build.h>

/* Every flat descriptor is create-zeroed / free, which is the whole of its
   lifetime management. */
#define DEFINE_FLAT_BUILDER(Type, name)                                                          \
    Type *SDLStatic_##name##Create(void)                                                         \
    {                                                                                            \
        return (Type *)SDL_calloc(1, sizeof(Type));                                              \
    }                                                                                            \
    void SDLStatic_##name##Destroy(Type *value)                                                  \
    {                                                                                            \
        SDL_free(value);                                                                         \
    }

DEFINE_FLAT_BUILDER(SDL_GPUColorTargetInfo, GPUColorTargetInfo)
DEFINE_FLAT_BUILDER(SDL_GPUDepthStencilTargetInfo, GPUDepthStencilTargetInfo)
DEFINE_FLAT_BUILDER(SDL_GPUBufferBinding, GPUBufferBinding)
DEFINE_FLAT_BUILDER(SDL_GPUTextureSamplerBinding, GPUTextureSamplerBinding)
DEFINE_FLAT_BUILDER(SDL_GPUTransferBufferLocation, GPUTransferBufferLocation)
DEFINE_FLAT_BUILDER(SDL_GPUBufferRegion, GPUBufferRegion)
DEFINE_FLAT_BUILDER(SDL_GPUBufferLocation, GPUBufferLocation)
DEFINE_FLAT_BUILDER(SDL_GPUTextureTransferInfo, GPUTextureTransferInfo)
DEFINE_FLAT_BUILDER(SDL_GPUTextureRegion, GPUTextureRegion)
DEFINE_FLAT_BUILDER(SDL_GPUTextureLocation, GPUTextureLocation)
DEFINE_FLAT_BUILDER(SDL_GPUBlitInfo, GPUBlitInfo)

/* --- render pass targets --------------------------------------------------- */

void SDLStatic_GPUColorTargetInfoSetTexture(SDL_GPUColorTargetInfo *info, SDL_GPUTexture *texture)
{
    if (info != NULL)
    {
        info->texture = texture;
    }
}

void SDLStatic_GPUColorTargetInfoSetClearColor(SDL_GPUColorTargetInfo *info, float r, float g,
                                               float b, float a)
{
    if (info != NULL)
    {
        info->clear_color = (SDL_FColor){r, g, b, a};
    }
}

void SDLStatic_GPUColorTargetInfoSetOps(SDL_GPUColorTargetInfo *info, SDL_GPULoadOp load_op,
                                        SDL_GPUStoreOp store_op)
{
    if (info != NULL)
    {
        info->load_op = load_op;
        info->store_op = store_op;
    }
}

void SDLStatic_GPUColorTargetInfoSetMipLayer(SDL_GPUColorTargetInfo *info, Uint32 mip,
                                             Uint32 layer_or_depth)
{
    if (info != NULL)
    {
        info->mip_level = mip;
        info->layer_or_depth_plane = layer_or_depth;
    }
}

void SDLStatic_GPUColorTargetInfoSetCycle(SDL_GPUColorTargetInfo *info, bool cycle)
{
    if (info != NULL)
    {
        info->cycle = cycle;
    }
}

void SDLStatic_GPUDepthStencilTargetInfoSetTexture(SDL_GPUDepthStencilTargetInfo *info,
                                                   SDL_GPUTexture *texture)
{
    if (info != NULL)
    {
        info->texture = texture;
    }
}

void SDLStatic_GPUDepthStencilTargetInfoSetClear(SDL_GPUDepthStencilTargetInfo *info, float depth,
                                                 Uint8 stencil)
{
    if (info != NULL)
    {
        info->clear_depth = depth;
        info->clear_stencil = stencil;
    }
}

void SDLStatic_GPUDepthStencilTargetInfoSetOps(SDL_GPUDepthStencilTargetInfo *info,
                                               SDL_GPULoadOp load_op, SDL_GPUStoreOp store_op)
{
    if (info != NULL)
    {
        info->load_op = load_op;
        info->store_op = store_op;
    }
}

/* --- shaders ---------------------------------------------------------------- */

/* The code and entrypoint are borrowed pointers in the struct. A script's
   string may be collected the moment the setter returns, so the builder
   owns copies — which is why these are not flat builders. */
typedef struct ShaderBlock
{
    SDL_GPUShaderCreateInfo info;
    void *code;
    char *entrypoint;
} ShaderBlock;

SDL_GPUShaderCreateInfo *SDLStatic_GPUShaderCreateInfoCreate(void)
{
    ShaderBlock *block = (ShaderBlock *)SDL_calloc(1, sizeof(ShaderBlock));
    if (block == NULL)
    {
        return NULL;
    }
    /* SDL's own default entry point, so a script that does not care about
       naming need not say anything. */
    block->entrypoint = SDL_strdup("main");
    block->info.entrypoint = block->entrypoint;
    return &block->info;
}

void SDLStatic_GPUShaderCreateInfoDestroy(SDL_GPUShaderCreateInfo *info)
{
    if (info == NULL)
    {
        return;
    }
    ShaderBlock *block = (ShaderBlock *)info;
    SDL_free(block->code);
    SDL_free(block->entrypoint);
    SDL_free(block);
}

void SDLStatic_GPUShaderCreateInfoSetCode(SDL_GPUShaderCreateInfo *info, const void *code,
                                          int size)
{
    if (info == NULL || code == NULL || size <= 0)
    {
        return;
    }
    ShaderBlock *block = (ShaderBlock *)info;
    void *copy = SDL_malloc((size_t)size);
    if (copy == NULL)
    {
        return;
    }
    SDL_memcpy(copy, code, (size_t)size);
    SDL_free(block->code);
    block->code = copy;
    block->info.code = (const Uint8 *)copy;
    block->info.code_size = (size_t)size;
}

void SDLStatic_GPUShaderCreateInfoSetEntrypoint(SDL_GPUShaderCreateInfo *info,
                                                const char *entrypoint)
{
    if (info == NULL)
    {
        return;
    }
    ShaderBlock *block = (ShaderBlock *)info;
    SDL_free(block->entrypoint);
    block->entrypoint = (entrypoint != NULL) ? SDL_strdup(entrypoint) : NULL;
    block->info.entrypoint = block->entrypoint;
}

void SDLStatic_GPUShaderCreateInfoSetFormat(SDL_GPUShaderCreateInfo *info,
                                            SDL_GPUShaderFormat format, SDL_GPUShaderStage stage)
{
    if (info != NULL)
    {
        info->format = format;
        info->stage = stage;
    }
}

void SDLStatic_GPUShaderCreateInfoSetCounts(SDL_GPUShaderCreateInfo *info, Uint32 samplers,
                                            Uint32 storage_textures, Uint32 storage_buffers,
                                            Uint32 uniform_buffers)
{
    if (info != NULL)
    {
        info->num_samplers = samplers;
        info->num_storage_textures = storage_textures;
        info->num_storage_buffers = storage_buffers;
        info->num_uniform_buffers = uniform_buffers;
    }
}

/* --- graphics pipelines ----------------------------------------------------- */

/* The descriptor points at three arrays. The builder owns them and grows
   them as a script appends, which is the whole reason these are appends and
   not setters: a script cannot allocate a C array. */
typedef struct PipelineBlock
{
    SDL_GPUGraphicsPipelineCreateInfo info;

    SDL_GPUVertexBufferDescription *buffers;
    Uint32 buffer_count, buffer_capacity;
    SDL_GPUVertexAttribute *attributes;
    Uint32 attribute_count, attribute_capacity;
    SDL_GPUColorTargetDescription *targets;
    Uint32 target_count, target_capacity;
} PipelineBlock;

SDL_GPUGraphicsPipelineCreateInfo *SDLStatic_GPUPipelineInfoCreate(void)
{
    PipelineBlock *block = (PipelineBlock *)SDL_calloc(1, sizeof(PipelineBlock));
    return (block != NULL) ? &block->info : NULL;
}

void SDLStatic_GPUPipelineInfoDestroy(SDL_GPUGraphicsPipelineCreateInfo *info)
{
    if (info == NULL)
    {
        return;
    }
    PipelineBlock *block = (PipelineBlock *)info;
    SDL_free(block->buffers);
    SDL_free(block->attributes);
    SDL_free(block->targets);
    SDL_free(block);
}

/* Grow one of the arrays. Re-pointing the descriptor after every growth
   matters: a realloc may move the storage, and the struct holds a raw
   pointer that would otherwise dangle. */
static bool Grow(void **array, Uint32 *capacity, Uint32 needed, size_t element)
{
    if (*capacity >= needed)
    {
        return true;
    }
    Uint32 next = (*capacity > 0) ? *capacity * 2 : 4;
    while (next < needed)
    {
        next *= 2;
    }
    void *grown = SDL_realloc(*array, (size_t)next * element);
    if (grown == NULL)
    {
        return false;
    }
    *array = grown;
    *capacity = next;
    return true;
}

void SDLStatic_GPUPipelineInfoSetShaders(SDL_GPUGraphicsPipelineCreateInfo *info,
                                         SDL_GPUShader *vertex, SDL_GPUShader *fragment)
{
    if (info != NULL)
    {
        info->vertex_shader = vertex;
        info->fragment_shader = fragment;
    }
}

void SDLStatic_GPUPipelineInfoSetPrimitive(SDL_GPUGraphicsPipelineCreateInfo *info,
                                           SDL_GPUPrimitiveType primitive)
{
    if (info != NULL)
    {
        info->primitive_type = primitive;
    }
}

void SDLStatic_GPUPipelineInfoSetFillMode(SDL_GPUGraphicsPipelineCreateInfo *info,
                                          SDL_GPUFillMode fill, SDL_GPUCullMode cull)
{
    if (info != NULL)
    {
        info->rasterizer_state.fill_mode = fill;
        info->rasterizer_state.cull_mode = cull;
    }
}

bool SDLStatic_GPUPipelineInfoAddVertexBuffer(SDL_GPUGraphicsPipelineCreateInfo *info,
                                              Uint32 slot, Uint32 pitch,
                                              SDL_GPUVertexInputRate input_rate)
{
    if (info == NULL)
    {
        return false;
    }
    PipelineBlock *block = (PipelineBlock *)info;
    if (!Grow((void **)&block->buffers, &block->buffer_capacity, block->buffer_count + 1,
              sizeof(SDL_GPUVertexBufferDescription)))
    {
        return false;
    }
    SDL_GPUVertexBufferDescription *description = &block->buffers[block->buffer_count++];
    SDL_zerop(description);
    description->slot = slot;
    description->pitch = pitch;
    description->input_rate = input_rate;

    info->vertex_input_state.vertex_buffer_descriptions = block->buffers;
    info->vertex_input_state.num_vertex_buffers = block->buffer_count;
    return true;
}

bool SDLStatic_GPUPipelineInfoAddVertexAttribute(SDL_GPUGraphicsPipelineCreateInfo *info,
                                                 Uint32 location, Uint32 buffer_slot,
                                                 SDL_GPUVertexElementFormat format,
                                                 Uint32 offset)
{
    if (info == NULL)
    {
        return false;
    }
    PipelineBlock *block = (PipelineBlock *)info;
    if (!Grow((void **)&block->attributes, &block->attribute_capacity,
              block->attribute_count + 1, sizeof(SDL_GPUVertexAttribute)))
    {
        return false;
    }
    SDL_GPUVertexAttribute *attribute = &block->attributes[block->attribute_count++];
    SDL_zerop(attribute);
    attribute->location = location;
    attribute->buffer_slot = buffer_slot;
    attribute->format = format;
    attribute->offset = offset;

    info->vertex_input_state.vertex_attributes = block->attributes;
    info->vertex_input_state.num_vertex_attributes = block->attribute_count;
    return true;
}

bool SDLStatic_GPUPipelineInfoAddColorTarget(SDL_GPUGraphicsPipelineCreateInfo *info,
                                             SDL_GPUTextureFormat format)
{
    if (info == NULL)
    {
        return false;
    }
    PipelineBlock *block = (PipelineBlock *)info;
    if (!Grow((void **)&block->targets, &block->target_capacity, block->target_count + 1,
              sizeof(SDL_GPUColorTargetDescription)))
    {
        return false;
    }
    SDL_GPUColorTargetDescription *target = &block->targets[block->target_count++];
    SDL_zerop(target);
    target->format = format;

    info->target_info.color_target_descriptions = block->targets;
    info->target_info.num_color_targets = block->target_count;
    return true;
}

void SDLStatic_GPUPipelineInfoSetDepthStencil(SDL_GPUGraphicsPipelineCreateInfo *info,
                                              SDL_GPUTextureFormat format, bool enabled)
{
    if (info != NULL)
    {
        info->target_info.depth_stencil_format = format;
        info->target_info.has_depth_stencil_target = enabled;
    }
}

/* --- compute pipelines ------------------------------------------------------ */

typedef struct ComputeBlock
{
    SDL_GPUComputePipelineCreateInfo info;
    void *code;
    char *entrypoint;
} ComputeBlock;

SDL_GPUComputePipelineCreateInfo *SDLStatic_GPUComputePipelineInfoCreate(void)
{
    ComputeBlock *block = (ComputeBlock *)SDL_calloc(1, sizeof(ComputeBlock));
    if (block == NULL)
    {
        return NULL;
    }
    block->entrypoint = SDL_strdup("main");
    block->info.entrypoint = block->entrypoint;
    return &block->info;
}

void SDLStatic_GPUComputePipelineInfoDestroy(SDL_GPUComputePipelineCreateInfo *info)
{
    if (info == NULL)
    {
        return;
    }
    ComputeBlock *block = (ComputeBlock *)info;
    SDL_free(block->code);
    SDL_free(block->entrypoint);
    SDL_free(block);
}

void SDLStatic_GPUComputePipelineInfoSetCode(SDL_GPUComputePipelineCreateInfo *info,
                                             const void *code, int size)
{
    if (info == NULL || code == NULL || size <= 0)
    {
        return;
    }
    ComputeBlock *block = (ComputeBlock *)info;
    void *copy = SDL_malloc((size_t)size);
    if (copy == NULL)
    {
        return;
    }
    SDL_memcpy(copy, code, (size_t)size);
    SDL_free(block->code);
    block->code = copy;
    block->info.code = (const Uint8 *)copy;
    block->info.code_size = (size_t)size;
}

void SDLStatic_GPUComputePipelineInfoSetEntrypoint(SDL_GPUComputePipelineCreateInfo *info,
                                                   const char *entrypoint)
{
    if (info == NULL)
    {
        return;
    }
    ComputeBlock *block = (ComputeBlock *)info;
    SDL_free(block->entrypoint);
    block->entrypoint = (entrypoint != NULL) ? SDL_strdup(entrypoint) : NULL;
    block->info.entrypoint = block->entrypoint;
}

void SDLStatic_GPUComputePipelineInfoSetFormat(SDL_GPUComputePipelineCreateInfo *info,
                                               SDL_GPUShaderFormat format)
{
    if (info != NULL)
    {
        info->format = format;
    }
}

void SDLStatic_GPUComputePipelineInfoSetThreadCount(SDL_GPUComputePipelineCreateInfo *info,
                                                    Uint32 x, Uint32 y, Uint32 z)
{
    if (info != NULL)
    {
        info->threadcount_x = x;
        info->threadcount_y = y;
        info->threadcount_z = z;
    }
}

/* --- bindings --------------------------------------------------------------- */

void SDLStatic_GPUBufferBindingSet(SDL_GPUBufferBinding *binding, SDL_GPUBuffer *buffer,
                                   Uint32 offset)
{
    if (binding != NULL)
    {
        binding->buffer = buffer;
        binding->offset = offset;
    }
}

void SDLStatic_GPUTextureSamplerBindingSet(SDL_GPUTextureSamplerBinding *binding,
                                           SDL_GPUTexture *texture, SDL_GPUSampler *sampler)
{
    if (binding != NULL)
    {
        binding->texture = texture;
        binding->sampler = sampler;
    }
}

/* --- copy pass -------------------------------------------------------------- */

void SDLStatic_GPUTransferBufferLocationSet(SDL_GPUTransferBufferLocation *location,
                                            SDL_GPUTransferBuffer *buffer, Uint32 offset)
{
    if (location != NULL)
    {
        location->transfer_buffer = buffer;
        location->offset = offset;
    }
}

void SDLStatic_GPUBufferRegionSet(SDL_GPUBufferRegion *region, SDL_GPUBuffer *buffer,
                                  Uint32 offset, Uint32 size)
{
    if (region != NULL)
    {
        region->buffer = buffer;
        region->offset = offset;
        region->size = size;
    }
}

void SDLStatic_GPUBufferLocationSet(SDL_GPUBufferLocation *location, SDL_GPUBuffer *buffer,
                                    Uint32 offset)
{
    if (location != NULL)
    {
        location->buffer = buffer;
        location->offset = offset;
    }
}

void SDLStatic_GPUTextureTransferInfoSet(SDL_GPUTextureTransferInfo *info,
                                         SDL_GPUTransferBuffer *buffer, Uint32 offset,
                                         Uint32 pixels_per_row, Uint32 rows_per_layer)
{
    if (info != NULL)
    {
        info->transfer_buffer = buffer;
        info->offset = offset;
        info->pixels_per_row = pixels_per_row;
        info->rows_per_layer = rows_per_layer;
    }
}

void SDLStatic_GPUTextureRegionSet(SDL_GPUTextureRegion *region, SDL_GPUTexture *texture,
                                   Uint32 x, Uint32 y, Uint32 w, Uint32 h)
{
    if (region != NULL)
    {
        region->texture = texture;
        region->x = x;
        region->y = y;
        region->w = w;
        region->h = h;
        /* A 2D region still needs a depth of one, or the copy moves nothing
           and reports success. */
        region->d = 1;
    }
}

void SDLStatic_GPUTextureLocationSet(SDL_GPUTextureLocation *location, SDL_GPUTexture *texture,
                                     Uint32 x, Uint32 y, Uint32 z)
{
    if (location != NULL)
    {
        location->texture = texture;
        location->x = x;
        location->y = y;
        location->z = z;
    }
}

void SDLStatic_GPUBlitInfoSetSource(SDL_GPUBlitInfo *info, SDL_GPUTexture *texture, Uint32 x,
                                    Uint32 y, Uint32 w, Uint32 h)
{
    if (info != NULL)
    {
        info->source.texture = texture;
        info->source.x = x;
        info->source.y = y;
        info->source.w = w;
        info->source.h = h;
    }
}

void SDLStatic_GPUBlitInfoSetDestination(SDL_GPUBlitInfo *info, SDL_GPUTexture *texture, Uint32 x,
                                         Uint32 y, Uint32 w, Uint32 h)
{
    if (info != NULL)
    {
        info->destination.texture = texture;
        info->destination.x = x;
        info->destination.y = y;
        info->destination.w = w;
        info->destination.h = h;
    }
}

void SDLStatic_GPUBlitInfoSetFilter(SDL_GPUBlitInfo *info, SDL_GPUFilter filter)
{
    if (info != NULL)
    {
        info->filter = filter;
    }
}

/* --- the swapchain ---------------------------------------------------------- */

/* SDL returns the texture through an SDL_GPUTexture**, which the generator
   cannot bind — so the call every GPU frame begins with was unreachable.
   The size comes back through two more out-parameters; a script reads them
   afterwards rather than juggling three returns. */
static Uint32 g_swapchain_width;
static Uint32 g_swapchain_height;

SDL_GPUTexture *SDLStatic_GPUAcquireSwapchain(SDL_GPUCommandBuffer *command_buffer,
                                              SDL_Window *window)
{
    SDL_GPUTexture *texture = NULL;
    g_swapchain_width = 0;
    g_swapchain_height = 0;
    if (command_buffer == NULL || window == NULL)
    {
        SDL_InvalidParamError("command_buffer/window");
        return NULL;
    }
    if (!SDL_AcquireGPUSwapchainTexture(command_buffer, window, &texture, &g_swapchain_width,
                                        &g_swapchain_height))
    {
        return NULL;
    }
    /* A NULL texture with a true return is normal: the swapchain is not
       ready this frame, and the caller should skip rather than stop. */
    return texture;
}

Uint32 SDLStatic_GPUSwapchainWidth(void)
{
    return g_swapchain_width;
}

Uint32 SDLStatic_GPUSwapchainHeight(void)
{
    return g_swapchain_height;
}

SDL_GPUTexture *SDLStatic_GPUWaitAndAcquireSwapchain(SDL_GPUCommandBuffer *command_buffer,
                                                     SDL_Window *window)
{
    SDL_GPUTexture *texture = NULL;
    g_swapchain_width = 0;
    g_swapchain_height = 0;
    if (command_buffer == NULL || window == NULL)
    {
        SDL_InvalidParamError("command_buffer/window");
        return NULL;
    }
    if (!SDL_WaitAndAcquireGPUSwapchainTexture(command_buffer, window, &texture,
                                               &g_swapchain_width, &g_swapchain_height))
    {
        return NULL;
    }
    return texture;
}

/* --- getting data onto the device ------------------------------------------ */

/* SDL's route is map, write, unmap; the map returns a void*, which the
   generator cannot bind, so a script had no way to get a single vertex onto
   the device. Doing all three together is what the C call sites do anyway. */
bool SDLStatic_GPUUploadToTransferBuffer(SDL_GPUDevice *device, SDL_GPUTransferBuffer *buffer,
                                         Uint32 offset, const void *data, int size, bool cycle)
{
    if (device == NULL || buffer == NULL || data == NULL || size <= 0)
    {
        SDL_InvalidParamError("device/buffer/data");
        return false;
    }
    Uint8 *mapped = (Uint8 *)SDL_MapGPUTransferBuffer(device, buffer, cycle);
    if (mapped == NULL)
    {
        return false;
    }
    SDL_memcpy(mapped + offset, data, (size_t)size);
    SDL_UnmapGPUTransferBuffer(device, buffer);
    return true;
}

void *SDLStatic_GPUReadTransferBuffer(SDL_GPUDevice *device, SDL_GPUTransferBuffer *buffer,
                                      Uint32 offset, int size)
{
    if (device == NULL || buffer == NULL || size <= 0)
    {
        SDL_InvalidParamError("device/buffer/size");
        return NULL;
    }
    void *copy = SDL_malloc((size_t)size);
    if (copy == NULL)
    {
        return NULL;
    }
    /* Never cycle on a read: cycling hands back fresh storage, which is
       exactly the data the caller is trying to look at, discarded. */
    const Uint8 *mapped = (const Uint8 *)SDL_MapGPUTransferBuffer(device, buffer, false);
    if (mapped == NULL)
    {
        SDL_free(copy);
        return NULL;
    }
    SDL_memcpy(copy, mapped + offset, (size_t)size);
    SDL_UnmapGPUTransferBuffer(device, buffer);
    return copy;
}

/* --- storage bindings ------------------------------------------------------- */

/* SDL takes an array of pointers, which a script cannot build. One slot at a
   time covers nearly every call site, and a shader wanting several calls
   these once per slot. */
#define DEFINE_STORAGE_BIND(name, PassType, HandleType, sdl_call)                                \
    void SDLStatic_##name(PassType *pass, Uint32 slot, HandleType *handle)                       \
    {                                                                                            \
        if (pass != NULL && handle != NULL)                                                      \
        {                                                                                        \
            sdl_call(pass, slot, &handle, 1);                                                    \
        }                                                                                        \
    }

DEFINE_STORAGE_BIND(GPUBindVertexStorageBuffer, SDL_GPURenderPass, SDL_GPUBuffer,
                    SDL_BindGPUVertexStorageBuffers)
DEFINE_STORAGE_BIND(GPUBindVertexStorageTexture, SDL_GPURenderPass, SDL_GPUTexture,
                    SDL_BindGPUVertexStorageTextures)
DEFINE_STORAGE_BIND(GPUBindFragmentStorageBuffer, SDL_GPURenderPass, SDL_GPUBuffer,
                    SDL_BindGPUFragmentStorageBuffers)
DEFINE_STORAGE_BIND(GPUBindFragmentStorageTexture, SDL_GPURenderPass, SDL_GPUTexture,
                    SDL_BindGPUFragmentStorageTextures)
DEFINE_STORAGE_BIND(GPUBindComputeStorageBuffer, SDL_GPUComputePass, SDL_GPUBuffer,
                    SDL_BindGPUComputeStorageBuffers)
DEFINE_STORAGE_BIND(GPUBindComputeStorageTexture, SDL_GPUComputePass, SDL_GPUTexture,
                    SDL_BindGPUComputeStorageTextures)

/* --- compute passes --------------------------------------------------------- */

struct SDLStatic_GPUComputeBindings
{
    SDL_GPUStorageBufferReadWriteBinding *buffers;
    Uint32 buffer_count, buffer_capacity;
    SDL_GPUStorageTextureReadWriteBinding *textures;
    Uint32 texture_count, texture_capacity;
};

SDLStatic_GPUComputeBindings *SDLStatic_GPUComputeBindingsCreate(void)
{
    return (SDLStatic_GPUComputeBindings *)SDL_calloc(
        1, sizeof(SDLStatic_GPUComputeBindings));
}

void SDLStatic_GPUComputeBindingsDestroy(SDLStatic_GPUComputeBindings *bindings)
{
    if (bindings == NULL)
    {
        return;
    }
    SDL_free(bindings->buffers);
    SDL_free(bindings->textures);
    SDL_free(bindings);
}

bool SDLStatic_GPUComputeBindingsAddBuffer(SDLStatic_GPUComputeBindings *bindings,
                                           SDL_GPUBuffer *buffer, bool cycle)
{
    if (bindings == NULL || buffer == NULL)
    {
        return false;
    }
    if (!Grow((void **)&bindings->buffers, &bindings->buffer_capacity,
              bindings->buffer_count + 1, sizeof(SDL_GPUStorageBufferReadWriteBinding)))
    {
        return false;
    }
    SDL_GPUStorageBufferReadWriteBinding *binding = &bindings->buffers[bindings->buffer_count++];
    SDL_zerop(binding);
    binding->buffer = buffer;
    binding->cycle = cycle;
    return true;
}

bool SDLStatic_GPUComputeBindingsAddTexture(SDLStatic_GPUComputeBindings *bindings,
                                            SDL_GPUTexture *texture, Uint32 mip_level,
                                            Uint32 layer, bool cycle)
{
    if (bindings == NULL || texture == NULL)
    {
        return false;
    }
    if (!Grow((void **)&bindings->textures, &bindings->texture_capacity,
              bindings->texture_count + 1, sizeof(SDL_GPUStorageTextureReadWriteBinding)))
    {
        return false;
    }
    SDL_GPUStorageTextureReadWriteBinding *binding =
        &bindings->textures[bindings->texture_count++];
    SDL_zerop(binding);
    binding->texture = texture;
    binding->mip_level = mip_level;
    binding->layer = layer;
    binding->cycle = cycle;
    return true;
}

SDL_GPUComputePass *SDLStatic_GPUBeginComputePass(SDL_GPUCommandBuffer *command_buffer,
                                                  SDLStatic_GPUComputeBindings *bindings)
{
    if (command_buffer == NULL)
    {
        SDL_InvalidParamError("command_buffer");
        return NULL;
    }
    if (bindings == NULL)
    {
        return SDL_BeginGPUComputePass(command_buffer, NULL, 0, NULL, 0);
    }
    return SDL_BeginGPUComputePass(command_buffer, bindings->textures, bindings->texture_count,
                                   bindings->buffers, bindings->buffer_count);
}

/* --- fences ----------------------------------------------------------------- */

bool SDLStatic_GPUWaitForFence(SDL_GPUDevice *device, SDL_GPUFence *fence)
{
    if (device == NULL || fence == NULL)
    {
        SDL_InvalidParamError("device/fence");
        return false;
    }
    return SDL_WaitForGPUFences(device, true, &fence, 1);
}

/* --- render states ---------------------------------------------------------- */

/* Like the pipeline descriptor, this points at arrays the builder owns —
   here, the extra samplers a custom fragment shader reads from. */
typedef struct RenderStateBlock
{
    SDL_GPURenderStateCreateInfo info;
    SDL_GPUTextureSamplerBinding *samplers;
    Uint32 sampler_count, sampler_capacity;
} RenderStateBlock;

SDL_GPURenderStateCreateInfo *SDLStatic_GPURenderStateInfoCreate(void)
{
    RenderStateBlock *block = (RenderStateBlock *)SDL_calloc(1, sizeof(RenderStateBlock));
    return (block != NULL) ? &block->info : NULL;
}

void SDLStatic_GPURenderStateInfoDestroy(SDL_GPURenderStateCreateInfo *info)
{
    if (info == NULL)
    {
        return;
    }
    RenderStateBlock *block = (RenderStateBlock *)info;
    SDL_free(block->samplers);
    SDL_free(block);
}

bool SDLStatic_GPURenderStateInfoAddSampler(SDL_GPURenderStateCreateInfo *info,
                                            SDL_GPUTexture *texture, SDL_GPUSampler *sampler)
{
    if (info == NULL || texture == NULL || sampler == NULL)
    {
        return false;
    }
    RenderStateBlock *block = (RenderStateBlock *)info;
    if (!Grow((void **)&block->samplers, &block->sampler_capacity, block->sampler_count + 1,
              sizeof(SDL_GPUTextureSamplerBinding)))
    {
        return false;
    }
    SDL_GPUTextureSamplerBinding *binding = &block->samplers[block->sampler_count++];
    SDL_zerop(binding);
    binding->texture = texture;
    binding->sampler = sampler;

    info->sampler_bindings = block->samplers;
    info->num_sampler_bindings = (Sint32)block->sampler_count;
    return true;
}

void SDLStatic_GPURenderStateInfoSetShader(SDL_GPURenderStateCreateInfo *info,
                                           SDL_GPUShader *fragment_shader)
{
    if (info != NULL)
    {
        info->fragment_shader = fragment_shader;
    }
}
