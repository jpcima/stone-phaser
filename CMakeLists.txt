cmake_minimum_required(VERSION 3.12)
project(stone-phaser)

add_subdirectory("dpf")

option(STONE_PHASER_BUILD_UI "Build plugin UI" ON)

if(STONE_PHASER_BUILD_UI)
  set(STONE_PHASER_UI_OPTIONS UI_TYPE "cairo")
else()
  set(STONE_PHASER_UI_OPTIONS)
endif()

#
dpf_add_plugin(stone-phaser
  ${STONE_PHASER_UI_OPTIONS}
  TARGETS lv2 vst2 ladspa
  FILES_DSP
    "plugins/stone-phaser/PhaserPlugin.cpp"
  FILES_UI
    "plugins/stone-phaser/PhaserUI.cpp"
    "plugins/stone-phaser/Artwork.cpp"
    "plugins/stone-phaser/ui/components/KnobSkin.cpp"
    "plugins/stone-phaser/ui/components/SkinIndicator.cpp"
    "plugins/stone-phaser/ui/components/SkinSlider.cpp"
    "plugins/stone-phaser/ui/components/SkinToggleButton.cpp"
    "plugins/stone-phaser/ui/FontEngine.cpp"
    "plugins/stone-phaser/ui/Fontstash.cpp"
    "plugins/stone-phaser/ui/Cairo++.cpp"
  FILES_COMMON
    "plugins/stone-phaser/PhaserShared.cpp"
    "plugins/stone-phaser/gen/StonePhaserDsp.cpp")

target_include_directories(stone-phaser
  PUBLIC
    "plugins/stone-phaser"
    "plugins/stone-phaser/meta"
    "plugins/stone-phaser/gen"
    "thirdparty/blink"
    "thirdparty/fontstash"
    "thirdparty/stb")

if(STONE_PHASER_BUILD_UI)
  target_compile_definitions(stone-phaser PUBLIC "DISTRHO_PLUGIN_HAS_UI=1")
endif()

if(MSVC)
  target_compile_options(stone-phaser PUBLIC "/fp:fast")
else()
  target_compile_options(stone-phaser PUBLIC "-ffast-math")
endif()

#
dpf_add_plugin(stone-phaser-stereo
  ${STONE_PHASER_UI_OPTIONS}
  TARGETS lv2 vst2 ladspa
  UI_TYPE "${STONE_PHASER_UI_TYPE}"
  FILES_DSP
    "plugins/stone-phaser-stereo/PhaserPlugin.cpp"
  FILES_UI
    "plugins/stone-phaser-stereo/PhaserUI.cpp"
    "plugins/stone-phaser-stereo/Artwork.cpp"
    "plugins/stone-phaser-stereo/ui/components/KnobSkin.cpp"
    "plugins/stone-phaser-stereo/ui/components/SkinIndicator.cpp"
    "plugins/stone-phaser-stereo/ui/components/SkinSlider.cpp"
    "plugins/stone-phaser-stereo/ui/components/SkinToggleButton.cpp"
    "plugins/stone-phaser-stereo/ui/FontEngine.cpp"
    "plugins/stone-phaser-stereo/ui/Fontstash.cpp"
    "plugins/stone-phaser-stereo/ui/Cairo++.cpp"
  FILES_COMMON
    "plugins/stone-phaser-stereo/PhaserShared.cpp"
    "plugins/stone-phaser-stereo/gen/StonePhaserDsp.cpp")

target_include_directories(stone-phaser-stereo
  PUBLIC
    "plugins/stone-phaser-stereo"
    "plugins/stone-phaser-stereo/meta"
    "plugins/stone-phaser-stereo/gen"
    "thirdparty/blink"
    "thirdparty/fontstash"
    "thirdparty/stb")

if(STONE_PHASER_BUILD_UI)
  target_compile_definitions(stone-phaser-stereo PUBLIC "DISTRHO_PLUGIN_HAS_UI=1")
endif()

if(MSVC)
  target_compile_options(stone-phaser-stereo PUBLIC "/fp:fast")
else()
  target_compile_options(stone-phaser-stereo PUBLIC "-ffast-math")
endif()
