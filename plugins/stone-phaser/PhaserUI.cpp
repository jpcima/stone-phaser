#include "PhaserUI.hpp"
#include "PhaserShared.hpp"
#include "Artwork.hpp"
#include "Window.hpp"
#include "ui/components/KnobSkin.hpp"
#include "ui/components/SkinSlider.hpp"
#include "ui/components/SkinToggleButton.hpp"
#include "ui/components/SkinIndicator.hpp"
#include "ui/FontEngine.h"
#include "ui/Cairo++.h"
#include "Cairo.hpp"
#include <mutex>
#include <cmath>

#ifndef DISTRHO_UI_PATCH_INVERTED_BYPASS
    #pragma message("Please patch DPF with `resources/patch/DPF-bypass.patch`")
    #pragma message("The patch works around the value inversion issue (DISTRHO/DPF#150).")
#endif

static cairo_surface_u sImgBackground;
static cairo_surface_u sImgSmallKnob;
static cairo_surface_u sImgLargeKnob;
static cairo_surface_u sImgSwitch;
static cairo_surface_u sImgFootswitch;
static cairo_surface_u sImgLed;

static std::unique_ptr<KnobSkin> sSkinSmallKnob;
static std::unique_ptr<KnobSkin> sSkinLargeKnob;
static std::unique_ptr<KnobSkin> sSkinSwitch;
static std::unique_ptr<KnobSkin> sSkinFootswitch;
static std::unique_ptr<KnobSkin> sSkinLed;

//------------------------------------------------------------------------------
PhaserUI::PhaserUI()
    : UI(cairo_image_surface_get_width(sImgBackground.get()),
         cairo_image_surface_get_height(sImgBackground.get())),
      fParameters(new DISTRHO::Parameter[StonePhaserDsp::NumParameters]),
      fSliderForParameter(new SkinSlider *[StonePhaserDsp::NumParameters]()),
      fToggleButtonForParameter(new SkinToggleButton *[StonePhaserDsp::NumParameters]()),
      fIndicatorForParameter(new SkinIndicator *[StonePhaserDsp::NumParameters]()),
      fFontEngine(new FontEngine)
{
    #define RES_T(x, T) (T *)Artwork::x##Data, Artwork::x##DataSize
    fFontEngine->addFont("Cooper Hewitt", RES_T(CooperHewitt_Medium, const uint8_t));
    #undef RES_T

    for (uint32_t index = 0; index < StonePhaserDsp::NumParameters; ++index)
        InitParameter(index, fParameters[index]);

    int wFull = getWidth();
    // int hFull = getHeight();

    int wSmallKnob = sSkinSmallKnob->getWidth();
    int wLargeKnob = sSkinLargeKnob->getWidth();
    int wFootswitch = sSkinFootswitch->getWidth();

#if DISTRHO_PLUGIN_NUM_INPUTS == 1
    int numKnobs = 3;
    int wSpacing = 24;
#elif DISTRHO_PLUGIN_NUM_INPUTS == 2
    int numKnobs = 4;
    int wSpacing = 8;
#endif

    int xOffset = (wFull - (wSmallKnob * numKnobs + wSpacing * (numKnobs - 1))) / 2;

    int x = xOffset;
    int y = 14;

#if DISTRHO_PLUGIN_NUM_INPUTS == 1
    createKnobForParameter(StonePhaserDsp::p_feedback_depth, {x, y, 0, 0}, *sSkinSmallKnob);
    x += wSmallKnob + wSpacing;
    createKnobForParameter(StonePhaserDsp::p_feedback_hpf_cutoff, {x, y, 0, 0}, *sSkinSmallKnob);
    x += wSmallKnob + wSpacing;
    createKnobForParameter(StonePhaserDsp::p_mix, {x, y, 0, 0}, *sSkinSmallKnob);
#elif DISTRHO_PLUGIN_NUM_INPUTS == 2
    createKnobForParameter(StonePhaserDsp::p_feedback_depth, {x, y, 0, 0}, *sSkinSmallKnob);
    x += wSmallKnob + wSpacing;
    createKnobForParameter(StonePhaserDsp::p_feedback_hpf_cutoff, {x, y, 0, 0}, *sSkinSmallKnob);
    x += wSmallKnob + wSpacing;
    createKnobForParameter(StonePhaserDsp::p_mix, {x, y, 0, 0}, *sSkinSmallKnob);
    x += wSmallKnob + wSpacing;
    createKnobForParameter(StonePhaserDsp::p_stereo_phase, {x, y, 0, 0}, *sSkinSmallKnob);
#endif

    createKnobForParameter(StonePhaserDsp::p_lfo_frequency, {(wFull - wLargeKnob) / 2, 140, 0, 0}, *sSkinLargeKnob);

    createToggleButtonForParameter(StonePhaserDsp::p_color, {48, 160, 0, 0}, *sSkinSwitch);

    createToggleButtonForParameter(StonePhaserDsp::p_bypass, {(wFull - wFootswitch) / 2, 294, 0, 0}, *sSkinFootswitch, true);

    createIndicatorForParameter(StonePhaserDsp::p_bypass, {290, 190, 0, 0}, *sSkinLed, true);
}

PhaserUI::~PhaserUI()
{
}

void PhaserUI::onDisplay()
{
    cairo_t *cr = getParentWindow().getGraphicsContext().cairo;

    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
    cairo_paint(cr);

    cairo_set_source_surface(cr, sImgBackground.get(), 0, 0);
    cairo_paint(cr);

    Rect brandLabelBounds {50, 280, 75, 50};
    cairo_rounded_rectangle(cr, brandLabelBounds, 10.0);
    cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
    cairo_set_line_width(cr, 4.0);
    cairo_stroke(cr);

    struct TextItem {
        const char *text;
        Font *font;
        Rect bounds;
        int align;
    };

    auto widgetBounds =
        [](Widget *w) -> Rect {
            DISTRHO_SAFE_ASSERT_RETURN(w, Rect());
            return Rect(w->getAbsoluteX(), w->getAbsoluteY(), w->getWidth(), w->getHeight());
        };

    Font font {"Cooper Hewitt", 11.0, ColorRGBA8{0xff, 0xff, 0xff, 0xff}};
    Font fontBrand {"Cooper Hewitt", 32.0, ColorRGBA8{0xff, 0xff, 0xff, 0xff}};

    TextItem textItems[] = {
        {"COLOR",
         &font,
         widgetBounds(fToggleButtonForParameter[StonePhaserDsp::p_color]).off_by({0, 4}),
         FontEngine::AlignCenter|FontEngine::AlignBottom},
        {"FEEDBACK",
         &font,
         widgetBounds(fSliderForParameter[StonePhaserDsp::p_feedback_depth]).off_by({0, 4}),
         FontEngine::AlignCenter|FontEngine::AlignBottom},
        {"FB BASS CUT",
         &font,
         widgetBounds(fSliderForParameter[StonePhaserDsp::p_feedback_hpf_cutoff]).off_by({0, 4}),
         FontEngine::AlignCenter|FontEngine::AlignBottom},
        {"MIX",
         &font,
         widgetBounds(fSliderForParameter[StonePhaserDsp::p_mix]).off_by({0, 4}),
         FontEngine::AlignCenter|FontEngine::AlignBottom},
#if DISTRHO_PLUGIN_NUM_INPUTS == 2
        {"STEREO PHASE",
         &font,
         widgetBounds(fSliderForParameter[StonePhaserDsp::p_stereo_phase]).off_by({0, 4}),
         FontEngine::AlignCenter|FontEngine::AlignBottom},
#endif
        {"RATE",
         &font,
         widgetBounds(fSliderForParameter[StonePhaserDsp::p_lfo_frequency]).off_by({0, 4}),
         FontEngine::AlignCenter|FontEngine::AlignBottom},
        {"STATUS",
         &font,
         widgetBounds(fIndicatorForParameter[StonePhaserDsp::p_bypass]).off_by({0, 21}),
         FontEngine::AlignCenter|FontEngine::AlignBottom},
        {DISTRHO_PLUGIN_BRAND,
         &fontBrand,
         brandLabelBounds.off_by({0, 4}),
         FontEngine::AlignCenter},
    };

    FontEngine &fe = *fFontEngine;
    for (const TextItem &item : textItems) {
        fe.drawInBox(cr, item.text, *item.font, item.bounds, item.align);
    }

    cairo_set_line_width(cr, 1.0);
}

void PhaserUI::parameterChanged(uint32_t index, float value)
{
#ifdef DISTRHO_UI_PATCH_INVERTED_BYPASS
    if (index == StonePhaserDsp::p_bypass && hasInvertedBypass())
        value = 1.0f - value;
#endif

    SkinSlider *sl = fSliderForParameter[index];
    if (sl) {
        sl->setValueNotified(false);
        sl->setValue(convertNormalizedFromParameter(index, value));
        sl->setValueNotified(true);
    }

    SkinToggleButton *tb = fToggleButtonForParameter[index];
    if (tb) {
        tb->setValueNotified(false);
        tb->setValue(convertNormalizedFromParameter(index, value));
        tb->setValueNotified(true);
    }

    updateParameterValue(index, value);
}

void PhaserUI::updateParameterValue(uint32_t index, float value)
{
    SkinIndicator *in = fIndicatorForParameter[index];
    if (in)
        in->setValue(convertNormalizedFromParameter(index, value));
}

SkinSlider *PhaserUI::createKnobForParameter(unsigned index, const Rect &bounds, const KnobSkin &skin)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < StonePhaserDsp::NumParameters, nullptr);

    SkinSlider *sl = createSubWidget<SkinSlider>(skin, this);
    fSliderForParameter[index] = sl;
    sl->setAbsolutePos(bounds.x, bounds.y);
    sl->setOrientation(SkinSlider::Radial);

    const DISTRHO::Parameter &param = fParameters[index];
    sl->setValueBounds(0.0, 1.0);
    sl->setValue(convertNormalizedFromParameter(index, param.ranges.def));

    sl->ValueChangedCallback =
        [this, index](double value) {
            value = convertNormalizedToParameter(index, value);
            updateParameterValue(index, value);
            setParameterValue(index, value);
        };

    return sl;
}

SkinToggleButton *PhaserUI::createToggleButtonForParameter(unsigned index, const Rect &bounds, const KnobSkin &skin, bool invert)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < StonePhaserDsp::NumParameters, nullptr);

    SkinToggleButton *cb = createSubWidget<SkinToggleButton>(skin, this);
    fToggleButtonForParameter[index] = cb;
    cb->setAbsolutePos(bounds.x, bounds.y);

    cb->setHasInvertedAppearance(invert);

    const Parameter &param = fParameters[index];
    cb->setValue(param.ranges.def > 0.5f);

    cb->ValueChangedCallback =
        [this, index](bool value) {
            updateParameterValue(index, value);
#ifdef DISTRHO_UI_PATCH_INVERTED_BYPASS
            if (index == StonePhaserDsp::p_bypass && hasInvertedBypass())
                value = 1.0f - value;
#endif
            setParameterValue(index, value);
        };

    return cb;
}

SkinIndicator *PhaserUI::createIndicatorForParameter(unsigned index, const Rect &bounds, const KnobSkin &skin, bool invert)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < StonePhaserDsp::NumParameters, nullptr);

    SkinIndicator *in = createSubWidget<SkinIndicator>(skin, *fFontEngine, this);
    fIndicatorForParameter[index] = in;
    in->setAbsolutePos(bounds.x, bounds.y);

    in->setHasInvertedAppearance(invert);

    const DISTRHO::Parameter &param = fParameters[index];
    in->setValueBounds(0.0, 1.0);
    in->setValue(convertNormalizedFromParameter(index, param.ranges.def));

    return in;
}

double PhaserUI::convertNormalizedToParameter(unsigned index, double value)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < StonePhaserDsp::NumParameters, 0.0)

    const DISTRHO::Parameter &param = fParameters[index];
    double min = param.ranges.min;
    double max = param.ranges.max;

    if (param.hints & DISTRHO::kParameterIsLogarithmic)
        value = min * std::pow(max / min, value);
    else
        value = min + value * (max - min);

    if (param.hints & DISTRHO::kParameterIsInteger)
        value = std::lround(value);

    return value;
}

double PhaserUI::convertNormalizedFromParameter(unsigned index, double value)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < StonePhaserDsp::NumParameters, 0.0)

    const DISTRHO::Parameter &param = fParameters[index];
    double min = param.ranges.min;
    double max = param.ranges.max;

    if (param.hints & DISTRHO::kParameterIsLogarithmic)
        value = std::log(value / min) / std::log(max / min);
    else
        value = (value - min) / (max - min);

    return value;
}

//------------------------------------------------------------------------------

static std::mutex sMutex;
static volatile bool sInitialized = false;

static void staticInitUI()
{
    std::lock_guard<std::mutex> lock(sMutex);
    if (sInitialized)
        return;

    #define PNG(x) cairo_image_surface_create_from_png_data(Artwork::x##Data, Artwork::x##DataSize)
    sImgBackground.reset(PNG(pedal));
    cairo_surface_u imgKnob(PNG(knob));
    sImgSmallKnob.reset(cairo_image_surface_resize_to_height(imgKnob.get(), CAIRO_FORMAT_ARGB32, 79));
    sImgLargeKnob.reset(cairo_image_surface_resize_to_height(imgKnob.get(), CAIRO_FORMAT_ARGB32, 120));
    cairo_surface_u imgSwitch(PNG(switch));
    sImgSwitch.reset(cairo_image_surface_resize_to_height(imgSwitch.get(), CAIRO_FORMAT_ARGB32, 79));
    cairo_surface_u imgFootswitch(PNG(footswitch));
    sImgFootswitch.reset(cairo_image_surface_resize_to_height(imgFootswitch.get(), CAIRO_FORMAT_ARGB32, 130));
    sImgLed.reset(PNG(led));

    sSkinSmallKnob.reset(new KnobSkin(sImgSmallKnob.get(), 65));
    sSkinLargeKnob.reset(new KnobSkin(sImgLargeKnob.get(), 65));
    sSkinSwitch.reset(new KnobSkin(sImgSwitch.get(), 2));
    sSkinFootswitch.reset(new KnobSkin(sImgFootswitch.get(), 2));
    sSkinLed.reset(new KnobSkin(sImgLed.get(), 2));

    #undef PNG

    sInitialized = true;
}

//------------------------------------------------------------------------------

START_NAMESPACE_DISTRHO

UI *createUI()
{
    staticInitUI();
    return new PhaserUI;
}

END_NAMESPACE_DISTRHO
