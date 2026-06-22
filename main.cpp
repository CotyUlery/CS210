#include "Clock.h"
#include <iostream>

void displayClocks(const Clock& clock) {
    std::cout << "\n**************************     **************************\n";
    std::cout << "*      12-Hour Clock     *     *      24-Hour Clock     *\n";
    std::cout << "*        ";
    clock.display12Hour();
    std::cout << "       *     *         ";
    clock.display24Hour();
    std::cout << "         *\n";
    std::cout << "**************************     **************************\n";
}

int main() {
    Clock clock(12, 0, 0);

    int choice = 0;

    while (choice != 4) {
        displayClocks(clock);

        std::cout << "\nMenu\n";
        std::cout << "1 - Add One Hour\n";
        std::cout << "2 - Add One Minute\n";
        std::cout << "3 - Add One Second\n";
        std::cout << "4 - Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: clock.addHour(); break;
            case 2: clock.addMinute(); break;
            case 3: clock.addSecond(); break;
            case 4: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid selection.\n";
        }
    }

    return 0;
}

# Clock Project Portfolio Artifact

This project demonstrates a menu-driven clock application written in C++.

Files:
- Clock.h
- Clock.cpp
- main.cpp

Features:
- 12-hour clock display
- 24-hour clock display
- Add hour, minute, or second
- Automatic rollover handling

This project serves as a portfolio artifact demonstrating object-oriented programming, modular design, and basic user interaction in C++.

#include "Clock.h"
#include <iomanip>
#include <iostream>

Clock::Clock(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

void Clock::addHour() {
    hours = (hours + 1) % 24;
}

void Clock::addMinute() {
    minutes++;
    if (minutes >= 60) {
        minutes = 0;
        addHour();
    }
}

void Clock::addSecond() {
    seconds++;
    if (seconds >= 60) {
        seconds = 0;
        addMinute();
    }
}

void Clock::display24Hour() const {
    std::cout << std::setfill('0')
              << std::setw(2) << hours << ":"
              << std::setw(2) << minutes << ":"
              << std::setw(2) << seconds;
}

void Clock::display12Hour() const {
    int displayHour = hours % 12;
    if (displayHour == 0) displayHour = 12;

    std::string period = (hours >= 12) ? "PM" : "AM";

    std::cout << std::setfill('0')
              << std::setw(2) << displayHour << ":"
              << std::setw(2) << minutes << ":"
              << std::setw(2) << seconds << " "
              << period;
}

#ifndef CLOCK_H
#define CLOCK_H

class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Clock(int h = 0, int m = 0, int s = 0);

    void addHour();
    void addMinute();
    void addSecond();

    void display24Hour() const;
    void display12Hour() const;
};

#endif
