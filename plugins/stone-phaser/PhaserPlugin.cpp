/*
 * Stone phaser audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2019 Jean Pierre Cimalando <jp-dev@inbox.ru>
 */

#include "PhaserPlugin.hpp"
#include "PhaserShared.hpp"
#include "blink/DenormalDisabler.h"
#include <cmath>
#include <cstring>

static_assert(DISTRHO_PLUGIN_NUM_INPUTS == StonePhaserDsp::NumInputs,
              "The number of inputs does not match.");
static_assert(DISTRHO_PLUGIN_NUM_OUTPUTS == StonePhaserDsp::NumOutputs,
              "The number of outputs does not match.");

// -----------------------------------------------------------------------

PhaserPlugin::PhaserPlugin()
    : Plugin(StonePhaserDsp::NumActives, 0, 0)
{
    fDsp.init(getSampleRate());
}

PhaserPlugin::~PhaserPlugin()
{
}

// -----------------------------------------------------------------------
// Init

void PhaserPlugin::initParameter(uint32_t index, DISTRHO::Parameter &parameter)
{
    return InitParameter(index, parameter);
}

// -----------------------------------------------------------------------
// Internal data

/**
  Optional callback to inform the plugin about a sample rate change.
*/
void PhaserPlugin::sampleRateChanged(double newSampleRate)
{
    fDsp.init(newSampleRate);
}

/**
  Get the current value of a parameter.
*/
float PhaserPlugin::getParameterValue(uint32_t index) const
{
    DISTRHO_SAFE_ASSERT_RETURN(index < StonePhaserDsp::NumActives, 0);

    return fDsp.get_parameter(index);
}

/**
  Change a parameter value.
*/
void PhaserPlugin::setParameterValue(uint32_t index, float value)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < StonePhaserDsp::NumActives,);

    fDsp.set_parameter(index, value);
}

// -----------------------------------------------------------------------
// Process

void PhaserPlugin::activate()
{
    StonePhaserDsp &dsp = fDsp;

    dsp.clear();
    fTrueBypass = dsp.get_bypass() > 0.5f;
}

void PhaserPlugin::run(const float **inputs, float **outputs, uint32_t frames)
{
    StonePhaserDsp &dsp = fDsp;

    bool bypass = dsp.get_bypass() > 0.5f;
    if (!bypass)
        fTrueBypass = false;
    else {
        bool trueBypass = fTrueBypass;
        if (!trueBypass && dsp.get_bypass_meter() < 1e-4) {
            trueBypass = fTrueBypass = true;
            dsp.clear();
        }
        if (trueBypass) {
            for (unsigned i = 0; i < DISTRHO_PLUGIN_NUM_INPUTS; ++i)
                std::memcpy(outputs[i], inputs[i], frames * sizeof(uint32_t));
            return;
        }
    }

    WebCore::DenormalDisabler dd;

#if DISTRHO_PLUGIN_NUM_INPUTS == 1
    dsp.process(inputs[0], outputs[0], frames);
#elif DISTRHO_PLUGIN_NUM_INPUTS == 2
    dsp.process(inputs[0], inputs[1], outputs[0], outputs[1], frames);
#endif
}

// -----------------------------------------------------------------------

START_NAMESPACE_DISTRHO

Plugin *createPlugin()
{
    return new PhaserPlugin();
}

END_NAMESPACE_DISTRHO
