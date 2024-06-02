#ifndef NEWTIME_H
#define NEWTIME_H

#include <chrono>

class Time {
    private:
        int hour;
        int minute;

    public:
        Time();
        int getHour() const;
        int getMinute() const;
        void setHour(int);
        void setMinute(int);
};

#endif