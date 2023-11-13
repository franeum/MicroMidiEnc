#include <MicroMidiEnc.h>

#define ENCPIN1 2
#define ENCPIN2 3
#define MIDI_CHANNEL 1
#define N_CONTROLLER 50

// create MicroMidiEnc instance
/*
    Initialize with these args:
      1. pin1
      2. pin2
      3. midi channel (1 - 16)
      4. midi controller number (0 - 127)
      5. a string representing the encoder (optional, only for debug purpose)
    */
MicroMidiEnc encoder(ENCPIN1, ENCPIN2, MIDI_CHANNEL, N_CONTROLLER, "ENC1");

void setup()
{
  // disable serial monitoring if you want
  // MicroMidiEnc::set_debug(0);
}

void loop()
{
  // call update() method: it makes all (read value and send midi)
  encoder.update();
}