#include <cmath>
#include <cstdint>

template <class T> T min(T a, T b) { return (a < b) ? a : b; }
template <class T> T max(T a, T b) { return (a > b) ? a : b; }

class Meta {
public:
    void declare(...) {}
};

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

class dsp {
};

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#define virtual /* do not make methods virtual */

<<includeIntrinsic>>
<<includeclass>>

#undef virtual

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

//------------------------------------------------------------------------------

#include <jack/jack.h>
#include <unistd.h>
#include <cstdio>

static jack_client_t *client;
static jack_port_t *port_out;
static mydsp synth;

static int process(jack_nframes_t count, void *)
{
    float *outputs[] = {(float *)jack_port_get_buffer(port_out, count)};
    synth.compute(count, (float **)0, outputs);
    return 0;
}

int main()
{
    client = jack_client_open("Chirp synthesizer", JackNoStartServer, nullptr);
    if (!client) {
        fprintf(stderr, "Cannot open JACK client.\n");
        return 1;
    }

    port_out = jack_port_register(client, "out", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);
    if (!port_out) {
        fprintf(stderr, "Cannot register JACK ports.\n");
        return 1;
    }

    jack_set_process_callback(client, &process, (void *)0);

    synth.init(jack_get_sample_rate(client));

    if (jack_activate(client) != 0) {
        fprintf(stderr, "Cannot activate JACK client.\n");
        return 1;
    }

    for (;;)
        pause();

    return 0;
}
