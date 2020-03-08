#include "hw_config.h"

void setup() {
    Serial.begin(115200);
    Serial.println("\nbegin");
    initController();
}

void loop() {
    loopController();
}
