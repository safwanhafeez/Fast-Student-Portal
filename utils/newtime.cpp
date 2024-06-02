#include "../include/newtime.h"

Time::Time() {
    auto current_time = chrono::system_clock::now();
    time_t current_time_t = chrono::system_clock::to_time_t(current_time);
    tm* current_time_tm = localtime(&current_time_t);
    hour = current_time_tm->tm_hour;
    minute = current_time_tm->tm_min;
}
int Time::getHour() const {
    return hour;
}
int Time::getMinute() const {
    return minute;
}
void Time::setHour(int h) {
    hour = h;
}
void Time::setMinute(int m) {
    minute = m;
}