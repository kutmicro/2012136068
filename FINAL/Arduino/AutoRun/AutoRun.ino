#include "DRV8835MotorShield_set.h"
#include <SoftwareSerial.h>
SoftwareSerial BT(12,13);
void setup() {
    motors.flipM1(true);
}

void loop() {
  autoRun(1);
}
