//Datei: Timer.h
//Headerdatei für die Klasse Timer
//Autor: Andri Andermatt, 19.03.2025
#include <Arduino.h>

#ifndef TIMER_H_
#define TIMER_H_
    class Timer
    {
        public:
            enum timerMode {pulse, reset, periodic}; 
            //Mode of the Timer

            explicit Timer(timerMode initMode, int initTime); //Ctor
            //timerMode ->
            //pulse: One Pulse after Time is Up
            //reset: Stays High after Time is up, until resetTimer() is called
            //periodic: Pulses after Time is Up -> restart Timer again

            void startTimer();
            //Starts the Timer

            void updateTimer();
            //Updates the Timer State

            void resetTimer() {trigTimer = LOW;}
            //Resets the Timer; Output and interanl Time

            bool getTimerState() const {return timerState;}
            //Gets the State of the Timer
            //FALSE == Time is not up
            //TRUE == Time is up, unless in Mode Edge, then only for one Cycle true

            bool isTimerRunning() const {return (trigTimer && !timerState) ? HIGH : LOW;}
            //FALSE == Timer has reached the time value
            //TRUE == Timer has not yet reached time Value

        private:
            bool timerState = LOW; //State of the Timer
            int time; //Time the Timer is set to
            int mode; //Mode of the Timer
            int timeLast = 0; //Last Time of millis();
            bool trigTimer = LOW; //Helper for Timer
    };
#endif //TIMER_H_