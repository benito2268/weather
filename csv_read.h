#pragma once
#include<string>
#include<vector>

namespace weather {
    struct DaySpan;
    DaySpan read(const char* filename);
    std::vector<std::string> split(std::string str, char delim);
}
