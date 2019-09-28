# Stone phaser

[![Build Status](https://travis-ci.com/jpcima/stone-phaser.svg?branch=master)](https://travis-ci.com/jpcima/stone-phaser)

A classic analog phaser effect

This is an analog phaser with similarity to the Small Stone. It has a color switch, which makes the phasing stronger when on, and adds some feedback controls. A stereo variant of the phaser is included.

This effect is supported on [MOD devices](https://www.moddevices.com/).

![screenshot](modgui/stone-phaser/modgui/screenshot-stone-phaser.png)

## Downloads

**Stable**

- GNU/Linux: download packages from [Open Build Service](https://software.opensuse.org/download.html?project=home%3Ajpcima&package=stone-phaser).
- All: download from [Github releases](https://github.com/jpcima/stone-phaser/releases).

**Development**

- All: download from [Automatic builds](https://github.com/jpcima/stone-phaser/releases/tag/automatic).

## Build instructions

1. Obtain prerequisites

Install needed packages:

- `git`
- `build-essential`
- `pkg-config`
- `libx11-dev`
- `libcairo2-dev`
- `libjack-jackd2-dev` or `libjack-dev`
- `mesa-common-dev`

2. Check out the repository and submodules

```
git clone https://github.com/jpcima/stone-phaser.git
cd stone-phaser
git submodule update --init
```

3. Patch DPF

This recommended patch works around a current bug in LV2 graphical interfaces.

```
patch -d dpf -p 1 -i "`pwd`/resources/patch/DPF-bypass.patch"
```

4. Compile

```
make
```

5. Install

```
sudo make install  # to install in system directories, or
make install-user  # to install in the home directory
```

## Change log

**0.1.1**

- add the graphical user interface
- improve the integration of Faust source code

**0.1.0**

- initial software release
