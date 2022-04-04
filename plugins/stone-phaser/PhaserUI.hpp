#pragma once
#include "DistrhoUI.hpp"
#include "DistrhoPlugin.hpp"
#include "StonePhaserDsp.hpp"
#include "ui/Geometry.h"
#include <list>
#include <utility>
#include <memory>

class KnobSkin;
class SkinSlider;
class SkinToggleButton;
class SkinIndicator;
class FontEngine;

//------------------------------------------------------------------------------
class PhaserUI : public DISTRHO::UI {
public:
    PhaserUI();
    ~PhaserUI();

protected:
    void onDisplay() override;
    void parameterChanged(uint32_t index, float value) override;

private:
    void updateParameterValue(uint32_t index, float value);
    SkinSlider *createKnobForParameter(unsigned index, const Rect &bounds, const KnobSkin &skin);
    SkinToggleButton *createToggleButtonForParameter(unsigned index, const Rect &bounds, const KnobSkin &skin, bool invert = false);
    SkinIndicator *createIndicatorForParameter(unsigned index, const Rect &bounds, const KnobSkin &skin, bool invert = false);

    double convertNormalizedToParameter(unsigned index, double value);
    double convertNormalizedFromParameter(unsigned index, double value);

    //--------------------------------------------------------------------------
    template <class T, class... Args> T *createSubWidget(Args &&... args)
    {
        T *w = new T(std::forward<Args>(args)...);
        fSubWidgets.emplace_back(w);
        return w;
    }

private:
    std::unique_ptr<DISTRHO::Parameter[]> fParameters;
    std::unique_ptr<SkinSlider *[]> fSliderForParameter;
    std::unique_ptr<SkinToggleButton *[]> fToggleButtonForParameter;
    std::unique_ptr<SkinIndicator *[]> fIndicatorForParameter;
    std::unique_ptr<FontEngine> fFontEngine;
    std::list<std::unique_ptr<SubWidget>> fSubWidgets;
};
