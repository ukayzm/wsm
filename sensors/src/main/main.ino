#include "hw_config.h"

void onButtonPressed(int stateA, int countA, int stateB, int countB)
{
    if (stateA == BUTTON_PRESSED) {
        Serial.println("A on");
        digitalWrite(LED, HIGH);
    } else if (stateA == BUTTON_RELEASED) {
        Serial.println("A off");
    }
    if (stateB == BUTTON_PRESSED) {
        Serial.println("B on");
        digitalWrite(LED, LOW);
    } else if (stateB == BUTTON_RELEASED) {
        Serial.println("B off");
    }
}

void setup() {
    init_led_button(onButtonPressed);
    Serial.begin(115200);
    Serial.println("begin");
}

void loop() {
    check_button();
}
