#include "Arduino.h"
#include "DHT.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "hw_config.h"

DHT dht(DHT_PIN, DHT11);
unsigned long lastMillis;
unsigned long loopCount;

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

void initController() {
    init_led_button(onButtonPressed);
    initLcd();
    lastMillis = millis();
    loopCount = 0;
}

void loopController() {
    unsigned long curMillis = millis();
    if (curMillis - lastMillis < 100) {
        return;
    }
    loopCount++;

    check_button();

    if (loopCount % 10 == 0) {
        int humidity = dht.readHumidity();
        int temperature = dht.readTemperature();
        displayTempHumidity(temperature, humidity);
    }
    lastMillis = curMillis;
}
