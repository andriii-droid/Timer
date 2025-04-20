//Datei: Timer.cpp
//Implementationsdatei für die Klasse Timer
//Autor: Andri Andermatt, 19.03.2025
#include <Arduino.h>
#include <Timer.h>

Timer::Timer(timerMode initMode, int initTime)
    :mode{initMode}, time{initTime}
{
}
void Timer::startTimer()
{
    if (!isTimerRunning())
    {
        timeLast = millis(); 
        trigTimer = HIGH;
    }
}

void Timer::updateTimer()
{
    switch (mode)
    {
    case reset: //Mode Requires the reset() Function
        if ((time < millis() - timeLast) && trigTimer)
        {
            timerState = HIGH;
        } else
        {
            timerState = LOW;
        }

        break;
    case pulse: //This Mode does not require a Reset
        if ((time < millis() - timeLast) && trigTimer)
        {
            timerState = HIGH;
            trigTimer = LOW;
        } else
        {
            timerState = LOW;
        }
        break;
    case periodic:
        if ((time < millis() - timeLast) && trigTimer)
        {
            timerState = HIGH;
            trigTimer = LOW;
        } else
        {
            timerState = LOW;
            if (!trigTimer)
            {
                startTimer();
            }
            
        }        
        break;
    }
}
