declare name "Chirp synthesizer";
declare author "Jean Pierre Cimalando";
declare version "1.0";
declare license "CC0-1.0";

// chirp synthesizer with all-pass filter chain
// analysis signal generator for phasers

import("stdfaust.lib");

process = os.lf_imptrain(oscf) : seq(i,64,allpass1(apf)) with {
  oscf = 1.0/30e-3;
  apf = 701.87330;
};

allpass1(f) = fi.iir((a,1.),(a)) with {
  a = -1.+2.*ma.PI*f/ma.SR;
};
