#include <Arduino.h>

// Hall-effect sensor 3.3V
int HS1 = PA0; // Blue Pin 2
int HS2 = PA1; // Yellow Pin 3
int HS3 = PA2; // Green Pin 4

int led1 = PA15;
int led2 = PB4;
int led3 = PB5;
int led4 = PB8;
int leds[] = { led1, led2, led3, led4 };
// int leds[] = { led4, led3, led2, led1 };
int powerLed = PB9;

void setup () {  
  pinMode(HS1, INPUT);
  pinMode(HS2, INPUT);
  pinMode(HS3, INPUT);

  pinMode(powerLed, OUTPUT);

  // LEDs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void display(byte number) {
  for(byte i = 0; i < 4; i++) {
    bool value = number & 1;
    digitalWrite(leds[i], !value);
    number /= 2;
  }
}

byte i = 0;

void loop() {
  digitalWrite(powerLed, LOW);

  int angle = analogRead(HS1);
  display(i);
  i += 1;
  i = i % 16;
  delay(1000);
}