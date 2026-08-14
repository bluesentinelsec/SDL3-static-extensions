/*
 * sdlstatic_bidi.c — Unicode BiDi itemization over vendored SheenBidi.
 * Original SDLStatic code (zlib). See SDLStatic/bidi.h.
 */
#include <SDLStatic/bidi.h>

#include <SheenBidi/SheenBidi.h>

static bool GetParagraph(const char *utf8, int length, SBAlgorithmRef *out_algo,
                         SBParagraphRef *out_par)
{
    SBCodepointSequence seq;
    if (utf8 == NULL)
    {
        SDL_InvalidParamError("utf8");
        return false;
    }
    if (length < 0)
    {
        length = (int)SDL_strlen(utf8);
    }
    seq.stringEncoding = SBStringEncodingUTF8;
    seq.stringBuffer = (void *)utf8;
    seq.stringLength = (SBUInteger)length;
    *out_algo = SBAlgorithmCreate(&seq);
    if (*out_algo == NULL)
    {
        SDL_SetError("SheenBidi: algorithm creation failed");
        return false;
    }
    /* First paragraph only; base level from the first strong character. */
    *out_par = SBAlgorithmCreateParagraph(*out_algo, 0, (SBUInteger)length,
                                          SBLevelDefaultLTR);
    if (*out_par == NULL)
    {
        SBAlgorithmRelease(*out_algo);
        SDL_SetError("SheenBidi: paragraph creation failed");
        return false;
    }
    return true;
}

SDLStatic_BidiRun *SDLStatic_BidiItemize(const char *utf8, int length, int *count)
{
    SBAlgorithmRef algo = NULL;
    SBParagraphRef par = NULL;
    SBLineRef line = NULL;
    SDLStatic_BidiRun *out = NULL;

    if (count == NULL)
    {
        SDL_InvalidParamError("count");
        return NULL;
    }
    *count = 0;
    if (!GetParagraph(utf8, length, &algo, &par))
    {
        return NULL;
    }
    line = SBParagraphCreateLine(par, 0, SBParagraphGetLength(par));
    if (line == NULL)
    {
        SDL_SetError("SheenBidi: line creation failed");
        goto done;
    }
    {
        SBUInteger n = SBLineGetRunCount(line);
        const SBRun *runs = SBLineGetRunsPtr(line);
        SBUInteger i;
        out = (SDLStatic_BidiRun *)SDL_calloc(n > 0 ? n : 1, sizeof(*out));
        if (out == NULL)
        {
            goto done;
        }
        for (i = 0; i < n; i++)
        {
            out[i].offset = (int)runs[i].offset;
            out[i].length = (int)runs[i].length;
            out[i].direction = (runs[i].level & 1) ? TTF_DIRECTION_RTL
                                                   : TTF_DIRECTION_LTR;
        }
        *count = (int)n;
    }
done:
    if (line != NULL)
    {
        SBLineRelease(line);
    }
    SBParagraphRelease(par);
    SBAlgorithmRelease(algo);
    return out;
}

bool SDLStatic_BidiBaseIsRTL(const char *utf8, int length)
{
    SBAlgorithmRef algo = NULL;
    SBParagraphRef par = NULL;
    bool rtl = false;
    if (!GetParagraph(utf8, length, &algo, &par))
    {
        return false;
    }
    rtl = (SBParagraphGetBaseLevel(par) & 1) != 0;
    SBParagraphRelease(par);
    SBAlgorithmRelease(algo);
    return rtl;
}
