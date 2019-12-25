#include "PhaserShared.hpp"
#include "StonePhaserDsp.hpp"

void InitParameter(uint32_t index, DISTRHO::Parameter &parameter)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < StonePhaserDsp::NumActives,);

    switch (index) {
    case StonePhaserDsp::p_bypass:
        parameter.initDesignation(DISTRHO::kParameterDesignationBypass);
        break;
    default:
        parameter.name = StonePhaserDsp::parameter_label(index);
        parameter.shortName = StonePhaserDsp::parameter_short_label(index);
        parameter.symbol = StonePhaserDsp::parameter_symbol(index);
        parameter.unit = StonePhaserDsp::parameter_unit(index);
        parameter.hints = DISTRHO::kParameterIsAutomable;

        const StonePhaserDsp::ParameterRange *pr = StonePhaserDsp::parameter_range(index);
        parameter.ranges.min = pr->min;
        parameter.ranges.max = pr->max;
        parameter.ranges.def = pr->init;

        if (StonePhaserDsp::parameter_is_trigger(index))
            parameter.hints |= DISTRHO::kParameterIsTrigger;
        if (StonePhaserDsp::parameter_is_boolean(index))
            parameter.hints |= DISTRHO::kParameterIsBoolean;
        if (StonePhaserDsp::parameter_is_integer(index))
            parameter.hints |= DISTRHO::kParameterIsInteger;
        if (StonePhaserDsp::parameter_is_logarithmic(index))
            parameter.hints |= DISTRHO::kParameterIsLogarithmic;

        break;
    }
}
