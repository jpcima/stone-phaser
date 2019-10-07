//-----------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: stone_phaser.dsp
// Name: Stone Phaser
// Author: Jean Pierre Cimalando
// Copyright: 
// License: CC0-1.0
// Version: 1.2.3
//-----------------------------------------------------------------------------

#include "StonePhaserDsp.hpp"

//------------------------------------------------------------------------------
// Begin the Faust code section

template <class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template <class T> inline T max(T a, T b) { return (a > b) ? a : b; }

// dummy
class Meta {
public:
    void declare(...) {}
};

// dummy
class UI {
public:
    void openHorizontalBox(...) {}
    void openVerticalBox(...) {}
    void closeBox(...) {}
    void declare(...) {}
    void addButton(...) {}
    void addCheckButton(...) {}
    void addVerticalSlider(...) {}
    void addHorizontalSlider(...) {}
    void addVerticalBargraph(...) {}
};

// dummy
class dsp {
public:
};

#define FAUSTPP_VIRTUAL // do not declare any methods virtual
#define FAUSTPP_PRIVATE public // do not hide any members
#define FAUSTPP_PROTECTED public // do not hide any members

#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTPP_PRIVATE
#   define FAUSTPP_PRIVATE private
#endif
#ifndef FAUSTPP_PROTECTED
#   define FAUSTPP_PROTECTED protected
#endif
#ifndef FAUSTPP_VIRTUAL
#   define FAUSTPP_VIRTUAL virtual
#endif

#ifndef FAUSTPP_BEGIN_NAMESPACE
#   define FAUSTPP_BEGIN_NAMESPACE
#endif
#ifndef FAUSTPP_END_NAMESPACE
#   define FAUSTPP_END_NAMESPACE
#endif

FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
FAUSTPP_END_NAMESPACE
#include <algorithm>
#include <cmath>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE


class mydspSIG0 {
	
  FAUSTPP_PRIVATE:
	
	int iRec14[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
		
	}
	int getNumOutputsmydspSIG0() {
		return 1;
		
	}
	int getInputRatemydspSIG0(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	int getOutputRatemydspSIG0(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	void instanceInitmydspSIG0(int samplingFreq) {
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			iRec14[l10] = 0;
			
		}
		
	}
	
	void fillmydspSIG0(int count, float* output) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec14[0] = (iRec14[1] + 1);
			float fTemp0 = (0.0078125f * float((iRec14[0] + -1)));
			float fTemp1 = float(int(fTemp0));
			float fTemp2 = (fTemp0 - fTemp1);
			output[i] = (1.0f - (1.02564108f * std::sin((2.69344211f * ((fTemp2 < 0.5f)?fTemp2:(fTemp1 + (1.0f - fTemp0)))))));
			iRec14[1] = iRec14[0];
			
		}
		
	}

};

mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }


class mydspSIG1 {
	
  FAUSTPP_PRIVATE:
	
	int iRec15[2];
	
  public:
	
	int getNumInputsmydspSIG1() {
		return 0;
		
	}
	int getNumOutputsmydspSIG1() {
		return 1;
		
	}
	int getInputRatemydspSIG1(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	int getOutputRatemydspSIG1(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	void instanceInitmydspSIG1(int samplingFreq) {
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			iRec15[l12] = 0;
			
		}
		
	}
	
	void fillmydspSIG1(int count, float* output) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec15[0] = (iRec15[1] + 1);
			output[i] = float(tanhf(float((0.0393700786f * float((iRec15[0] + -1))))));
			iRec15[1] = iRec15[0];
			
		}
		
	}

};

mydspSIG1* newmydspSIG1() { return (mydspSIG1*)new mydspSIG1(); }
void deletemydspSIG1(mydspSIG1* dsp) { delete dsp; }

static float ftbl0mydspSIG0[128];
static float ftbl1mydspSIG1[128];

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	int fSamplingFreq;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fCheckbox0;
	float fRec0_perm[4];
	float fConst3;
	float fRec2_perm[4];
	float fConst4;
	FAUSTFLOAT fHslider0;
	float fRec4_perm[4];
	FAUSTFLOAT fHslider1;
	float fRec3_perm[4];
	FAUSTFLOAT fHslider2;
	float fRec6_perm[4];
	float fConst5;
	float fRec5_perm[4];
	float fRec8_perm[4];
	float fRec9_perm[4];
	FAUSTFLOAT fHslider3;
	float fRec11_perm[4];
	float fRec10_perm[4];
	float fConst6;
	float fConst7;
	float fConst8;
	float fYec0_perm[4];
	float fRec13_perm[4];
	float fYec1_perm[4];
	float fRec16_perm[4];
	float fYec2_perm[4];
	float fRec12_perm[4];
	float fYec3_perm[4];
	float fRec7_perm[4];
	float fRec1_perm[4];
	FAUSTFLOAT fHslider4;
	float fRec17_perm[4];
	float fRec18_perm[4];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "Jean Pierre Cimalando");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("filename", "stone_phaser");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("license", "CC0-1.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "Stone Phaser");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
		m->declare("version", "1.2.3");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 1;
		
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 1;
		
	}
	FAUSTPP_VIRTUAL int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	FAUSTPP_VIRTUAL int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(samplingFreq);
		sig0->fillmydspSIG0(128, ftbl0mydspSIG0);
		mydspSIG1* sig1 = newmydspSIG1();
		sig1->instanceInitmydspSIG1(samplingFreq);
		sig1->fillmydspSIG1(128, ftbl1mydspSIG1);
		deletemydspSIG0(sig0);
		deletemydspSIG1(sig1);
		
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq)));
		fConst1 = std::exp((0.0f - (10.0f / fConst0)));
		fConst2 = (1.0f - fConst1);
		fConst3 = std::exp((0.0f - (207.345108f / fConst0)));
		fConst4 = (0.00999999978f * fConst2);
		fConst5 = (1.0f / fConst0);
		fConst6 = (440.0f * (0.0f - (6.28318548f / fConst0)));
		fConst7 = (0.5f * (fConst3 + 1.0f));
		fConst8 = (0.0f - fConst7);
		
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(75.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(500.0f);
		fHslider3 = FAUSTFLOAT(0.20000000000000001f);
		fHslider4 = FAUSTFLOAT(50.0f);
		
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; (l0 < 4); l0 = (l0 + 1)) {
			fRec0_perm[l0] = 0.0f;
			
		}
		for (int l1 = 0; (l1 < 4); l1 = (l1 + 1)) {
			fRec2_perm[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 4); l2 = (l2 + 1)) {
			fRec4_perm[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 4); l3 = (l3 + 1)) {
			fRec3_perm[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 4); l4 = (l4 + 1)) {
			fRec6_perm[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 4); l5 = (l5 + 1)) {
			fRec5_perm[l5] = 0.0f;
			
		}
		for (int l6 = 0; (l6 < 4); l6 = (l6 + 1)) {
			fRec8_perm[l6] = 0.0f;
			
		}
		for (int l7 = 0; (l7 < 4); l7 = (l7 + 1)) {
			fRec9_perm[l7] = 0.0f;
			
		}
		for (int l8 = 0; (l8 < 4); l8 = (l8 + 1)) {
			fRec11_perm[l8] = 0.0f;
			
		}
		for (int l9 = 0; (l9 < 4); l9 = (l9 + 1)) {
			fRec10_perm[l9] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 4); l11 = (l11 + 1)) {
			fYec0_perm[l11] = 0.0f;
			
		}
		for (int l13 = 0; (l13 < 4); l13 = (l13 + 1)) {
			fRec13_perm[l13] = 0.0f;
			
		}
		for (int l14 = 0; (l14 < 4); l14 = (l14 + 1)) {
			fYec1_perm[l14] = 0.0f;
			
		}
		for (int l15 = 0; (l15 < 4); l15 = (l15 + 1)) {
			fRec16_perm[l15] = 0.0f;
			
		}
		for (int l16 = 0; (l16 < 4); l16 = (l16 + 1)) {
			fYec2_perm[l16] = 0.0f;
			
		}
		for (int l17 = 0; (l17 < 4); l17 = (l17 + 1)) {
			fRec12_perm[l17] = 0.0f;
			
		}
		for (int l18 = 0; (l18 < 4); l18 = (l18 + 1)) {
			fYec3_perm[l18] = 0.0f;
			
		}
		for (int l19 = 0; (l19 < 4); l19 = (l19 + 1)) {
			fRec7_perm[l19] = 0.0f;
			
		}
		for (int l20 = 0; (l20 < 4); l20 = (l20 + 1)) {
			fRec1_perm[l20] = 0.0f;
			
		}
		for (int l21 = 0; (l21 < 4); l21 = (l21 + 1)) {
			fRec17_perm[l21] = 0.0f;
			
		}
		for (int l22 = 0; (l22 < 4); l22 = (l22 + 1)) {
			fRec18_perm[l22] = 0.0f;
			
		}
		
	}
	
	FAUSTPP_VIRTUAL void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	
	FAUSTPP_VIRTUAL void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Stone Phaser");
		ui_interface->declare(&fCheckbox0, "0", "");
		ui_interface->declare(&fCheckbox0, "symbol", "bypass");
		ui_interface->addCheckButton("Bypass", &fCheckbox0);
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->declare(&fHslider1, "boolean", "");
		ui_interface->declare(&fHslider1, "symbol", "color");
		ui_interface->addHorizontalSlider("Color", &fHslider1, 1.0f, 0.0f, 1.0f, 1.0f);
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->declare(&fHslider3, "scale", "log");
		ui_interface->declare(&fHslider3, "symbol", "lfo_frequency");
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("LFO frequency", &fHslider3, 0.200000003f, 0.00999999978f, 5.0f, 0.00999999978f);
		ui_interface->declare(&fHslider0, "3", "");
		ui_interface->declare(&fHslider0, "integer", "");
		ui_interface->declare(&fHslider0, "symbol", "feedback_depth");
		ui_interface->declare(&fHslider0, "unit", "%");
		ui_interface->addHorizontalSlider("Feedback depth", &fHslider0, 75.0f, 0.0f, 99.0f, 1.0f);
		ui_interface->declare(&fHslider2, "4", "");
		ui_interface->declare(&fHslider2, "abbrev", "Fb bass cut");
		ui_interface->declare(&fHslider2, "scale", "log");
		ui_interface->declare(&fHslider2, "symbol", "feedback_hpf_cutoff");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("Feedback bass cut", &fHslider2, 500.0f, 10.0f, 5000.0f, 1.0f);
		ui_interface->declare(&fHslider4, "5", "");
		ui_interface->declare(&fHslider4, "integer", "");
		ui_interface->declare(&fHslider4, "symbol", "mix");
		ui_interface->declare(&fHslider4, "unit", "%");
		ui_interface->addHorizontalSlider("Dry/wet mix", &fHslider4, 50.0f, 0.0f, 100.0f, 1.0f);
		ui_interface->closeBox();
		
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0_ptr = inputs[0];
		FAUSTFLOAT* output0_ptr = outputs[0];
		float fSlow0 = (fConst2 * float(fCheckbox0));
		float fRec0_tmp[36];
		float* fRec0 = &fRec0_tmp[4];
		float fRec2_tmp[36];
		float* fRec2 = &fRec2_tmp[4];
		float fSlow1 = (fConst4 * float(fHslider0));
		float fRec4_tmp[36];
		float* fRec4 = &fRec4_tmp[4];
		int iSlow2 = int(float(fHslider1));
		float fRec3_tmp[36];
		float* fRec3 = &fRec3_tmp[4];
		float fSlow3 = (fConst2 * float(fHslider2));
		float fRec6_tmp[36];
		float* fRec6 = &fRec6_tmp[4];
		float fZec0[32];
		float fRec5_tmp[36];
		float* fRec5 = &fRec5_tmp[4];
		float fSlow4 = (fConst2 * (iSlow2?39.4868202f:62.3695068f));
		float fRec8_tmp[36];
		float* fRec8 = &fRec8_tmp[4];
		float fSlow5 = (fConst2 * (iSlow2?96.8631363f:114.232643f));
		float fRec9_tmp[36];
		float* fRec9 = &fRec9_tmp[4];
		float fSlow6 = (fConst2 * float(fHslider3));
		float fRec11_tmp[36];
		float* fRec11 = &fRec11_tmp[4];
		float fZec1[32];
		float fRec10_tmp[36];
		float* fRec10 = &fRec10_tmp[4];
		float fZec2[32];
		int iZec3[32];
		float fZec4[32];
		float fZec5[32];
		float fZec6[32];
		float fZec7[32];
		float fZec8[32];
		float fZec9[32];
		float fYec0_tmp[36];
		float* fYec0 = &fYec0_tmp[4];
		float fZec10[32];
		float fZec11[32];
		int iZec12[32];
		float fZec13[32];
		float fRec13_tmp[36];
		float* fRec13 = &fRec13_tmp[4];
		float fYec1_tmp[36];
		float* fYec1 = &fYec1_tmp[4];
		float fZec14[32];
		float fZec15[32];
		int iZec16[32];
		float fZec17[32];
		float fRec16_tmp[36];
		float* fRec16 = &fRec16_tmp[4];
		float fZec18[32];
		float fYec2_tmp[36];
		float* fYec2 = &fYec2_tmp[4];
		float fZec19[32];
		float fZec20[32];
		int iZec21[32];
		float fZec22[32];
		float fRec12_tmp[36];
		float* fRec12 = &fRec12_tmp[4];
		float fZec23[32];
		float fYec3_tmp[36];
		float* fYec3 = &fYec3_tmp[4];
		float fZec24[32];
		float fZec25[32];
		int iZec26[32];
		float fZec27[32];
		float fRec7_tmp[36];
		float* fRec7 = &fRec7_tmp[4];
		float fRec1_tmp[36];
		float* fRec1 = &fRec1_tmp[4];
		float fSlow7 = (0.0157079641f * float(fHslider4));
		float fSlow8 = (fConst2 * std::sin(fSlow7));
		float fRec17_tmp[36];
		float* fRec17 = &fRec17_tmp[4];
		float fSlow9 = (fConst2 * std::cos(fSlow7));
		float fRec18_tmp[36];
		float* fRec18 = &fRec18_tmp[4];
		int vindex = 0;
		/* Main loop */
		for (vindex = 0; (vindex <= (count - 32)); vindex = (vindex + 32)) {
			FAUSTFLOAT* input0 = &input0_ptr[vindex];
			FAUSTFLOAT* output0 = &output0_ptr[vindex];
			int vsize = 32;
			/* Recursive loop 0 */
			/* Pre code */
			for (int j16 = 0; (j16 < 4); j16 = (j16 + 1)) {
				fRec11_tmp[j16] = fRec11_perm[j16];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec11[i] = (fSlow6 + (fConst1 * fRec11[(i - 1)]));
				
			}
			/* Post code */
			for (int j17 = 0; (j17 < 4); j17 = (j17 + 1)) {
				fRec11_perm[j17] = fRec11_tmp[(vsize + j17)];
				
			}
			/* Recursive loop 1 */
			/* Pre code */
			for (int j18 = 0; (j18 < 4); j18 = (j18 + 1)) {
				fRec10_tmp[j18] = fRec10_perm[j18];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec1[i] = (fRec10[(i - 1)] + (fConst5 * fRec11[(i - 1)]));
				fRec10[i] = (fZec1[i] - std::floor(fZec1[i]));
				
			}
			/* Post code */
			for (int j19 = 0; (j19 < 4); j19 = (j19 + 1)) {
				fRec10_perm[j19] = fRec10_tmp[(vsize + j19)];
				
			}
			/* Vectorizable loop 2 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec2[i] = (128.0f * fRec10[i]);
				
			}
			/* Recursive loop 3 */
			/* Pre code */
			for (int j8 = 0; (j8 < 4); j8 = (j8 + 1)) {
				fRec6_tmp[j8] = fRec6_perm[j8];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec6[i] = (fSlow3 + (fConst1 * fRec6[(i - 1)]));
				
			}
			/* Post code */
			for (int j9 = 0; (j9 < 4); j9 = (j9 + 1)) {
				fRec6_perm[j9] = fRec6_tmp[(vsize + j9)];
				
			}
			/* Vectorizable loop 4 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				iZec3[i] = int(fZec2[i]);
				
			}
			/* Recursive loop 5 */
			/* Pre code */
			for (int j2 = 0; (j2 < 4); j2 = (j2 + 1)) {
				fRec2_tmp[j2] = fRec2_perm[j2];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec2[i] = ((fConst3 * fRec2[(i - 1)]) + float(input0[i]));
				
			}
			/* Post code */
			for (int j3 = 0; (j3 < 4); j3 = (j3 + 1)) {
				fRec2_perm[j3] = fRec2_tmp[(vsize + j3)];
				
			}
			/* Recursive loop 6 */
			/* Pre code */
			for (int j4 = 0; (j4 < 4); j4 = (j4 + 1)) {
				fRec4_tmp[j4] = fRec4_perm[j4];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec4[i] = (fSlow1 + (fConst1 * fRec4[(i - 1)]));
				
			}
			/* Post code */
			for (int j5 = 0; (j5 < 4); j5 = (j5 + 1)) {
				fRec4_perm[j5] = fRec4_tmp[(vsize + j5)];
				
			}
			/* Vectorizable loop 7 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec0[i] = std::exp((fConst5 * (0.0f - (6.28318548f * fRec6[i]))));
				
			}
			/* Recursive loop 8 */
			/* Pre code */
			for (int j12 = 0; (j12 < 4); j12 = (j12 + 1)) {
				fRec8_tmp[j12] = fRec8_perm[j12];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec8[i] = ((fConst1 * fRec8[(i - 1)]) + fSlow4);
				
			}
			/* Post code */
			for (int j13 = 0; (j13 < 4); j13 = (j13 + 1)) {
				fRec8_perm[j13] = fRec8_tmp[(vsize + j13)];
				
			}
			/* Recursive loop 9 */
			/* Pre code */
			for (int j14 = 0; (j14 < 4); j14 = (j14 + 1)) {
				fRec9_tmp[j14] = fRec9_perm[j14];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec9[i] = ((fConst1 * fRec9[(i - 1)]) + fSlow5);
				
			}
			/* Post code */
			for (int j15 = 0; (j15 < 4); j15 = (j15 + 1)) {
				fRec9_perm[j15] = fRec9_tmp[(vsize + j15)];
				
			}
			/* Vectorizable loop 10 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec4[i] = float(iZec3[i]);
				
			}
			/* Recursive loop 11 */
			/* Pre code */
			for (int j6 = 0; (j6 < 4); j6 = (j6 + 1)) {
				fRec3_tmp[j6] = fRec3_perm[j6];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec3[i] = ((fConst1 * fRec3[(i - 1)]) + (fConst2 * (iSlow2?fRec4[i]:(0.100000001f * fRec4[i]))));
				
			}
			/* Post code */
			for (int j7 = 0; (j7 < 4); j7 = (j7 + 1)) {
				fRec3_perm[j7] = fRec3_tmp[(vsize + j7)];
				
			}
			/* Vectorizable loop 12 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec5[i] = (1.0f - std::exp((fConst6 * std::pow(2.0f, (0.0833333358f * ((fRec8[i] + ((fRec9[i] - fRec8[i]) * ((ftbl0mydspSIG0[iZec3[i]] * (fZec4[i] + (1.0f - fZec2[i]))) + ((fZec2[i] - fZec4[i]) * ftbl0mydspSIG0[((iZec3[i] + 1) % 128)])))) + -69.0f))))));
				
			}
			/* Vectorizable loop 13 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec6[i] = (fConst8 * fRec2[(i - 1)]);
				
			}
			/* Vectorizable loop 14 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec7[i] = (fZec0[i] + 1.0f);
				
			}
			/* Vectorizable loop 15 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec9[i] = (fConst7 * fRec2[i]);
				
			}
			/* Recursive loop 16 */
			/* Pre code */
			for (int j0 = 0; (j0 < 4); j0 = (j0 + 1)) {
				fRec0_tmp[j0] = fRec0_perm[j0];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec0[i] = (fSlow0 + (fConst1 * fRec0[(i - 1)]));
				
			}
			/* Post code */
			for (int j1 = 0; (j1 < 4); j1 = (j1 + 1)) {
				fRec0_perm[j1] = fRec0_tmp[(vsize + j1)];
				
			}
			/* Recursive loop 17 */
			/* Pre code */
			for (int j10 = 0; (j10 < 4); j10 = (j10 + 1)) {
				fRec5_tmp[j10] = fRec5_perm[j10];
				
			}
			for (int j20 = 0; (j20 < 4); j20 = (j20 + 1)) {
				fYec0_tmp[j20] = fYec0_perm[j20];
				
			}
			for (int j22 = 0; (j22 < 4); j22 = (j22 + 1)) {
				fRec13_tmp[j22] = fRec13_perm[j22];
				
			}
			for (int j24 = 0; (j24 < 4); j24 = (j24 + 1)) {
				fYec1_tmp[j24] = fYec1_perm[j24];
				
			}
			for (int j26 = 0; (j26 < 4); j26 = (j26 + 1)) {
				fRec16_tmp[j26] = fRec16_perm[j26];
				
			}
			for (int j28 = 0; (j28 < 4); j28 = (j28 + 1)) {
				fYec2_tmp[j28] = fYec2_perm[j28];
				
			}
			for (int j30 = 0; (j30 < 4); j30 = (j30 + 1)) {
				fRec12_tmp[j30] = fRec12_perm[j30];
				
			}
			for (int j32 = 0; (j32 < 4); j32 = (j32 + 1)) {
				fYec3_tmp[j32] = fYec3_perm[j32];
				
			}
			for (int j34 = 0; (j34 < 4); j34 = (j34 + 1)) {
				fRec7_tmp[j34] = fRec7_perm[j34];
				
			}
			for (int j36 = 0; (j36 < 4); j36 = (j36 + 1)) {
				fRec1_tmp[j36] = fRec1_perm[j36];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec5[i] = (fRec1[(i - 1)] + (fRec5[(i - 1)] * fZec0[i]));
				fZec8[i] = (fRec3[i] * ((0.5f * (fRec5[i] * fZec7[i])) + (fRec5[(i - 1)] * (0.0f - (0.5f * fZec7[i])))));
				fYec0[i] = (fZec6[i] + (fZec8[i] + fZec9[i]));
				fZec10[i] = (0.000740740739f * (0.0f - (10000.0f * (fYec0[(i - 1)] + (fYec0[i] + fRec13[(i - 1)])))));
				fZec11[i] = (25.3999996f * std::fabs(fZec10[i]));
				iZec12[i] = int(fZec11[i]);
				fZec13[i] = float(iZec12[i]);
				fRec13[i] = (fRec13[(i - 1)] + (0.135000005f * ((fZec5[i] * float(((fZec10[i] < 0.0f)?-1:1))) * std::fabs(((ftbl1mydspSIG1[std::min<int>(iZec12[i], 127)] * (fZec13[i] + (1.0f - fZec11[i]))) + ((fZec11[i] - fZec13[i]) * ftbl1mydspSIG1[std::min<int>((iZec12[i] + 1), 127)]))))));
				fYec1[i] = (fZec6[i] + (fZec9[i] + (fRec13[i] + fZec8[i])));
				fZec14[i] = (0.000740740739f * (0.0f - (10000.0f * (fYec1[(i - 1)] + (fYec1[i] + fRec16[(i - 1)])))));
				fZec15[i] = (25.3999996f * std::fabs(fZec14[i]));
				iZec16[i] = int(fZec15[i]);
				fZec17[i] = float(iZec16[i]);
				fRec16[i] = (fRec16[(i - 1)] + (0.135000005f * ((fZec5[i] * float(((fZec14[i] < 0.0f)?-1:1))) * std::fabs(((ftbl1mydspSIG1[std::min<int>(iZec16[i], 127)] * (fZec17[i] + (1.0f - fZec15[i]))) + ((fZec15[i] - fZec17[i]) * ftbl1mydspSIG1[std::min<int>((iZec16[i] + 1), 127)]))))));
				fZec18[i] = (fRec13[i] + fRec16[i]);
				fYec2[i] = (fZec6[i] + (fZec9[i] + (fZec8[i] + fZec18[i])));
				fZec19[i] = (0.000740740739f * (0.0f - (10000.0f * (fYec2[(i - 1)] + (fYec2[i] + fRec12[(i - 1)])))));
				fZec20[i] = (25.3999996f * std::fabs(fZec19[i]));
				iZec21[i] = int(fZec20[i]);
				fZec22[i] = float(iZec21[i]);
				fRec12[i] = (fRec12[(i - 1)] + (0.135000005f * ((fZec5[i] * float(((fZec19[i] < 0.0f)?-1:1))) * std::fabs(((ftbl1mydspSIG1[std::min<int>(iZec21[i], 127)] * (fZec22[i] + (1.0f - fZec20[i]))) + ((fZec20[i] - fZec22[i]) * ftbl1mydspSIG1[std::min<int>((iZec21[i] + 1), 127)]))))));
				fZec23[i] = (fRec12[i] + fZec18[i]);
				fYec3[i] = (fZec6[i] + (fZec9[i] + (fZec8[i] + fZec23[i])));
				fZec24[i] = (0.000740740739f * (0.0f - (10000.0f * (fYec3[(i - 1)] + (fYec3[i] + fRec7[(i - 1)])))));
				fZec25[i] = (25.3999996f * std::fabs(fZec24[i]));
				iZec26[i] = int(fZec25[i]);
				fZec27[i] = float(iZec26[i]);
				fRec7[i] = (fRec7[(i - 1)] + (0.135000005f * ((fZec5[i] * float(((fZec24[i] < 0.0f)?-1:1))) * std::fabs(((ftbl1mydspSIG1[std::min<int>(iZec26[i], 127)] * (fZec27[i] + (1.0f - fZec25[i]))) + ((fZec25[i] - fZec27[i]) * ftbl1mydspSIG1[std::min<int>((iZec26[i] + 1), 127)]))))));
				fRec1[i] = (fZec6[i] + (fZec9[i] + (fZec8[i] + (fRec7[i] + fZec23[i]))));
				
			}
			/* Post code */
			for (int j33 = 0; (j33 < 4); j33 = (j33 + 1)) {
				fYec3_perm[j33] = fYec3_tmp[(vsize + j33)];
				
			}
			for (int j29 = 0; (j29 < 4); j29 = (j29 + 1)) {
				fYec2_perm[j29] = fYec2_tmp[(vsize + j29)];
				
			}
			for (int j25 = 0; (j25 < 4); j25 = (j25 + 1)) {
				fYec1_perm[j25] = fYec1_tmp[(vsize + j25)];
				
			}
			for (int j27 = 0; (j27 < 4); j27 = (j27 + 1)) {
				fRec16_perm[j27] = fRec16_tmp[(vsize + j27)];
				
			}
			for (int j21 = 0; (j21 < 4); j21 = (j21 + 1)) {
				fYec0_perm[j21] = fYec0_tmp[(vsize + j21)];
				
			}
			for (int j23 = 0; (j23 < 4); j23 = (j23 + 1)) {
				fRec13_perm[j23] = fRec13_tmp[(vsize + j23)];
				
			}
			for (int j31 = 0; (j31 < 4); j31 = (j31 + 1)) {
				fRec12_perm[j31] = fRec12_tmp[(vsize + j31)];
				
			}
			for (int j35 = 0; (j35 < 4); j35 = (j35 + 1)) {
				fRec7_perm[j35] = fRec7_tmp[(vsize + j35)];
				
			}
			for (int j11 = 0; (j11 < 4); j11 = (j11 + 1)) {
				fRec5_perm[j11] = fRec5_tmp[(vsize + j11)];
				
			}
			for (int j37 = 0; (j37 < 4); j37 = (j37 + 1)) {
				fRec1_perm[j37] = fRec1_tmp[(vsize + j37)];
				
			}
			/* Recursive loop 18 */
			/* Pre code */
			for (int j38 = 0; (j38 < 4); j38 = (j38 + 1)) {
				fRec17_tmp[j38] = fRec17_perm[j38];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec17[i] = (fSlow8 + (fConst1 * fRec17[(i - 1)]));
				
			}
			/* Post code */
			for (int j39 = 0; (j39 < 4); j39 = (j39 + 1)) {
				fRec17_perm[j39] = fRec17_tmp[(vsize + j39)];
				
			}
			/* Recursive loop 19 */
			/* Pre code */
			for (int j40 = 0; (j40 < 4); j40 = (j40 + 1)) {
				fRec18_tmp[j40] = fRec18_perm[j40];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec18[i] = (fSlow9 + (fConst1 * fRec18[(i - 1)]));
				
			}
			/* Post code */
			for (int j41 = 0; (j41 < 4); j41 = (j41 + 1)) {
				fRec18_perm[j41] = fRec18_tmp[(vsize + j41)];
				
			}
			/* Vectorizable loop 20 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				output0[i] = FAUSTFLOAT(((fRec0[i] * float(input0[i])) + ((1.0f - fRec0[i]) * ((fRec1[i] * fRec17[i]) + (fRec18[i] * float(input0[i]))))));
				
			}
			
		}
		/* Remaining frames */
		if (vindex < count) {
			FAUSTFLOAT* input0 = &input0_ptr[vindex];
			FAUSTFLOAT* output0 = &output0_ptr[vindex];
			int vsize = (count - vindex);
			/* Recursive loop 0 */
			/* Pre code */
			for (int j16 = 0; (j16 < 4); j16 = (j16 + 1)) {
				fRec11_tmp[j16] = fRec11_perm[j16];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec11[i] = (fSlow6 + (fConst1 * fRec11[(i - 1)]));
				
			}
			/* Post code */
			for (int j17 = 0; (j17 < 4); j17 = (j17 + 1)) {
				fRec11_perm[j17] = fRec11_tmp[(vsize + j17)];
				
			}
			/* Recursive loop 1 */
			/* Pre code */
			for (int j18 = 0; (j18 < 4); j18 = (j18 + 1)) {
				fRec10_tmp[j18] = fRec10_perm[j18];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec1[i] = (fRec10[(i - 1)] + (fConst5 * fRec11[(i - 1)]));
				fRec10[i] = (fZec1[i] - std::floor(fZec1[i]));
				
			}
			/* Post code */
			for (int j19 = 0; (j19 < 4); j19 = (j19 + 1)) {
				fRec10_perm[j19] = fRec10_tmp[(vsize + j19)];
				
			}
			/* Vectorizable loop 2 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec2[i] = (128.0f * fRec10[i]);
				
			}
			/* Recursive loop 3 */
			/* Pre code */
			for (int j8 = 0; (j8 < 4); j8 = (j8 + 1)) {
				fRec6_tmp[j8] = fRec6_perm[j8];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec6[i] = (fSlow3 + (fConst1 * fRec6[(i - 1)]));
				
			}
			/* Post code */
			for (int j9 = 0; (j9 < 4); j9 = (j9 + 1)) {
				fRec6_perm[j9] = fRec6_tmp[(vsize + j9)];
				
			}
			/* Vectorizable loop 4 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				iZec3[i] = int(fZec2[i]);
				
			}
			/* Recursive loop 5 */
			/* Pre code */
			for (int j2 = 0; (j2 < 4); j2 = (j2 + 1)) {
				fRec2_tmp[j2] = fRec2_perm[j2];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec2[i] = ((fConst3 * fRec2[(i - 1)]) + float(input0[i]));
				
			}
			/* Post code */
			for (int j3 = 0; (j3 < 4); j3 = (j3 + 1)) {
				fRec2_perm[j3] = fRec2_tmp[(vsize + j3)];
				
			}
			/* Recursive loop 6 */
			/* Pre code */
			for (int j4 = 0; (j4 < 4); j4 = (j4 + 1)) {
				fRec4_tmp[j4] = fRec4_perm[j4];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec4[i] = (fSlow1 + (fConst1 * fRec4[(i - 1)]));
				
			}
			/* Post code */
			for (int j5 = 0; (j5 < 4); j5 = (j5 + 1)) {
				fRec4_perm[j5] = fRec4_tmp[(vsize + j5)];
				
			}
			/* Vectorizable loop 7 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec0[i] = std::exp((fConst5 * (0.0f - (6.28318548f * fRec6[i]))));
				
			}
			/* Recursive loop 8 */
			/* Pre code */
			for (int j12 = 0; (j12 < 4); j12 = (j12 + 1)) {
				fRec8_tmp[j12] = fRec8_perm[j12];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec8[i] = ((fConst1 * fRec8[(i - 1)]) + fSlow4);
				
			}
			/* Post code */
			for (int j13 = 0; (j13 < 4); j13 = (j13 + 1)) {
				fRec8_perm[j13] = fRec8_tmp[(vsize + j13)];
				
			}
			/* Recursive loop 9 */
			/* Pre code */
			for (int j14 = 0; (j14 < 4); j14 = (j14 + 1)) {
				fRec9_tmp[j14] = fRec9_perm[j14];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec9[i] = ((fConst1 * fRec9[(i - 1)]) + fSlow5);
				
			}
			/* Post code */
			for (int j15 = 0; (j15 < 4); j15 = (j15 + 1)) {
				fRec9_perm[j15] = fRec9_tmp[(vsize + j15)];
				
			}
			/* Vectorizable loop 10 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec4[i] = float(iZec3[i]);
				
			}
			/* Recursive loop 11 */
			/* Pre code */
			for (int j6 = 0; (j6 < 4); j6 = (j6 + 1)) {
				fRec3_tmp[j6] = fRec3_perm[j6];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec3[i] = ((fConst1 * fRec3[(i - 1)]) + (fConst2 * (iSlow2?fRec4[i]:(0.100000001f * fRec4[i]))));
				
			}
			/* Post code */
			for (int j7 = 0; (j7 < 4); j7 = (j7 + 1)) {
				fRec3_perm[j7] = fRec3_tmp[(vsize + j7)];
				
			}
			/* Vectorizable loop 12 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec5[i] = (1.0f - std::exp((fConst6 * std::pow(2.0f, (0.0833333358f * ((fRec8[i] + ((fRec9[i] - fRec8[i]) * ((ftbl0mydspSIG0[iZec3[i]] * (fZec4[i] + (1.0f - fZec2[i]))) + ((fZec2[i] - fZec4[i]) * ftbl0mydspSIG0[((iZec3[i] + 1) % 128)])))) + -69.0f))))));
				
			}
			/* Vectorizable loop 13 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec6[i] = (fConst8 * fRec2[(i - 1)]);
				
			}
			/* Vectorizable loop 14 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec7[i] = (fZec0[i] + 1.0f);
				
			}
			/* Vectorizable loop 15 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec9[i] = (fConst7 * fRec2[i]);
				
			}
			/* Recursive loop 16 */
			/* Pre code */
			for (int j0 = 0; (j0 < 4); j0 = (j0 + 1)) {
				fRec0_tmp[j0] = fRec0_perm[j0];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec0[i] = (fSlow0 + (fConst1 * fRec0[(i - 1)]));
				
			}
			/* Post code */
			for (int j1 = 0; (j1 < 4); j1 = (j1 + 1)) {
				fRec0_perm[j1] = fRec0_tmp[(vsize + j1)];
				
			}
			/* Recursive loop 17 */
			/* Pre code */
			for (int j10 = 0; (j10 < 4); j10 = (j10 + 1)) {
				fRec5_tmp[j10] = fRec5_perm[j10];
				
			}
			for (int j20 = 0; (j20 < 4); j20 = (j20 + 1)) {
				fYec0_tmp[j20] = fYec0_perm[j20];
				
			}
			for (int j22 = 0; (j22 < 4); j22 = (j22 + 1)) {
				fRec13_tmp[j22] = fRec13_perm[j22];
				
			}
			for (int j24 = 0; (j24 < 4); j24 = (j24 + 1)) {
				fYec1_tmp[j24] = fYec1_perm[j24];
				
			}
			for (int j26 = 0; (j26 < 4); j26 = (j26 + 1)) {
				fRec16_tmp[j26] = fRec16_perm[j26];
				
			}
			for (int j28 = 0; (j28 < 4); j28 = (j28 + 1)) {
				fYec2_tmp[j28] = fYec2_perm[j28];
				
			}
			for (int j30 = 0; (j30 < 4); j30 = (j30 + 1)) {
				fRec12_tmp[j30] = fRec12_perm[j30];
				
			}
			for (int j32 = 0; (j32 < 4); j32 = (j32 + 1)) {
				fYec3_tmp[j32] = fYec3_perm[j32];
				
			}
			for (int j34 = 0; (j34 < 4); j34 = (j34 + 1)) {
				fRec7_tmp[j34] = fRec7_perm[j34];
				
			}
			for (int j36 = 0; (j36 < 4); j36 = (j36 + 1)) {
				fRec1_tmp[j36] = fRec1_perm[j36];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec5[i] = (fRec1[(i - 1)] + (fRec5[(i - 1)] * fZec0[i]));
				fZec8[i] = (fRec3[i] * ((0.5f * (fRec5[i] * fZec7[i])) + (fRec5[(i - 1)] * (0.0f - (0.5f * fZec7[i])))));
				fYec0[i] = (fZec6[i] + (fZec8[i] + fZec9[i]));
				fZec10[i] = (0.000740740739f * (0.0f - (10000.0f * (fYec0[(i - 1)] + (fYec0[i] + fRec13[(i - 1)])))));
				fZec11[i] = (25.3999996f * std::fabs(fZec10[i]));
				iZec12[i] = int(fZec11[i]);
				fZec13[i] = float(iZec12[i]);
				fRec13[i] = (fRec13[(i - 1)] + (0.135000005f * ((fZec5[i] * float(((fZec10[i] < 0.0f)?-1:1))) * std::fabs(((ftbl1mydspSIG1[std::min<int>(iZec12[i], 127)] * (fZec13[i] + (1.0f - fZec11[i]))) + ((fZec11[i] - fZec13[i]) * ftbl1mydspSIG1[std::min<int>((iZec12[i] + 1), 127)]))))));
				fYec1[i] = (fZec6[i] + (fZec9[i] + (fRec13[i] + fZec8[i])));
				fZec14[i] = (0.000740740739f * (0.0f - (10000.0f * (fYec1[(i - 1)] + (fYec1[i] + fRec16[(i - 1)])))));
				fZec15[i] = (25.3999996f * std::fabs(fZec14[i]));
				iZec16[i] = int(fZec15[i]);
				fZec17[i] = float(iZec16[i]);
				fRec16[i] = (fRec16[(i - 1)] + (0.135000005f * ((fZec5[i] * float(((fZec14[i] < 0.0f)?-1:1))) * std::fabs(((ftbl1mydspSIG1[std::min<int>(iZec16[i], 127)] * (fZec17[i] + (1.0f - fZec15[i]))) + ((fZec15[i] - fZec17[i]) * ftbl1mydspSIG1[std::min<int>((iZec16[i] + 1), 127)]))))));
				fZec18[i] = (fRec13[i] + fRec16[i]);
				fYec2[i] = (fZec6[i] + (fZec9[i] + (fZec8[i] + fZec18[i])));
				fZec19[i] = (0.000740740739f * (0.0f - (10000.0f * (fYec2[(i - 1)] + (fYec2[i] + fRec12[(i - 1)])))));
				fZec20[i] = (25.3999996f * std::fabs(fZec19[i]));
				iZec21[i] = int(fZec20[i]);
				fZec22[i] = float(iZec21[i]);
				fRec12[i] = (fRec12[(i - 1)] + (0.135000005f * ((fZec5[i] * float(((fZec19[i] < 0.0f)?-1:1))) * std::fabs(((ftbl1mydspSIG1[std::min<int>(iZec21[i], 127)] * (fZec22[i] + (1.0f - fZec20[i]))) + ((fZec20[i] - fZec22[i]) * ftbl1mydspSIG1[std::min<int>((iZec21[i] + 1), 127)]))))));
				fZec23[i] = (fRec12[i] + fZec18[i]);
				fYec3[i] = (fZec6[i] + (fZec9[i] + (fZec8[i] + fZec23[i])));
				fZec24[i] = (0.000740740739f * (0.0f - (10000.0f * (fYec3[(i - 1)] + (fYec3[i] + fRec7[(i - 1)])))));
				fZec25[i] = (25.3999996f * std::fabs(fZec24[i]));
				iZec26[i] = int(fZec25[i]);
				fZec27[i] = float(iZec26[i]);
				fRec7[i] = (fRec7[(i - 1)] + (0.135000005f * ((fZec5[i] * float(((fZec24[i] < 0.0f)?-1:1))) * std::fabs(((ftbl1mydspSIG1[std::min<int>(iZec26[i], 127)] * (fZec27[i] + (1.0f - fZec25[i]))) + ((fZec25[i] - fZec27[i]) * ftbl1mydspSIG1[std::min<int>((iZec26[i] + 1), 127)]))))));
				fRec1[i] = (fZec6[i] + (fZec9[i] + (fZec8[i] + (fRec7[i] + fZec23[i]))));
				
			}
			/* Post code */
			for (int j33 = 0; (j33 < 4); j33 = (j33 + 1)) {
				fYec3_perm[j33] = fYec3_tmp[(vsize + j33)];
				
			}
			for (int j29 = 0; (j29 < 4); j29 = (j29 + 1)) {
				fYec2_perm[j29] = fYec2_tmp[(vsize + j29)];
				
			}
			for (int j25 = 0; (j25 < 4); j25 = (j25 + 1)) {
				fYec1_perm[j25] = fYec1_tmp[(vsize + j25)];
				
			}
			for (int j27 = 0; (j27 < 4); j27 = (j27 + 1)) {
				fRec16_perm[j27] = fRec16_tmp[(vsize + j27)];
				
			}
			for (int j21 = 0; (j21 < 4); j21 = (j21 + 1)) {
				fYec0_perm[j21] = fYec0_tmp[(vsize + j21)];
				
			}
			for (int j23 = 0; (j23 < 4); j23 = (j23 + 1)) {
				fRec13_perm[j23] = fRec13_tmp[(vsize + j23)];
				
			}
			for (int j31 = 0; (j31 < 4); j31 = (j31 + 1)) {
				fRec12_perm[j31] = fRec12_tmp[(vsize + j31)];
				
			}
			for (int j35 = 0; (j35 < 4); j35 = (j35 + 1)) {
				fRec7_perm[j35] = fRec7_tmp[(vsize + j35)];
				
			}
			for (int j11 = 0; (j11 < 4); j11 = (j11 + 1)) {
				fRec5_perm[j11] = fRec5_tmp[(vsize + j11)];
				
			}
			for (int j37 = 0; (j37 < 4); j37 = (j37 + 1)) {
				fRec1_perm[j37] = fRec1_tmp[(vsize + j37)];
				
			}
			/* Recursive loop 18 */
			/* Pre code */
			for (int j38 = 0; (j38 < 4); j38 = (j38 + 1)) {
				fRec17_tmp[j38] = fRec17_perm[j38];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec17[i] = (fSlow8 + (fConst1 * fRec17[(i - 1)]));
				
			}
			/* Post code */
			for (int j39 = 0; (j39 < 4); j39 = (j39 + 1)) {
				fRec17_perm[j39] = fRec17_tmp[(vsize + j39)];
				
			}
			/* Recursive loop 19 */
			/* Pre code */
			for (int j40 = 0; (j40 < 4); j40 = (j40 + 1)) {
				fRec18_tmp[j40] = fRec18_perm[j40];
				
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec18[i] = (fSlow9 + (fConst1 * fRec18[(i - 1)]));
				
			}
			/* Post code */
			for (int j41 = 0; (j41 < 4); j41 = (j41 + 1)) {
				fRec18_perm[j41] = fRec18_tmp[(vsize + j41)];
				
			}
			/* Vectorizable loop 20 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				output0[i] = FAUSTFLOAT(((fRec0[i] * float(input0[i])) + ((1.0f - fRec0[i]) * ((fRec1[i] * fRec17[i]) + (fRec18[i] * float(input0[i]))))));
				
			}
			
		}
		
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif


//------------------------------------------------------------------------------
// End the Faust code section

StonePhaserDsp::StonePhaserDsp()
    : fDsp(new mydsp)
{
    fDsp->instanceResetUserInterface();
}

StonePhaserDsp::~StonePhaserDsp()
{
    delete fDsp;
}

void StonePhaserDsp::init(float sample_rate)
{
    mydsp &dsp = *fDsp;
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    dsp.instanceClear();
}

void StonePhaserDsp::clear() noexcept
{
    fDsp->instanceClear();
}

void StonePhaserDsp::process(
    const float *in0,
    float *out0,
    unsigned count) noexcept
{
    float *inputs[] = {
        const_cast<float *>(in0),
    };
    float *outputs[] = {
        out0,
    };
    fDsp->compute(count, inputs, outputs);
}

const char *StonePhaserDsp::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Bypass";
    
    case 1:
        return "Color";
    
    case 2:
        return "LFO frequency";
    
    case 3:
        return "Feedback depth";
    
    case 4:
        return "Feedback bass cut";
    
    case 5:
        return "Dry/wet mix";
    
    default:
        return 0;
    }
}

const char *StonePhaserDsp::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    case 3:
        return "";
    
    case 4:
        return "Fb bass cut";
    
    case 5:
        return "";
    
    default:
        return 0;
    }
}

const char *StonePhaserDsp::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "bypass";
    
    case 1:
        return "color";
    
    case 2:
        return "lfo_frequency";
    
    case 3:
        return "feedback_depth";
    
    case 4:
        return "feedback_hpf_cutoff";
    
    case 5:
        return "mix";
    
    default:
        return 0;
    }
}

const char *StonePhaserDsp::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "Hz";
    
    case 3:
        return "%";
    
    case 4:
        return "Hz";
    
    case 5:
        return "%";
    
    default:
        return 0;
    }
}

const StonePhaserDsp::ParameterRange *StonePhaserDsp::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 0.0, 0.0, 1.0 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { 1.0, 0.0, 1.0 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 0.20000000298023224, 0.009999999776482582, 5.0 };
        return &range;
    }
    
    case 3: {
        static const ParameterRange range = { 75.0, 0.0, 99.0 };
        return &range;
    }
    
    case 4: {
        static const ParameterRange range = { 500.0, 10.0, 5000.0 };
        return &range;
    }
    
    case 5: {
        static const ParameterRange range = { 50.0, 0.0, 100.0 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool StonePhaserDsp::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool StonePhaserDsp::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return true;
    
    case 1:
        return true;
    
    default:
        return false;
    }
}

bool StonePhaserDsp::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return true;
    
    case 1:
        return true;
    
    case 3:
        return true;
    
    case 5:
        return true;
    
    default:
        return false;
    }
}

bool StonePhaserDsp::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    case 2:
        return true;
    
    case 4:
        return true;
    
    default:
        return false;
    }
}

float StonePhaserDsp::get_parameter(unsigned index) const noexcept
{
    switch (index) {
    
    case 0:
        return fDsp->fCheckbox0;
    
    case 1:
        return fDsp->fHslider1;
    
    case 2:
        return fDsp->fHslider3;
    
    case 3:
        return fDsp->fHslider0;
    
    case 4:
        return fDsp->fHslider2;
    
    case 5:
        return fDsp->fHslider4;
    
    default:
        return 0;
    }
}

void StonePhaserDsp::set_parameter(unsigned index, float value) noexcept
{
    switch (index) {
    
    case 0:
        fDsp->fCheckbox0 = value;
        break;
    
    case 1:
        fDsp->fHslider1 = value;
        break;
    
    case 2:
        fDsp->fHslider3 = value;
        break;
    
    case 3:
        fDsp->fHslider0 = value;
        break;
    
    case 4:
        fDsp->fHslider2 = value;
        break;
    
    case 5:
        fDsp->fHslider4 = value;
        break;
    
    default:
        break;
    }
}


float StonePhaserDsp::get_bypass() const noexcept
{
    return fDsp->fCheckbox0;
}

void StonePhaserDsp::set_bypass(float value) noexcept
{
    fDsp->fCheckbox0 = value;
}

float StonePhaserDsp::get_color() const noexcept
{
    return fDsp->fHslider1;
}

void StonePhaserDsp::set_color(float value) noexcept
{
    fDsp->fHslider1 = value;
}

float StonePhaserDsp::get_lfo_frequency() const noexcept
{
    return fDsp->fHslider3;
}

void StonePhaserDsp::set_lfo_frequency(float value) noexcept
{
    fDsp->fHslider3 = value;
}

float StonePhaserDsp::get_feedback_depth() const noexcept
{
    return fDsp->fHslider0;
}

void StonePhaserDsp::set_feedback_depth(float value) noexcept
{
    fDsp->fHslider0 = value;
}

float StonePhaserDsp::get_feedback_hpf_cutoff() const noexcept
{
    return fDsp->fHslider2;
}

void StonePhaserDsp::set_feedback_hpf_cutoff(float value) noexcept
{
    fDsp->fHslider2 = value;
}

float StonePhaserDsp::get_mix() const noexcept
{
    return fDsp->fHslider4;
}

void StonePhaserDsp::set_mix(float value) noexcept
{
    fDsp->fHslider4 = value;
}


#if __cplusplus >= 201103L
StonePhaserDsp::StonePhaserDsp(StonePhaserDsp &&other) noexcept
    : fDsp(other.fDsp)
{
    other.fDsp = 0;
}

StonePhaserDsp &StonePhaserDsp::operator=(StonePhaserDsp &&other) noexcept
{
    if (this != &other) {
        delete fDsp;
        fDsp = other.fDsp;
        other.fDsp = 0;
    }
    return *this;
}
#endif
