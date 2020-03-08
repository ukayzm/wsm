#ifndef __HW_CONFIG__
#define __HW_CONFIG__

#define DHT_PIN     7
#define LED         8
#define buttonApin  9
#define buttonBpin  10

typedef void (*OnButtonPressed)(int buttonA, int countA, int buttonB, int countB);
extern void init_led_button(OnButtonPressed func);
extern void check_button();
extern void check_dht11();
extern void initController();
extern void loopController();
extern void initLcd();
extern void displayTempHumidity(int temperature, int humidity);

#define BUTTON_NO_CHANGE    0
#define BUTTON_PRESSED      1
#define BUTTON_RELEASED     2

#endif
