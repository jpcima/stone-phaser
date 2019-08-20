/*
 * Stone phaser audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2019 Jean Pierre Cimalando <jp-dev@inbox.ru>
 */

#include "PhaserPlugin.hpp"
#include "StonePhaserDsp.cpp"
#include "blink/DenormalDisabler.h"
#include <cmath>
#include <cstring>

static_assert(DISTRHO_PLUGIN_NUM_INPUTS == mydsp_meta::inputs,
              "The number of inputs does not match.");
static_assert(DISTRHO_PLUGIN_NUM_OUTPUTS == mydsp_meta::outputs,
              "The number of outputs does not match.");

// -----------------------------------------------------------------------

PhaserPlugin::PhaserPlugin()
    : Plugin(mydsp_meta::actives, 0, 0),
      fDsp(new mydsp)
{
    fDsp->init(getSampleRate());
}

PhaserPlugin::~PhaserPlugin()
{
}

// -----------------------------------------------------------------------
// Init

void PhaserPlugin::initParameter(uint32_t index, Parameter &parameter)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < mydsp_meta::actives,);

    switch (index) {
    case 0:
        DISTRHO_SAFE_ASSERT(!strcmp(mydsp_meta::active_label[index], "Bypass"));
        parameter.designation = kParameterDesignationBypass;
        break;
    default:
        mydsp_meta::init_active_parameter(index, parameter);
        break;
    }
}

// -----------------------------------------------------------------------
// Internal data

/**
  Optional callback to inform the plugin about a sample rate change.
*/
void PhaserPlugin::sampleRateChanged(double newSampleRate)
{
    fDsp->instanceConstants(newSampleRate);
    fDsp->instanceClear();
}

/**
  Get the current value of a parameter.
*/
float PhaserPlugin::getParameterValue(uint32_t index) const
{
    DISTRHO_SAFE_ASSERT_RETURN(index < mydsp_meta::actives, 0);

    return mydsp_meta::active_get(*fDsp, index);
}

/**
  Change a parameter value.
*/
void PhaserPlugin::setParameterValue(uint32_t index, float value)
{
    DISTRHO_SAFE_ASSERT_RETURN(index < mydsp_meta::actives,);

    mydsp_meta::active_set(*fDsp, index, value);
}

// -----------------------------------------------------------------------
// Process

void PhaserPlugin::activate()
{
    fDsp->instanceClear();
}


void PhaserPlugin::run(const float **inputs, float **outputs, uint32_t frames)
{
    WebCore::DenormalDisabler dd;
    fDsp->compute(frames, (float **)inputs, outputs);
}

// -----------------------------------------------------------------------

START_NAMESPACE_DISTRHO

Plugin *createPlugin()
{
    return new PhaserPlugin();
}

END_NAMESPACE_DISTRHO
