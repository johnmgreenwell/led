//--------------------------------------------------------------------------------------------------------------------
// Name        : led.cpp
// Purpose     : LED Driver Class
// Description : This source file implements header file led.h.
// Language    : C++
// Platform    : Portable
// Framework   : Portable
// Copyright   : MIT License 2022, John Greenwell
//--------------------------------------------------------------------------------------------------------------------

#include "led.h"

namespace PeripheralIO
{

LED::LED(uint8_t led_pin, bool on_logic_level)
: _led(led_pin)
, _on_logic_level(on_logic_level)
{
    _led.pinMode(GPIO_OUTPUT);
}

void LED::on() const
{
    _led.digitalWrite(_on_logic_level);
}

void LED::off() const
{
    _led.digitalWrite(!_on_logic_level);
}

void LED::toggle() const
{
    _led.digitalWrite(!_led.digitalRead());
}

void LED::write(uint8_t val) const
{
    bool state = (val) ? _on_logic_level : !_on_logic_level;

    _led.digitalWrite(state);
}

uint8_t LED::read() const
{
    bool state = (_led.digitalRead()) ? _on_logic_level : !_on_logic_level;

    return state;
}

}

// EOF
