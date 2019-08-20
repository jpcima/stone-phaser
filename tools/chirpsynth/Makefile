CXX ?= g++
CXXFLAGS ?= -O2 -g
PKG_CONFIG ?= pkg-config

BUILD_CXX_FLAGS = $(CXXFLAGS) $(shell $(PKG_CONFIG) jack --cflags)
LINK_FLAGS = $(LDFLAGS) $(shell $(PKG_CONFIG) jack --libs)

all: bin/chirpsynth

bin/chirpsynth: build/chirpsynth.o
	@install -d $(dir $@)
	$(CXX) -o $@ $^ $(LINK_FLAGS)

build/chirpsynth.o: build/chirpsynth.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

build/chirpsynth.cpp: chirpsynth.dsp chirpsynth.cpp
	@install -d $(dir $@)
	faust -a chirpsynth.cpp chirpsynth.dsp > $@

clean:
	rm -rf bin build

.PHONY: all clean
