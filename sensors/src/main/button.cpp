#include "Arduino.h"
#include "hw_config.h"

OnButtonPressed onButtonPressed;
int stateA, stateB, countA, countB;
unsigned long lastMillis;

void init_led_button(OnButtonPressed func)
{
    onButtonPressed = func;
    pinMode(LED, OUTPUT);
    pinMode(buttonApin, INPUT_PULLUP);
    pinMode(buttonBpin, INPUT_PULLUP);
    stateA = BUTTON_RELEASED;
    stateB = BUTTON_RELEASED;
    lastMillis = millis();
}

void check_button()
{
    unsigned long curMillis = millis();
    if (curMillis - lastMillis < 100) {
        return;
    }
    lastMillis = curMillis;

    int newStateA = BUTTON_NO_CHANGE;
    int newStateB = BUTTON_NO_CHANGE;

    if (digitalRead(buttonApin) == LOW) {
        // A is pressed
        if (stateA != BUTTON_PRESSED) {
            stateA = BUTTON_PRESSED;
            countA = 0;
        } else {
            countA++;
        }
        newStateB = BUTTON_PRESSED;
    } else {
        // A is released
        if (stateA != BUTTON_RELEASED) {
            newStateA = stateA = BUTTON_RELEASED;
            countA = 0;
        }
    }
    if (digitalRead(buttonBpin) == LOW) {
        // B is pressed
        if (stateB != BUTTON_PRESSED) {
            stateB = BUTTON_PRESSED;
            countB = 0;
        }
        newStateB = BUTTON_PRESSED;
    } else {
        // B is released
        if (stateB != BUTTON_RELEASED) {
            newStateB = stateB = BUTTON_RELEASED;
            countB = 0;
        }
    }
    if (newStateA != BUTTON_NO_CHANGE || newStateB != BUTTON_NO_CHANGE) {
        onButtonPressed(newStateA, countA, newStateB, countB);
    }
}