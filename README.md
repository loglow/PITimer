# PITimer

## PIT (periodic interrupt timer) library for Teensy 3.0

Four built-in timers are available, numbered 0-3: `PITimer0`, `PITimer1`, `PITimer2`, and `PITimer3`.

Each timer's period defaults to one second. Change this with the `value()`, `period()`, or `frequency()` functions. If they're called without arguments, these functions will instead return their respective values. Period is specified in seconds, and frequency is specified in hertz. Floating-point values are fine for either. You can update these values on-the-fly, while a timer is running, if you want to.

Start a timer by calling it's `start()` function. Likewise, stop it by calling `stop()`. The periodic interrupts will call their appropriate interrupt service routines, which you'll have to define yourself with the following names:

`PITimer0` &rarr; `pit0_isr()`
`PITimer1` &rarr; `pit1_isr()`
`PITimer2` &rarr; `pit2_isr()`
`PITimer3` &rarr; `pit3_isr()`

These routines can't have a return value. Inside each service routine, you'll have to call the associated timer's `clear()` function in order for it to keep producing future interrupts.

The `reset()` function will reset the timer's countdown so that one full period will elapse from when it's called, thereby delaying when the next interrupt is to be generated. The `current()` function will return the remaining countdown value of the current timer cycle. This value is measured in individual bus clock cycles. The default bus speed for the Teensy 3.0 is 48 MHz (aka 48,000,000 cycles).

Last but not least, you can use `running()` to check whether the timer is active or not.

Please let me know if you find anything that needs fixing.
