//-----------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: stone_phaser.dsp
// Name: Stone Phaser
// Author: Jean Pierre Cimalando
// Copyright: 
// License: CC0-1.0
// Version: 1.2.2
//-----------------------------------------------------------------------------

#pragma once
#ifndef StonePhaserDsp_Faust_pp_Gen_HPP_
#define StonePhaserDsp_Faust_pp_Gen_HPP_

#if __cplusplus < 201103L
#   define noexcept
#endif

class mydsp;

class StonePhaserDsp {
public:
    StonePhaserDsp();
    ~StonePhaserDsp();

    void init(float sample_rate);
    void clear() noexcept;

    void process(
        const float *in0,
        float *out0,
        unsigned count) noexcept;

    enum { inputs = 1 };
    enum { outputs = 1 };
    enum { parameters = 6 };

    enum Parameter {
        p_bypass,
        p_color,
        p_lfo_frequency,
        p_feedback_depth,
        p_feedback_hpf_cutoff,
        p_mix,
        
    };


    struct ParameterRange {
        float init;
        float min;
        float max;
    };

    static const char *parameter_label(unsigned index) noexcept;
    static const char *parameter_symbol(unsigned index) noexcept;
    static const char *parameter_unit(unsigned index) noexcept;
    static const ParameterRange *parameter_range(unsigned index) noexcept;
    static bool parameter_is_trigger(unsigned index) noexcept;
    static bool parameter_is_boolean(unsigned index) noexcept;
    static bool parameter_is_integer(unsigned index) noexcept;
    static bool parameter_is_logarithmic(unsigned index) noexcept;

    float get_parameter(unsigned index) const noexcept;
    void set_parameter(unsigned index, float value) noexcept;

    
    float get_bypass() const noexcept;
    void set_bypass(float value) noexcept;
    
    float get_color() const noexcept;
    void set_color(float value) noexcept;
    
    float get_lfo_frequency() const noexcept;
    void set_lfo_frequency(float value) noexcept;
    
    float get_feedback_depth() const noexcept;
    void set_feedback_depth(float value) noexcept;
    
    float get_feedback_hpf_cutoff() const noexcept;
    void set_feedback_hpf_cutoff(float value) noexcept;
    
    float get_mix() const noexcept;
    void set_mix(float value) noexcept;
    

private:
    mydsp *fDsp;

private:
    StonePhaserDsp(const StonePhaserDsp &other);
    StonePhaserDsp &operator=(const StonePhaserDsp &other);

#if __cplusplus >= 201103L
public:
    StonePhaserDsp(StonePhaserDsp &&other) noexcept;
    StonePhaserDsp &operator=(StonePhaserDsp &&other) noexcept;
#endif
};

#endif // StonePhaserDsp_Faust_pp_Gen_HPP_
