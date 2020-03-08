#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcdI2C(0x3F, 16, 2);

void initLcd() {
    lcdI2C.init();
    lcdI2C.backlight();
    lcdI2C.setCursor(0, 0);
    lcdI2C.print("begin");
}

void printDigits(char *buf, int value, int numDigits) {
    int i;
    for (i = 0; i < numDigits; i++) {
        buf[numDigits - i - 1] = '0' + (value % 10);
        value /= 10;
    }
}

void displayTempHumidity(int temperature, int humidity) {
    char buf[17];
    buf[0] = 'T';
    buf[1] = ':';
    buf[2] = ' ';
    printDigits(buf + 3, temperature, 3);
    buf[6] = ',';
    buf[7] = ' ';
    buf[8] = 'H';
    buf[9] = ':';
    buf[10] = ' ';
    printDigits(buf + 11, humidity, 3);
    buf[14] = ' ';
    buf[15] = ' ';
    buf[16] = '\0';
    lcdI2C.setCursor(0, 0);
    lcdI2C.print(buf);
    //lcdI2C.display();
    Serial.print(millis() / 1000);
    Serial.print(": T "); Serial.print(temperature);
    Serial.print(", H "); Serial.print(humidity);
    Serial.print(" -> ");
    Serial.println(buf);
}
