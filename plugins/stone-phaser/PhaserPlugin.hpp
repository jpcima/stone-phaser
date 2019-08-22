/*
 * Stone phaser audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * SPDX-License-Identifier: BSL-1.0
 *
 * Copyright (C) 2019 Jean Pierre Cimalando <jp-dev@inbox.ru>
 */

#pragma once
#include "DistrhoPlugin.hpp"
#include <memory>

class mydsp;

// -----------------------------------------------------------------------

class PhaserPlugin : public Plugin {
public:
    PhaserPlugin();
    ~PhaserPlugin();

protected:
    // -------------------------------------------------------------------
    // Information

    const char *getLabel() const noexcept override
    {
#if DISTRHO_PLUGIN_NUM_INPUTS == 1
        return "stone-phaser";
#elif DISTRHO_PLUGIN_NUM_INPUTS == 2
        return "stone-phaser-stereo";
#endif
    }

    const char *getDescription() const noexcept override
    {
#if DISTRHO_PLUGIN_NUM_INPUTS == 1
        return "A classic analog phaser effect";
#elif DISTRHO_PLUGIN_NUM_INPUTS == 2
        return "A classic analog phaser effect (stereo)";
#endif
    }

    const char *getMaker() const noexcept override
    {
        return "Jean Pierre Cimalando";
    }

    const char *getHomePage() const noexcept override
    {
        return "https://github.com/jpcima/stone-phaser";
    }

    const char *getLicense() const noexcept override
    {
        return "https://spdx.org/licenses/BSL-1.0";
    }

    uint32_t getVersion() const noexcept override
    {
        return d_version(0, 1, 0);
    }

    int64_t getUniqueId() const noexcept override
    {
#if DISTRHO_PLUGIN_NUM_INPUTS == 1
        return d_cconst('s', 's', 'p', '1');
#elif DISTRHO_PLUGIN_NUM_INPUTS == 2
        return d_cconst('s', 's', 'p', '2');
#endif
    }

    // -------------------------------------------------------------------
    // Init

    void initParameter(uint32_t index, Parameter &parameter) override;

    // -------------------------------------------------------------------
    // Internal data

    float getParameterValue(uint32_t index) const override;
    void setParameterValue(uint32_t index, float value) override;

    // -------------------------------------------------------------------
    // Optional

    // Optional callback to inform the plugin about a sample rate change.
    void sampleRateChanged(double newSampleRate) override;

    // -------------------------------------------------------------------
    // Process

    void activate() override;

    void run(const float **inputs, float **outputs, uint32_t frames) override;


    // -------------------------------------------------------------------

private:
    std::unique_ptr<mydsp> fDsp;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PhaserPlugin)
};
