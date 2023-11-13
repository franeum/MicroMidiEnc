#ifndef MICRO_MIDI_ENC_H
#define MICRO_MIDI_ENC_H

#include <Arduino.h>
#include <BasicEncoder.h>
#include <MicroMidiUtils.h>

#define PLUS_ONE_DIRECTION 127
#define MINUS_ONE_DIRECTION 0

class MicroMidiEnc
{
public:
    MicroMidiEnc(){};
    MicroMidiEnc(byte pin1, byte pin2, byte channel, byte controller, String identifier = "ENC")
    {
        begin(pin1, pin2, channel, controller, identifier);
    };

    static void set_debug(byte value);
    void begin(byte pin1, byte pin2, byte channel, byte controller, String identifier = "ENC");
    void update();
    inline void set_reverse() { _enc->set_reverse(); };

private:
    static byte _debug;
    int _pos = -999;
    byte pin1, pin2;
    byte _channel;
    byte _controller;
    BasicEncoder *_enc;
    void send(byte value);
    String _id;
};

#endif
