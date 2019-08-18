#include <DistrhoPlugin.hpp>

namespace FAUSTMETA {

static void init_active_parameter(uint32_t index, DISTRHO::Parameter &parameter)
{
    FAUSTFLOAT step = FAUSTMETA::active_step[index];
    FAUSTFLOAT min = FAUSTMETA::active_min[index];
    FAUSTFLOAT max = FAUSTMETA::active_max[index];
    FAUSTFLOAT init = FAUSTMETA::active_init[index];
    FAUSTMETA::active_type_t type = FAUSTMETA::active_type[index];
    FAUSTMETA::scale_t scale = FAUSTMETA::active_scale[index];

    parameter.name = FAUSTMETA::active_label[index];
    parameter.symbol = FAUSTMETA::active_symbol[index];
    parameter.unit = FAUSTMETA::active_unit[index];
    parameter.hints = kParameterIsAutomable;

    parameter.ranges.min = min;
    parameter.ranges.max = max;
    parameter.ranges.def = init;

    if (type == FAUSTMETA::active_type_t::button)
        parameter.hints |= kParameterIsTrigger;
    else if (type == FAUSTMETA::active_type_t::checkbox) {
        parameter.hints |= kParameterIsBoolean|kParameterIsInteger;
    }
    else {
        if (step == 1 && (int)min == min && (int)max == max && (int)init == init) {
            parameter.hints |= kParameterIsInteger;
            if ((int)min + (int)step == (int)max)
                parameter.hints |= kParameterIsBoolean;
        }
    }
    if (scale == FAUSTMETA::scale_t::log)
        parameter.hints |= kParameterIsLogarithmic;
}

} // namespace FAUSTMETA
