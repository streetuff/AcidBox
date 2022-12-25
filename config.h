#define PROG_NAME       "ESP32 AcidBox"
#define VERSION         "v0.6"

//#define DEBUG_ON            // note that debugging eats ticks initially belonging to real-time tasks, so sound output will be spoild in most cases, turn it of for production
//#define DEBUG_MASTER_OUT    // serial monitor plotter will draw the output waveform
//#define DEBUG_SAMPLER

#define MIDI_ON             // use this option if you want to operate by MIDI
//#define MIDI_VIA_SERIAL     // use this option together with MIDI_ON for Hairless MIDI style, this will block Serial debugging as well
#define JUKEBOX               // not working with MIDI_ON yet

#define MAX_CUTOFF_FREQ 3000.0f
#define MIN_CUTOFF_FREQ 250.0f

#define SAMPLE_RATE     44100

const float DIV_SAMPLE_RATE = 1.0f / (float)SAMPLE_RATE;
const float DIV_2SAMPLE_RATE = 0.5f / (float)SAMPLE_RATE;

#define WAVE_SIZE       2048 // samples used for waveform lookup tables 
const float DIV_WAVE_SIZE = 1.0f / (float)WAVE_SIZE;
#define TANH_LOOKUP_MAX 5.0f // maximum argument X value for tanh(X) lookup table, tanh(X)~=1 if X>4 
const float TANH_LOOKUP_COEF = (float)WAVE_SIZE / TANH_LOOKUP_MAX;
#define DMA_BUF_LEN     32
#define DMA_NUM_BUF     2

#define I2S_BCLK_PIN    5
#define I2S_WCLK_PIN    19
#define I2S_DOUT_PIN    18

#define SYNTH1_MIDI_CHAN        1
#define SYNTH2_MIDI_CHAN        2

#define DRUM_MIDI_CHAN          10

#define MIDIRX_PIN      4
#define MIDITX_PIN      0

/*
#define MUXED_BUTTONS   0
#define GPIO_BUTTONS    1
#define TOTAL_BUTTONS MUXED_BUTTONS+GPIO_BUTTONS 
#define LOGICAL_ON      HIGH

enum e_pins_t     { fn1 = MUXED_BUTTONS,  fn2,  fn3,  fn4, enc_but }; // mnemonics for bits, starting with the first after the muxed buttons
uint8_t buttonGPIOs[GPIO_BUTTONS]{ 23 }; // GPIO buttons
//e_pins_t gpio_pin;
bool autoFireEnabled = false;                 // should the buttons generate continious clicks when pressed longer than a longPressThreshold
bool lateClickEnabled = false;                // enable registering click after a longPress call
const unsigned long longPressThreshold = 800; // the threshold (in milliseconds) before a long press is detected
const unsigned long autoFireDelay = 500;      // the threshold (in milliseconds) between clicks if autofire is enabled
const unsigned long riseThreshold = 20;       // the threshold (in milliseconds) for a button press to be confirmed (i.e. debounce, not "noise")
const unsigned long fallThreshold = 10;       // debounce, not "noise", also this is the time, while new "touches" won't be registered
*/

const float TWOPI = PI*2.0f;
const float MIDI_NORM = 1.0f/127.0f;
const float DIV_TWOPI = 1.0f/TWOPI;
#define FORMAT_LITTLEFS_IF_FAILED true
//#define CONFIG_LITTLEFS_CACHE_SIZE 1024



#define PSRAM_BUFFER_SIZE 900000 // this cache's size must correspond to the largest sample set's size
#define SAMPLECNT 12

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

// Debugging macros
#ifndef MIDI_VIA_SERIAL
  #ifndef DEB
    #ifdef DEBUG_ON
      #define DEB(...) Serial.print(__VA_ARGS__) 
      #define DEBF(...) Serial.printf(__VA_ARGS__) 
      #define DEBUG(...) Serial.println(__VA_ARGS__) 
    #else
      #define DEB(...)
      #define DEBF(...)
      #define DEBUG(...)
    #endif
  #endif
#else
      #define DEB(...)
      #define DEBF(...)
      #define DEBUG(...)
#endif
