#!/bin/bash

# ---------------------------------------------------------------------------------------------------------------------
# stop on error

set -e

# ---------------------------------------------------------------------------------------------------------------------
# print shell commands

set -x

# ---------------------------------------------------------------------------------------------------------------------
# set variables

test ! -z "$_MINGW"
test ! -z "$_HOST"

# ---------------------------------------------------------------------------------------------------------------------
# setup

export AR="$_HOST"-ar
export RANLIB="$_HOST"-ranlib
export CC="$_HOST"-gcc
export CXX="$_HOST"-g++
export STRIP="$_HOST"-strip
export WINDRES="$_HOST"-windres
export PKG_CONFIG="$_HOST"-pkg-config

export PKG_CONFIG="$PKG_CONFIG --static"

export PATH=/opt/"$_MINGW"/"$_HOST"/bin:/opt/"$_MINGW"/bin:"$PATH"

export CPPFLAGS="-I/opt/$_MINGW/include"
export CFLAGS="-O2 $CPPFLAGS"
export CXXFLAGS="-O2 $CPPFLAGS"
export LDFLAGS="-L/opt/$_MINGW/lib"

# ---------------------------------------------------------------------------------------------------------------------
# build dependencies

ZLIB_VERSION=1.2.11
ZLIB_BUILD=1

LIBPNG_VERSION=1.6.37
LIBPNG_BUILD=1

CAIRO_VERSION=1.17.2
CAIRO_BUILD=1

mkdir -p build-cache

if test ! -f build-cache/zlib-"$ZLIB_VERSION"-"$ZLIB_BUILD"-"$_HOST".tar.gz; then
    wget https://www.zlib.net/zlib-"$ZLIB_VERSION".tar.gz
    tar -x -z -f zlib-"$ZLIB_VERSION".tar.gz
    cd zlib-"$ZLIB_VERSION"
    ./configure --prefix=/opt/"$_MINGW"/"$_HOST" --static
    make -f win32/Makefile.gcc CC="$_HOST"-gcc AR="$_HOST"-ar RC="$_HOST"-windres STRIP="$_HOST"-strip CFLAGS="$CFLAGS"
    sed "s,@prefix@,/opt/$_MINGW/$_HOST,;s,@exec_prefix@,\${prefix},;s,@libdir@,\${exec_prefix}/lib,;s,@sharedlibdir@,\${libdir},;s,@includedir@,\${prefix}/include,;s,@VERSION@,$pkgver," < zlib.pc.in > zlib.pc
    install -D -m 644 zlib.h install-target/opt/"$_MINGW"/"$_HOST"/include/zlib.h
    install -D -m 644 zconf.h install-target/opt/"$_MINGW"/"$_HOST"/include/zconf.h
    install -D -m 644 libz.a install-target/opt/"$_MINGW"/"$_HOST"/lib/libz.a
    install -D -m 644 zlib.pc install-target/opt/"$_MINGW"/"$_HOST"/lib/pkgconfig/zlib.pc
    fakeroot tar -c -z -f "$(pwd)"/../build-cache/zlib-"$ZLIB_VERSION"-"$ZLIB_BUILD"-"$_HOST".tar.gz -C install-target opt/"$_MINGW"/"$_HOST"
    cd ..
fi
sudo tar -x -z -f "$(pwd)"/build-cache/zlib-"$ZLIB_VERSION"-"$ZLIB_BUILD"-"$_HOST".tar.gz -C /

if test ! -f build-cache/libpng-"$LIBPNG_VERSION"-"$LIBPNG_BUILD"-"$_HOST".tar.gz; then
    wget http://downloads.sourceforge.net/sourceforge/libpng/libpng-"$LIBPNG_VERSION".tar.xz
    tar -x -J -f libpng-"$LIBPNG_VERSION".tar.xz
    cd libpng-"$LIBPNG_VERSION"
    ./configure --prefix=/opt/"$_MINGW"/"$_HOST" --disable-shared --enable-static
    make
    make install DESTDIR="$(pwd)"/install-target
    fakeroot tar -c -z -f "$(pwd)"/../build-cache/libpng-"$LIBPNG_VERSION"-"$LIBPNG_BUILD"-"$_HOST".tar.gz -C install-target opt/"$_MINGW"/"$_HOST"
    cd ..
fi
sudo tar -x -z -f "$(pwd)"/build-cache/libpng-"$LIBPNG_VERSION"-"$LIBPNG_BUILD"-"$_HOST".tar.gz -C /

if test ! -f build-cache/cairo-"$CAIRO_VERSION"-"$CAIRO_BUILD"-"$_HOST".tar.gz; then
    wget https://cairographics.org/snapshots/cairo-"$CAIRO_VERSION".tar.xz
    tar -x -J -f cairo-"$CAIRO_VERSION".tar.xz
    cd cairo-"$CAIRO_VERSION"
    ./configure --prefix=/opt/"$_MINGW"/"$_HOST" --disable-shared --enable-static
    make
    make install DESTDIR="$(pwd)"/install-target
    fakeroot tar -c -z -f "$(pwd)"/../build-cache/cairo-"$CAIRO_VERSION"-"$CAIRO_BUILD"-"$_HOST".tar.gz -C install-target opt/"$_MINGW"/"$_HOST"
    cd ..
fi
sudo tar -x -z -f "$(pwd)"/build-cache/cairo-"$CAIRO_VERSION"-"$CAIRO_BUILD"-"$_HOST".tar.gz -C /

# ---------------------------------------------------------------------------------------------------------------------
# prepare

# invoke the Windows ttl generator using wine
sed -i 's/"$GEN"/wine "$GEN"/g' dpf/utils/generate-ttl.sh

# ---------------------------------------------------------------------------------------------------------------------
# build the plugin

# TODO setup cairo UI build...
CROSS_COMPILING=true WINDOWS=true make $MAKE_ARGS
