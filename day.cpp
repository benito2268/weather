//defines one day worth of weather
#include<cstring>
#include<iostream>
#include"day.h"

namespace weather {
    Day::Day(std::string date, int temp_max, int temp_min, double temp_avg, double temp_dpt, double precip, double new_snow, int snow){
        this->date = date;
        this->temp_max = temp_max;
        this->temp_min = temp_min;
        this->temp_avg = temp_avg;
        this->temp_dpt = temp_dpt;
        this->precip = precip;
        this->new_snow = new_snow;
        this->snow = snow;
    }

    Day::Day() {
        //default constructor
    }

    Day::~Day() {
        
    }

    DaySpan::DaySpan(Day* days, size_t size, int count) {
        this->ptr = new Day[count];
        std::memcpy(this->ptr, days, size);
        this->size = size;
        this->count = count;
    }

    DaySpan::DaySpan() {
        this->ptr = nullptr;
        this->size = 0;
        this->count = 0;
    }

    DaySpan::~DaySpan() {
        delete[] this->ptr;
    }

    DaySpan::DaySpan(DaySpan ds, int r_first, int r_last) {
        //re adjust pointer
        std::copy(ds.ptr+r_first, ds.ptr+r_last, this->ptr);
        this->size = (r_last - r_first)*sizeof(Day);
        this->count = (r_last - r_first);
    }

    //should probably be a better algorithm
    std::optional<int> DaySpan::indexOf(std::string date) {
        for(int i = 0; i < this->count; i++) {
            if(this->ptr[i].date == date) {
                return i;
            }
        }
        return {}; //empty
    }

    DaySpan DaySpan::subspan(int first, int last) {
        if(first < 0 || first >= count || last < 0 || last >= count) {
            return DaySpan();
        }
        return DaySpan(*this, first, last);
    }
}
