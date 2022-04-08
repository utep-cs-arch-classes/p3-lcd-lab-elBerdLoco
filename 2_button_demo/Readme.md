# 2_button_demo

This demo demonstrates how to use the button interrupts to control the
display. This demo updates the display based on the state of button 1 and
button 2 on the LCD board. When the button is not pressed a '-' is displayed,
when the button is pressed the button number is displayed. It contains the
following files:
* button_demo.c contains the driver code that loops, every loop iteration the
display is updated based on the button state then the MSP430 is put to sleep,
the LED is turned on when the CPU is running
* led.c code for running the LEDs
* p2_asm_handler.s assembly code for handling the Port 2 interrupts, required
in order to wake up the CPU after a port 2 interrupt has occured, calls the C handler
* p2_c_handler.c The C handler for port 2 interrupts
* switches.c The code that handles the switches

Note: P1.0 is used by the LCD, if you use it for anything else the LCD will
stop working
