# MicroMidiEnc

by [francesco bianchi](https://www.francescobianchi.cloud)

Arduino Library to use a rotary encoder as MIDI controller (via USB). It currently run only on **ATmega32U4** (Micro and Leonardo).

Tha API is based on ICU paradigm: *Instatiate-Configure-Update* and you can use an encoder with only 3 lines of code:

```c++
#include <MicroMidiEnc.h>

// Instantiate
MicroMidiEnc enc;

void setup() {
    // Configure (pin1, pi2, MIDI_CHANNEL (1-16), MIDI_CONTROLLER, LABEL_FOR_DEBUG)
    enc.begin(D2, D3, 1, 70, "ENC");
}

void loop() {
    // Update
    enc.update();

    // ...all done!
}
```

Credits:
-   Peter Harrison, [BasicEncoder Library](https://github.com/micromouseonline/BasicEncoder)
