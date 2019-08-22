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

static_assert(DISTRHO_PLUGIN_NUM_INPUTS == StonePhaserDsp::inputs,
              "The number of inputs does not match.");
static_assert(DISTRHO_PLUGIN_NUM_OUTPUTS == StonePhaserDsp::outputs,
              "The number of outputs does not match.");

// -----------------------------------------------------------------------

PhaserPlugin::PhaserPlugin()
    : Plugin(StonePhaserDsp::parameters, 0, 0)
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
    DISTRHO_SAFE_ASSERT_RETURN(index < StonePhaserDsp::parameters, 0);

    return fDsp.get_parameter(index);
}

/**
  Change a parameter value.
*/
void PhaserPlugin::setParameterValue(uint32_t index, float value)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < StonePhaserDsp::parameters,);

    fDsp.set_parameter(index, value);
}

// -----------------------------------------------------------------------
// Process

void PhaserPlugin::activate()
{
    fDsp.clear();
}


void PhaserPlugin::run(const float **inputs, float **outputs, uint32_t frames)
{
    WebCore::DenormalDisabler dd;
#if DISTRHO_PLUGIN_NUM_INPUTS == 1
    fDsp.process(inputs[0], outputs[0], frames);
#elif DISTRHO_PLUGIN_NUM_INPUTS == 2
    fDsp.process(inputs[0], inputs[1], outputs[0], outputs[1], frames);
#endif
}

// -----------------------------------------------------------------------

START_NAMESPACE_DISTRHO

Plugin *createPlugin()
{
    return new PhaserPlugin();
}

END_NAMESPACE_DISTRHO
