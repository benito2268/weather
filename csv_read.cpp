#include<iostream>
#include<fstream>
#include<algorithm>
#include<iterator>
#include"csv_read.h"
#include"day.h"

namespace weather {
    //reads a csv file and stores the data in the 'loaded' struct
    DaySpan read(const char* filename) {
        std::ifstream inFile(filename);
        if(inFile.fail()) {
            std::cout << "system could not find the file specified" << std::endl;
        }

        std::string line;
        std::size_t numLines;
        Day** arr;

        //count the number of lines in the file
        numLines = std::count(std::istreambuf_iterator<char>(inFile),
                   std::istreambuf_iterator<char>(), '\n'); 

        arr = new Day*[numLines];

        //equivalent to rewind() in c
        inFile.clear();
        inFile.seekg(0);

        int i = 0;
        while(std::getline(inFile, line)) {
            //split the string
            std::vector<std::string> vec = split(line, ',');
            arr[i] = new Day(vec[0],
                        std::stoi(vec[1]), //temp_max
                        std::stoi(vec[2]), //temp_min
                        std::stod(vec[3]), //temp_avg
                        std::stod(vec[4]), //temp_dpt
                        std::stod(vec[7]), //precip
                        std::stod(vec[8]), //new_snow
                        std::stoi(vec[9]) //snow_depth
                        );      
            i++;
        }

        inFile.close();
        DaySpan span = DaySpan(arr, numLines*sizeof(Day*), numLines);
        
        for(int k = 0; k < numLines; k++) {
            delete arr[k];
        }
        delete[] arr;

        return span;
    }

    //splits a string into a vector
    std::vector<std::string> split(std::string s, char delim) {
        std::size_t pos = 0;
        std::vector<std::string> ret;
        std::string token;
        std::string d(1, delim);
        while((pos = s.find(d)) != std::string::npos) {
            token = s.substr(0, pos);
            ret.push_back(token);
            s.erase(0, pos + d.length());
        }
        ret.push_back(s);
        return ret;
    }
}