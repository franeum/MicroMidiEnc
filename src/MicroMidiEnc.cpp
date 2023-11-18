#include "MicroMidiEnc.h"

byte MicroMidiEnc::_debug = 1;

void MicroMidiEnc::begin(byte pin1, byte pin2, byte channel, byte controller, String identifier)
{
    _channel = enc_check_channel(channel);
    _controller = controller;

    if (_debug)
    {
        _id = "[" + identifier + "] " + "(channel: " +
              String(_channel + 1) + ", n_controller: " +
              String(_controller) + ")";
    }

    _enc = new BasicEncoder(pin1, pin2, LOW, 2);
}

void MicroMidiEnc::update()
{
    _enc->service();
    int encoder_pos = _enc->get_count();
    if (encoder_pos > _pos)
    {
        this->send(PLUS_ONE_DIRECTION);
        if (_debug)
        {
            Serial.print(_id);
            Serial.print("\tvalue: ");
            Serial.println(PLUS_ONE_DIRECTION);
        }
        _pos = encoder_pos;
    }
    else if (encoder_pos < _pos)
    {
        this->send(MINUS_ONE_DIRECTION);
        if (_debug)
        {
            Serial.print(_id);
            Serial.print("\tvalue: ");
            Serial.println(MINUS_ONE_DIRECTION);
        }
        _pos = encoder_pos;
    }
}

void MicroMidiEnc::send(byte value)
{
    enc_control_change(_channel, _controller, value);
}

void MicroMidiEnc::set_debug(byte value)
{
    _debug = value;
}
