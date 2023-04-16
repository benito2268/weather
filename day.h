#pragma once
#include<string>
#include<optional>

namespace weather {
    struct Day {
        std::string date;
        int temp_max;
        int temp_min;
        double temp_avg;
        double temp_dpt;
        double precip;
        double new_snow;
        int snow;

        Day(std::string date, int temp_max, int temp_min, double temp_avg, double temp_dpt, double precip, double new_snow, int snow);
        Day();
        ~Day();
    };

    struct DaySpan {
        Day** ptr = nullptr;
        std::size_t size;
        int count; //number of days

        //constructor to construct from another day object
        DaySpan(Day** days, size_t size, int count);
        DaySpan(DaySpan ds, int r_first, int r_last);
        DaySpan(); // constructs and empty span
        ~DaySpan();

        std::optional<int> indexOf(std::string date); //returns an empty option if the element is not found
        DaySpan subspan(int first, int last); //returns an empty span if index is out of rang
    };
}
