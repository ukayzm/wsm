#ifndef __HW_CONFIG__
#define __HW_CONFIG__

#define LED 8
#define buttonApin 9
#define buttonBpin 10

typedef void (*OnButtonPressed)(int buttonA, int countA, int buttonB, int countB);
extern void init_led_button(OnButtonPressed func);
extern void check_button();

#define BUTTON_NO_CHANGE    0
#define BUTTON_PRESSED      1
#define BUTTON_RELEASED     2

#endif