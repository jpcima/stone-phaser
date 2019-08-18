#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX, Christopher Arndt, and Patrick Desaulniers
#

# --------------------------------------------------------------
# Installation directories

PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin
LIBDIR ?= $(PREFIX)/lib
DSSI_DIR ?= $(LIBDIR)/dssi
LADSPA_DIR ?= $(LIBDIR)/ladspa
LV2_DIR ?= $(LIBDIR)/lv2
VST_DIR ?= $(LIBDIR)/vst

# --------------------------------------------------------------
# Project name, used for binaries

NAME = stone-phaser-stereo

# --------------------------------------------------------------
# Plugin types to build

BUILD_LV2 ?= true
BUILD_VST2 ?= true
BUILD_JACK ?= false
BUILD_DSSI ?= false
BUILD_LADSPA ?= true

# --------------------------------------------------------------
# Files to build

FILES_DSP = \
	PhaserPlugin.cpp

# --------------------------------------------------------------
# Do some magic

include ../../dpf/Makefile.plugins.mk

BUILD_CXX_FLAGS += -Imeta

# --------------------------------------------------------------
# Enable all selected plugin types

ifeq ($(BUILD_LV2),true)
ifeq ($(HAVE_DGL),true)
TARGETS += lv2_sep
else
TARGETS += lv2_dsp
endif
endif

ifeq ($(BUILD_VST2),true)
TARGETS += vst
endif

ifeq ($(BUILD_JACK),true)
ifeq ($(HAVE_JACK),true)
TARGETS += jack
endif
endif

ifeq ($(BUILD_DSSI),true)
ifeq ($(HAVE_DGL),true)
ifeq ($(HAVE_LIBLO),true)
TARGETS += dssi
endif
endif
endif

ifeq ($(BUILD_LADSPA),true)
TARGETS += ladspa
endif

all: $(TARGETS)

install: all
ifeq ($(BUILD_DSSI),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-dssi$(LIB_EXT) -t $(DESTDIR)$(DSSI_DIR)
endif
ifeq ($(BUILD_LADSPA),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-ladspa$(LIB_EXT) -t $(DESTDIR)$(LADSPA_DIR)
endif
ifeq ($(BUILD_VST2),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-vst$(LIB_EXT) -t $(DESTDIR)$(VST_DIR)
endif
ifeq ($(BUILD_LV2),true)
	@install -dm755 $(DESTDIR)$(LV2_DIR) && \
		cp -rf $(TARGET_DIR)/$(NAME).lv2 $(DESTDIR)$(LV2_DIR)
endif
ifeq ($(BUILD_JACK),true)
ifeq ($(HAVE_JACK),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)$(APP_EXT) -t $(DESTDIR)$(BINDIR)
endif
endif

install-user: all
ifeq ($(BUILD_DSSI),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-dssi$(LIB_EXT) -t $(HOME)/.dssi
endif
ifeq ($(BUILD_LADSPA),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-ladspa$(LIB_EXT) -t $(HOME)/.ladspa
endif
ifeq ($(BUILD_VST2),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-vst$(LIB_EXT) -t $(HOME)/.vst
endif
ifeq ($(BUILD_LV2),true)
	@install -dm755 $(HOME)/.lv2 && \
		cp -rf $(TARGET_DIR)/$(NAME).lv2 $(HOME)/.lv2
endif
ifeq ($(BUILD_JACK),true)
ifeq ($(HAVE_JACK),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)$(APP_EXT) -t $(HOME)/bin
endif
endif

# --------------------------------------------------------------
FAUST ?= faust
FAUSTMD ?= faustmd

FAUST_FLAGS = -uim -vec
FAUSTMD_FLAGS = $(patsubst %,-X%,$(FAUST_FLAGS))

dsp:
	faust $(FAUST_FLAGS) -a ../../dsp/architecture.cpp ../../dsp/stone_phaser_stereo.dsp > StonePhaserDsp.cpp
	faustmd $(FAUSTMD_FLAGS) ../../dsp/stone_phaser_stereo.dsp >> StonePhaserDsp.cpp
	cat ../../dsp/footer.cpp >> StonePhaserDsp.cpp

# --------------------------------------------------------------

.PHONY: all install install-user dsp
