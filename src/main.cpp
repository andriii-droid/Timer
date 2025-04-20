//Datei: main.cpp
//BeispielTest für die Klasse Timer
//Autor: Andri Andermatt, 19.03.2025
#include <Arduino.h>
#include <Timer.h>

Timer t1 {t1.periodic, 1000};

void setup() 
{
    pinMode(16, OUTPUT);

    pinMode(17, OUTPUT);
    digitalWrite(17, HIGH);
    delay(100);
    digitalWrite(17, LOW);
    t1.startTimer();
}

void loop() 
{
    t1.updateTimer();

    if (t1.getTimerState())
    {
        if (digitalRead(16))
        {
            digitalWrite(16, LOW);
        } else
        {
            digitalWrite(16, HIGH);
        }
    }
}