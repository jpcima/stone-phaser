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
        return "stone-phaser-stereo";
    }

    const char *getDescription() const override
    {
        return "A classic analog phaser effect (stereo)";
    }

    const char *getMaker() const noexcept override
    {
        return "Jean Pierre Cimalando";
    }

    const char *getHomePage() const override
    {
        return "http://jpcima.sdf1.org/lv2/stone-phaser-stereo";
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
        return d_cconst('s', 's', 'p', '2');
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
