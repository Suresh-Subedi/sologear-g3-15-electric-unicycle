#include <Arduino.h>

// W
int HIn1 = PA10;
int LIn1 = PB15;
// V
int HIn2 = PA9;
int LIn2 = PB14;
// U
int HIn3 = PA8;
int LIn3 = PB13;
int pins_led[] = {PA15, PB4, PB5, PB8};
int pins_h[] = {HIn1, HIn2, HIn3};
int pins_l[] = {LIn1, LIn2, LIn3};

int buzzer = PB3;

bool POS = HIGH;
bool NEG = LOW;
bool OFF = -1;

void s1();
void s2();
void s3();
void s4();
void s5();
void s6();

void w(int state);
void v(int state);
void u(int state);

void setState(int pin, int state);

int exeStep(int step);

void setup()
{

  // Mosfet driver pins
  pinMode(HIn1, OUTPUT);
  pinMode(HIn2, OUTPUT);
  pinMode(HIn3, OUTPUT);
  pinMode(LIn1, OUTPUT);
  pinMode(LIn2, OUTPUT);
  pinMode(LIn3, OUTPUT);

  // Buzzer
  pinMode(buzzer, OUTPUT);

  // LEDs
  pinMode(PA15, OUTPUT); //1
  pinMode(PB4, OUTPUT);
  pinMode(PB5, OUTPUT);
  pinMode(PB8, OUTPUT); //4

  // Inverted mosfet driver pins
  digitalWrite(LIn1, HIGH);
  digitalWrite(LIn2, HIGH);
  digitalWrite(LIn3, HIGH);

  // Hall-effect sensor 3.3V
  int HS1 = PA0; // Blue Pin 2
  int HS2 = PA1; // Yellow Pin 3
  int HS3 = PA2; // Green Pin 4
}
int step = 1;
uint32_t interval = 2000;
void loop()
{
  /*static uint32_t nextTime;
  if (millis() - nextTime >= interval) {
    nextTime += interval;
    step = exeStep(step);
  }*/
  digitalWrite(PA15, LOW);
  digitalWrite(PB4, LOW);
  digitalWrite(PB5, LOW);
  digitalWrite(PB8, LOW);

  //digitalWrite(buzzer, HIGH);
}

int exeStep(int step)
{
  switch (step)
  {
  case 1:
    s1();
    break;
  case 2:
    s2();
    break;
  case 3:
    s3();
    break;
  case 4:
    s4();
    break;
  case 5:
    s5();
    break;
  case 6:
    s6();
    break;
  default:
    break;
  }
  return (step + 1) % 6;
}

void s1()
{
  v(OFF);
  w(NEG);
  u(POS);
}
void s2()
{
  u(OFF);
  w(NEG);
  v(POS);
}
void s3()
{
  w(OFF);
  u(NEG);
  v(POS);
}
void s4()
{
  u(NEG);
  w(POS);
  v(OFF);
}
void s5()
{
  u(OFF);
  w(NEG);
  v(POS);
}
void s6()
{
  v(OFF);
  w(NEG);
  u(POS);
}

void w(int state)
{
  setState(1, state);
}
void v(int state)
{
  setState(2, state);
}
void u(int state)
{
  setState(3, state);
}

void setState(int pin, int state)
{
  int hpin = pins_led[pin - 1];
  if (state == POS)
  {
    digitalWrite(hpin, HIGH);
  }
  else if (state == NEG)
  {
    digitalWrite(hpin, LOW);
  }
}

/*void setState(int pin, int state)
{
  int hpin = pins_h[pin - 1];
  int lpin = pins_l[pin - 1];
  if (state == POS)
  {
    digitalWrite(lpin, HIGH);
    digitalWrite(hpin, HIGH);
  }
  else if (state == NEG)
  {
    digitalWrite(lpin, LOW);
    digitalWrite(hpin, LOW);
  }
  else if (state == OFF)
  {
    digitalWrite(lpin, HIGH);
    digitalWrite(hpin, LOW);
  }
}*/