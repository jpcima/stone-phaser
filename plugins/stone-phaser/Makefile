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
ifneq ($(MACOS_OR_WINDOWS),true)
LV2_DIR ?= $(LIBDIR)/lv2
VST_DIR ?= $(LIBDIR)/vst
endif
ifeq ($(MACOS),true)
LV2_DIR ?= /Library/Audio/Plug-Ins/LV2
VST_DIR ?= /Library/Audio/Plug-Ins/VST
endif
ifeq ($(WINDOWS),true)
LV2_DIR ?= $(COMMONPROGRAMFILES)/LV2
VST_DIR ?= $(COMMONPROGRAMFILES)/VST2
endif

USER_DSSI_DIR ?= $(HOME)/.dssi
USER_LADSPA_DIR ?= $(HOME)/.ladspa
ifneq ($(MACOS_OR_WINDOWS),true)
USER_LV2_DIR ?= $(HOME)/.lv2
USER_VST_DIR ?= $(HOME)/.vst
endif
ifeq ($(MACOS),true)
USER_LV2_DIR ?= $(HOME)/Library/Audio/Plug-Ins/LV2
USER_VST_DIR ?= $(HOME)/Library/Audio/Plug-Ins/VST
endif
ifeq ($(WINDOWS),true)
USER_LV2_DIR ?= $(APPDATA)/LV2
USER_VST_DIR ?= $(APPDATA)/VST
endif

# --------------------------------------------------------------
# Project name, used for binaries

NAME = stone-phaser

# --------------------------------------------------------------
# Plugin types to build

BUILD_LV2 ?= true
BUILD_VST2 ?= true
BUILD_JACK ?= false
BUILD_DSSI ?= false
BUILD_LADSPA ?= true

# --------------------------------------------------------------
# Type of user interface

BUILD_UI ?= true
ifeq ($(BUILD_UI),true)
UI_TYPE = cairo
else
UI_TYPE = none
endif

# --------------------------------------------------------------
# Files to build

FILES_DSP = \
	PhaserPlugin.cpp \
	$(FILES_SHARED)

ifeq ($(BUILD_UI),true)
FILES_UI = \
	PhaserUI.cpp \
	Artwork.cpp \
	ui/components/KnobSkin.cpp \
	ui/components/SkinIndicator.cpp \
	ui/components/SkinSlider.cpp \
	ui/components/SkinToggleButton.cpp \
	ui/FontEngine.cpp \
	ui/Fontstash.cpp \
	ui/Cairo++.cpp \
	$(FILES_SHARED)
endif

FILES_SHARED = \
	PhaserShared.cpp \
	gen/StonePhaserDsp.cpp

# --------------------------------------------------------------
# Do some magic

include ../../dpf/Makefile.plugins.mk

BUILD_CXX_FLAGS += -Imeta
BUILD_CXX_FLAGS += -Igen
BUILD_CXX_FLAGS += -Ithirdparty/blink
BUILD_CXX_FLAGS += -Ithirdparty/fontstash
BUILD_CXX_FLAGS += -Ithirdparty/stb

ifeq ($(BUILD_UI),true)
BUILD_CXX_FLAGS += -DDISTRHO_PLUGIN_HAS_UI=1
endif

# --------------------------------------------------------------
# Enable all selected plugin types

ifeq ($(BUILD_LV2),true)
ifeq ($(BUILD_UI),true)
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
ifneq ($(MACOS_OR_WINDOWS),true)
ifeq ($(BUILD_UI),true)
ifeq ($(HAVE_LIBLO),true)
TARGETS += dssi
endif
endif
endif
endif

ifeq ($(BUILD_LADSPA),true)
TARGETS += ladspa
endif

all: $(TARGETS)

install: all
ifeq ($(BUILD_DSSI),true)
ifneq ($(MACOS_OR_WINDOWS),true)
ifeq ($(BUILD_UI),true)
ifeq ($(HAVE_LIBLO),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-dssi$(LIB_EXT) $(DESTDIR)$(DSSI_DIR)/$(NAME)-dssi$(LIB_EXT)
endif
endif
endif
endif
ifeq ($(BUILD_LADSPA),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-ladspa$(LIB_EXT) $(DESTDIR)$(LADSPA_DIR)/$(NAME)-ladspa$(LIB_EXT)
endif
ifeq ($(BUILD_VST2),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-vst$(LIB_EXT) $(DESTDIR)$(VST_DIR)/$(NAME)-vst$(LIB_EXT)
endif
ifeq ($(BUILD_LV2),true)
	@install -dm755 $(DESTDIR)$(LV2_DIR) && \
		cp -rfd $(TARGET_DIR)/$(NAME).lv2 $(DESTDIR)$(LV2_DIR)
endif
ifeq ($(BUILD_JACK),true)
ifeq ($(HAVE_JACK),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)$(APP_EXT) $(DESTDIR)$(BINDIR)/$(NAME)$(APP_EXT)
endif
endif

install-user: all
ifeq ($(BUILD_DSSI),true)
ifneq ($(MACOS_OR_WINDOWS),true)
ifeq ($(BUILD_UI),true)
ifeq ($(HAVE_LIBLO),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-dssi$(LIB_EXT) $(USER_DSSI_DIR)/$(NAME)-dssi$(LIB_EXT)
endif
endif
endif
endif
ifeq ($(BUILD_LADSPA),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-ladspa$(LIB_EXT) $(USER_LADSPA_DIR)/$(NAME)-ladspa$(LIB_EXT)
endif
ifeq ($(BUILD_VST2),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)-vst$(LIB_EXT) $(USER_VST_DIR)/$(NAME)-vst$(LIB_EXT)
endif
ifeq ($(BUILD_LV2),true)
	@install -dm755 $(USER_LV2_DIR) && \
		cp -rfd $(TARGET_DIR)/$(NAME).lv2 $(USER_LV2_DIR)
endif
ifeq ($(BUILD_JACK),true)
ifeq ($(HAVE_JACK),true)
	@install -Dm755 $(TARGET_DIR)/$(NAME)$(APP_EXT) $(HOME)/bin/$(NAME)$(APP_EXT)
endif
endif

# --------------------------------------------------------------
FAUSTPP ?= faustpp
FAUSTPP_FLAGS = -X-vec

dsp:
	@install -d gen
	$(FAUSTPP) $(FAUSTPP_FLAGS) -a ../../dsp/architecture.cpp -DIdentifier=StonePhaserDsp ../../dsp/stone_phaser.dsp > gen/StonePhaserDsp.cpp
	$(FAUSTPP) $(FAUSTPP_FLAGS) -a ../../dsp/architecture.hpp -DIdentifier=StonePhaserDsp ../../dsp/stone_phaser.dsp > gen/StonePhaserDsp.hpp

# --------------------------------------------------------------

artwork:
	python ../../dpf/utils/res2c.py Artwork artwork

# --------------------------------------------------------------

all: copy-modgui

copy-modgui:
	@install -d $(TARGET_DIR)/$(NAME).lv2
	cp -f ../../modgui/$(NAME)/modgui.ttl $(TARGET_DIR)/$(NAME).lv2
	cp -rf ../../modgui/$(NAME)/modgui $(TARGET_DIR)/$(NAME).lv2

# --------------------------------------------------------------

.PHONY: all install install-user dsp artwork copy-modgui
