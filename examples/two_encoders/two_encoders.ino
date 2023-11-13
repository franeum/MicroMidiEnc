#include <MicroMidiEnc.h>

#define ENC11 2
#define ENC12 3
#define ENC21 5
#define ENC22 6
#define MIDI_CHANNEL 1

// create MicroMidiEnc instance
MicroMidiEnc encoder1;
MicroMidiEnc encoder2;

void setup()
{
  /*
    Initialize with these args:
      1. pin1
      2. pin2
      3. midi channel (1 - 16)
      4. midi controller number (0 - 127)
      5. a string representing the encoder (optional, only for debug purpose)
    */
  encoder1.begin(ENC11, ENC12, MIDI_CHANNEL, 50, "ENC1");
  encoder2.begin(ENC21, ENC22, MIDI_CHANNEL, 60, "ENC2");

  // if you want encoder2 run at the contrary
  // encoder2.set_reverse();

  // disable serial monitoring if you want
  // MicroMidiEnc::setDebug(0);
}

void loop()
{
  // call update() method: it makes all (read value and send midi)
  encoder1.update();
  encoder2.update();
}