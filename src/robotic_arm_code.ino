#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servo_B;
Servo servo_L;
Servo servo_R;
Servo servo_T;

int pos, state;

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("NEXUS");
  delay(1000);
  Serial.begin(9600);

  servo_B.attach(3);
  servo_L.attach(5);
  servo_R.attach(10);
  servo_T.attach(9);

  servo_B.write(20);
  servo_T.write(10);
  servo_R.write(120);
  servo_L.write(120);
  delay(2000);
}

void loop() {

  // lcd.clear();
  // delay(1000);
  while (Serial.available()) {
    // String a= Serial.readStringUntil("\r");
    state = Serial.read();
    Serial.println(state);
    if (state == 'm') {
          lcd.setCursor(0, 1);
  lcd.print("METAL  ");
      metal();
      // lcd.clear();
    } else if (state == 'b') {
          lcd.setCursor(0, 1);
  lcd.print("PLASTIC");
      plastic();
      // lcd.clear();
    } else if (state == 'p') {
          lcd.setCursor(0, 1);
  lcd.print("PAPER  ");
      paper();

      // lcd.clear();
    }
  }
}

void metal() {

              for (pos = 120; pos <= 140; pos += 5) {
    servo_R.write(pos);
    delay(50);
  }
        for (pos = 10; pos <= 150; pos += 5) {
    servo_T.write(pos);
    delay(50);
  }
  delay(1000);
             for (pos = 140; pos >= 120; pos -= 5) {
    servo_R.write(pos);
    delay(50);
  }
          for (pos = 120; pos <= 160; pos += 2) {
    servo_L.write(pos);
    delay(50);
  }//initial STage
  for (pos = 20; pos <= 180; pos += 5) {
    servo_B.write(pos);
    delay(50);
  }
  for (pos = 160; pos >= 140; pos -= 5) {
    servo_L.write(pos);
    delay(50);
  }
  for (pos = 150; pos >= 10; pos -= 5) {
    servo_T.write(pos);
    delay(10);
  }
  delay(1000);
  for (pos = 140; pos <= 180; pos += 5) {
    servo_L.write(pos);
    delay(50);
  }
  for (pos = 180; pos >= 20; pos -= 5) {
    servo_B.write(pos);
    delay(50);
  }
  //   for (pos = 80; pos >= 10; pos -= 5) {
  //   servo_T.write(pos);
  //   delay(10);
  // }
    for (pos = 180; pos >= 120; pos -= 5) {
    servo_L.write(pos);
    delay(50);
  }
}

void plastic() {

                for (pos = 120; pos <= 140; pos += 5) {
    servo_R.write(pos);
    delay(50);
  }
        for (pos = 10; pos <= 150; pos += 5) {
    servo_T.write(pos);
    delay(50);
  }
  delay(1000);
             for (pos = 140; pos >= 120; pos -= 5) {
    servo_R.write(pos);
    delay(50);
  }
          for (pos = 120; pos <= 160; pos += 2) {
    servo_L.write(pos);
    delay(50);
  }//initial STage
  for (pos = 0; pos <= 130; pos += 5) {
    servo_B.write(pos);
    delay(50);
  }
  for (pos = 120; pos >= 100; pos -= 5) {
    servo_R.write(pos);
    delay(50);
  }
  for (pos = 160; pos >= 140; pos -= 5) {
    servo_L.write(pos);
    delay(50);
  }
  for (pos = 150; pos >= 10; pos -= 5) {
    servo_T.write(pos);
    delay(10);
  }
  delay(1000);

    for (pos = 140; pos >= 120; pos -= 5) {
    servo_L.write(pos);
    delay(50);
  }
    for (pos = 100; pos <= 120; pos += 5) {
    servo_R.write(pos);
    delay(50);
  }
      for (pos = 120; pos >= 100; pos -= 5) {
    servo_R.write(pos);
    delay(50);
  }
      for (pos = 120; pos <= 140; pos += 5) {
    servo_L.write(pos);
    delay(50);
  }
  delay(500);
    for (pos = 130; pos >= 20; pos -= 5) {
    servo_B.write(pos);
    delay(50);
  }
        for (pos = 100; pos <= 120; pos += 5) {
    servo_R.write(pos);
    delay(50);
  }
      for (pos = 140; pos >= 120; pos -= 5) {
    servo_L.write(pos);
    delay(50);
  }
  //   for (pos = 40; pos >= 10; pos -= 5) {
  //   servo_T.write(pos);
  //   delay(10);
  // }
}

void paper() {

                for (pos = 120; pos <= 140; pos += 5) {
    servo_R.write(pos);
    delay(50);
  }
        for (pos = 10; pos <= 150; pos += 5) {
    servo_T.write(pos);
    delay(50);
  }
  delay(1000);
             for (pos = 140; pos >= 120; pos -= 5) {
    servo_R.write(pos);
    delay(50);
  }
          for (pos = 120; pos <= 160; pos += 2) {
    servo_L.write(pos);
    delay(50);
  }//initial STage
  for (pos = 0; pos <= 80; pos += 5) {
    servo_B.write(pos);
    delay(50);
  }
  delay(1000);
  for (pos = 160; pos >= 150; pos -= 5) {
    servo_L.write(pos);
    delay(50);
  }
  delay(1000);
  for (pos = 150; pos >= 10; pos -= 5) {
    servo_T.write(pos);
    delay(10);
  }
  delay(1000);
  for (pos = 80; pos >= 20; pos -= 5) {
    servo_B.write(pos);
    delay(50);
  }
    for (pos = 150; pos >= 120; pos -= 5) {
    servo_L.write(pos);
    delay(50);
  }

}
