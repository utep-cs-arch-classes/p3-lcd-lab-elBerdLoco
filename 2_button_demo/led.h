#ifndef led_included
#define led_included

#define LED_RED   0         // P1.0 not used with lcd
#define LED_GREEN BIT6      // P1.6
#define LEDS (LED_RED | LED_GREEN)

// variables are defined elsewhere
extern unsigned char red_on, green_on;
extern unsigned char led_changed;

void led_init(void);
void led_update(void);

#endif // included
