#include <Arduino.h>

int HIn1 = PB10;
int HIn2 = PB9;
int HIn3 = PB8;
int LIn1 = PB15;
int LIn2 = PB14;
int LIn3 = PB13;

int pins_h[] = {HIn1, HIn2, HIn3};
int pins_l[] = {LIn1, LIn2, LIn3};

int delay_ms = 200;

int POS = 1;
int OFF = 0;
int NEG = -1;

bool invert = true;

void setState(int state, int pin);

void s1();
void s2();
void s3();
void s4();
void s5();
void s6();

void w(int state);
void v(int state);
void u(int state);

void setup()
{
    pinMode(HIn1, OUTPUT);
    pinMode(HIn2, OUTPUT);
    pinMode(HIn3, OUTPUT);
    pinMode(LIn1, OUTPUT);
    pinMode(LIn2, OUTPUT);
    pinMode(LIn3, OUTPUT);
}

void loop()
{       
    s2();
    s3();
    s4();
    s5();
    s6();
    s1();
}

void s1()
{
    u(POS);
    v(NEG);
    w(OFF);
    delay(delay_ms);
    u(OFF);
    v(OFF);
}
void s2()
{
    u(POS);
    v(OFF);
    w(NEG);
    delay(delay_ms);
    u(OFF);
    w(OFF);
}
void s3()
{
    u(OFF);
    v(POS);
    w(NEG);    
    delay(delay_ms);
    v(OFF);
    w(OFF);
}
void s4()
{
    u(NEG);
    v(POS);
    w(OFF);
    delay(delay_ms);
    u(OFF);
    v(OFF);
}
void s5()
{
    u(NEG);
    v(OFF);
    w(POS);
    delay(delay_ms);
    u(OFF);
    w(OFF);
}
void s6()
{
    u(OFF);
    v(NEG);
    w(POS);
    delay(delay_ms);
    v(OFF);
    w(OFF);
}

void u(int state)
{
    setState(state, 3);
}
void v(int state)
{
    setState(state, 2);
}
void w(int state)
{
    setState(state, 1);
}

void setState(int state, int pin)
{
    int hpin = pins_h[pin - 1];
    int lpin = pins_l[pin - 1];

    digitalWrite(hpin, LOW);
    digitalWrite(lpin, invert ^ LOW);
    if (state == POS)
    {
        digitalWrite(hpin, HIGH);
    }
    else if (state == NEG)
    {
        digitalWrite(lpin, invert ^ HIGH);
    }
}