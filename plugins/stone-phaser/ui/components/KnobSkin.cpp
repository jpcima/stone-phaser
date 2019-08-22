#include "KnobSkin.hpp"
#include <cassert>

KnobSkin::KnobSkin(cairo_surface_t *surface, unsigned imageCount)
{
    assert(imageCount > 0);

    if (!surface)
        throw std::runtime_error("cannot load skin image");
    fSurface.reset(cairo_surface_reference(surface));

    cairo_surface_u *subSurface = new cairo_surface_u[imageCount];
    fSubSurface.reset(subSurface);
    fImageCount = imageCount;

    cairo_format_t fmt = cairo_image_surface_get_format(surface);
    unsigned char *d = cairo_image_surface_get_data(surface);

    unsigned wf = cairo_image_surface_get_width(surface);
    unsigned hf = cairo_image_surface_get_height(surface);
    unsigned s = cairo_image_surface_get_stride(surface);

    unsigned w, h;
    bool vertical = hf > wf;
    if (vertical) {
        w = wf;
        h = hf / imageCount;
    }
    else {
        if (fmt != CAIRO_FORMAT_ARGB32)
            throw std::runtime_error("unsupported skin image format");
        h = hf;
        w = wf / imageCount;
    }

    for (unsigned i = 0; i < imageCount; ++i) {
        cairo_surface_t *sub;
        if (vertical)
            sub = cairo_image_surface_create_for_data(d + i * (h * s), fmt, w, h, s);
        else
            sub = cairo_image_surface_create_for_data(d + i * (4 * w), fmt, w, h, s);
        if (!surface)
            throw std::runtime_error("cannot extract skin image region");
        subSurface[i].reset(sub);
    }
}

KnobSkin::KnobSkin(const char *pngData, unsigned pngSize, unsigned imageCount)
    : KnobSkin(cairo_surface_u{cairo_image_surface_create_from_png_data(pngData, pngSize)}.get(), imageCount)
{
}

cairo_surface_t *KnobSkin::getImageForRatio(double ratio) const
{
    unsigned imageCount = fImageCount;
    int index = (int)(0.5 + ratio * (imageCount - 1));
    index = (index < 0) ? 0 : index;
    index = ((unsigned)index < imageCount) ? index : (imageCount - 1);
    return fSubSurface[index].get();
}

unsigned KnobSkin::getWidth() const
{
    return cairo_image_surface_get_width(fSubSurface[0].get());
}

unsigned KnobSkin::getHeight() const
{
    return cairo_image_surface_get_height(fSubSurface[0].get());
}
