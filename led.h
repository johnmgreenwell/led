//--------------------------------------------------------------------------------------------------------------------
// Name        : led.h
// Purpose     : LED Driver Class
// Description : 
//               This driver class intended for basic control of an LED.
//
// Language    : C++
// Platform    : Portable
// Framework   : Portable
// Copyright   : MIT License 2024, John Greenwell
// Requires    : External : N/A
//               Custom   : hal.h - Custom implementation-defined Hardware Abstraction Layer
//--------------------------------------------------------------------------------------------------------------------
#ifndef _LED_H
#define _LED_H

#include "hal.h"

namespace PeripheralIO
{

class LED 
{
    public:

        /**
         * @brief Constructor for LED object; LED initializes off
         * @param led_pin Identifying pin number of LED
         * @param on_logic_level Logic level for which the LED is illuminated
        */
        LED(uint8_t led_pin, bool on_logic_level=true);

        /**
         * @brief Illuminate the LED
        */
        void on() const;

        /**
         * @brief Extinguish the LED
        */
        void off() const;

        /**
         * @brief Toggle the current state of the LED
        */
        void toggle() const;

        /**
         * @brief Check whether the LED is currently illuminated
         * @return True for illuminated LED, false otherwise
        */
        bool is_on() const;

        /**
         * @brief Directly write a logic level to the LED pin
         * @param val The logic level to write to the LED pin; zero for false, nonzero for true
        */
        void write(uint8_t val) const;

        /**
         * @brief Directly read the logic level of the LED pin
         * @return Value read from LED pin; value of one for true, zero for false
        */
        uint8_t read() const;

    private:
        HAL::GPIO _led;
        bool      _on_logic_level;

};

}

#endif // _LED_H

// EOF
