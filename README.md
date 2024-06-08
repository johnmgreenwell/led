# Generic LED Driver

Generic, portable, multi-instance LED driver.

## Overview

This HAL-mediated custom LED driver permits ease of use that is designed to be platform-independent. Though simple GPIO behavior, this driver brings it up into a portable and highly-readable object-oriented programming space.

## Usage

The LED header and source rely on an external user-defined hardware abstraction layer (HAL) called `hal.h` which defines the necessary calls in the `HAL` namespace. This includes a GPIO pin object with `pinMode()`, `digitalRead()`, and `digitalWrite()` methods, as well as an enumerated value `GPIO_OUTPUT` which, when supplied to the `pinMode()` function, will set the selected GPIO pin to output mode.

At instantiation, the logic level corresponding to LED illumination may be set. By default, a high logic level will be applied for on, and a low level for off.

### Example

```cpp
#include "led.h"

...

// Instantiate LED
PeripheralIO::LED led(PIN_A0);

...

int main()
{
    // Use LED as conditional indicator
    if (someCondition)
    {
        led.on();
    }
    else
    {
        led.off();
    }

...

    // Check if LED is on
    if (led.read())
    {
        // Do something
    }

    // Toggle the LED
    led.toggle()
}

...
```

## License

MIT © 2024 John Greenwell