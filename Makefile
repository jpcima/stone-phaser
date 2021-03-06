#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX, Christopher Arndt, and Patrick Desaulniers
#

PLUGINS := stone-phaser stone-phaser-stereo

# --------------------------------------------------------------

ifneq ($(shell test -f dpf/Makefile.base.mk && echo 1),1)
$(error DPF is missing, run "git submodule update --init")
endif

include dpf/Makefile.base.mk

all: libs plugins gen

# --------------------------------------------------------------

submodules:
	git submodule update --init --recursive

libs:

plugins: libs
	$(foreach p,$(PLUGINS),$(MAKE) all -C plugins/$(p);)

ifneq ($(CROSS_COMPILING),true)
gen: plugins dpf/utils/lv2_ttl_generator
	@$(CURDIR)/dpf/utils/generate-ttl.sh
ifeq ($(MACOS),true)
	@$(CURDIR)/dpf/utils/generate-vst-bundles.sh
endif

dpf/utils/lv2_ttl_generator:
	$(MAKE) -C dpf/utils/lv2-ttl-generator
else
gen:
endif

# --------------------------------------------------------------

BUILD_UI ?= true

ifeq ($(BUILD_UI),true)
plugins: dgl

dgl:
	$(MAKE) -C dpf/dgl ../build/libdgl-cairo.a

clean-dgl:
	$(MAKE) -C dpf/dgl clean

clean: clean-dgl
endif

# --------------------------------------------------------------

dsp:
	$(foreach p,$(PLUGINS),$(MAKE) dsp -C plugins/$(p);)

# --------------------------------------------------------------

artwork:
	$(MAKE) artwork -C plugins/stone-phaser

# --------------------------------------------------------------

clean:
	$(MAKE) clean -C dpf/utils/lv2-ttl-generator
	$(foreach p,$(PLUGINS),$(MAKE) clean -C plugins/$(p);)
	rm -rf bin build

install: all
	$(foreach p,$(PLUGINS),$(MAKE) install -C plugins/$(p);)

install-user: all
	$(foreach p,$(PLUGINS),$(MAKE) install-user -C plugins/$(p);)

# --------------------------------------------------------------

.PHONY: all submodule libs plugins gen dgl dsp artwork clean clean-dgl install install-user
