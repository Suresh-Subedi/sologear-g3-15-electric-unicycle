#include <Arduino.h>

int HIn1 = PA10;
int HIn2 = PA9;
int HIn3 = PA8;
int LIn1 = PB15;
int LIn2 = PB14;
int LIn3 = PB13;

// Hall sensors 3.3V
int HS1 = PA0; // Blue Pin 2
int HS2 = PA1; // Yellow Pin 3
int HS3 = PA2; // Green Pin 4

int pins_h[] = {HIn1, HIn2, HIn3};
int pins_l[] = {LIn1, LIn2, LIn3};

int delay_ms = 2000;

int POS = 1;
int OFF = 0;
int NEG = -1;

bool invert = true;
bool turnOff = true;
bool delayAfterOff = false;
int magnetise_ms = 20;

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

    pinMode(HS1, INPUT);
    pinMode(HS2, INPUT);
    pinMode(HS3, INPUT);
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
    if(!delayAfterOff) { delay(magnetise_ms); }
    u(OFF);
    v(OFF);
    delay(delay_ms);
}
void s2()
{
    u(POS);
    v(OFF);
    w(NEG);
    if(!delayAfterOff) { delay(magnetise_ms); }
    u(OFF);
    w(OFF);
    delay(delay_ms);
}
void s3()
{
    u(OFF);
    v(POS);
    w(NEG);    
    if(!delayAfterOff) { delay(magnetise_ms); }
    v(OFF);
    w(OFF);
    delay(delay_ms);
}
void s4()
{
    u(NEG);
    v(POS);
    w(OFF);
    if(!delayAfterOff) { delay(magnetise_ms); }
    u(OFF);
    v(OFF);
    delay(delay_ms);
}
void s5()
{
    u(NEG);
    v(OFF);
    w(POS);
    if(!delayAfterOff) { delay(magnetise_ms); }
    u(OFF);
    w(OFF);
    delay(delay_ms);
}
void s6()
{
    u(OFF);
    v(NEG);
    w(POS);
    if(!delayAfterOff) { delay(magnetise_ms); }
    v(OFF);
    w(OFF);
    delay(delay_ms);
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