#include "Cairo++.h"
#include <cstring>

cairo_surface_t *cairo_image_surface_create_from_png_data(const char *data, unsigned length)
{
    struct PngReaderData
    {
        const char *dataPtr;
        unsigned sizeLeft;
    };

    auto readSomePngData = [](void *closure,
                              unsigned char *data,
                              unsigned int length) noexcept -> cairo_status_t
    {
        PngReaderData &readerData = *reinterpret_cast<PngReaderData *>(closure);
        if (readerData.sizeLeft < length)
            return CAIRO_STATUS_READ_ERROR;

        memcpy(data, readerData.dataPtr, length);
        readerData.dataPtr += length;
        readerData.sizeLeft -= length;
        return CAIRO_STATUS_SUCCESS;
    };

    PngReaderData readerData;
    readerData.dataPtr = data;
    readerData.sizeLeft = length;
    return cairo_image_surface_create_from_png_stream(+readSomePngData, &readerData);
}

cairo_surface_t *cairo_image_surface_resize_to_height(cairo_surface_t *src, cairo_format_t format, unsigned height)
{
    unsigned srcw = cairo_image_surface_get_width(src);
    unsigned srch = cairo_image_surface_get_height(src);
    double ratio = (double)height / srch;
    unsigned dstw = (unsigned)std::ceil(srcw * ratio);
    cairo_surface_u dst(cairo_surface_create_similar_image(src, format, dstw, height));
    cairo_u cr(cairo_create(dst.get()));
    cairo_scale(cr.get(), ratio, ratio);
    cairo_set_source_surface(cr.get(), src, 0.0, 0.0);
    cairo_paint(cr.get());
    return dst.release();
}

void cairo_set_source_rgba8(cairo_t *cr, ColorRGBA8 c)
{
    double k = 1.0 / 0xff;
    cairo_set_source_rgba(cr, c.r * k, c.g * k, c.b * k, c.a * k);
}
