#pragma once

class ScheduleTime {

    int day_of_week;
    int lecture_number;

public:

    ScheduleTime(int day_of_week, int lecture_number); // numbers from 1 to 7

    int get_day_of_week() const;
    int get_lecture_number() const;
};