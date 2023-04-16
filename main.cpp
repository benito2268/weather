#include<iostream>
#include<algorithm>
#include<cstring>
#include"day.h"
#include"csv_read.h"

using namespace weather;

int main() {
    // Day** ptr = new Day*[5];


    // for(int k = 0; k < 5; k++) {
    //     ptr[k] = new Day();
    // }

    // for(int i = 0; i < 5; i++) {
    //     delete ptr[i];
    // }
    // delete[] ptr;

    // Day** other = nullptr;
    
    // std::memcpy(other, ptr, 5);

    //std::cout << &other << std::endl;

    weather::read("data\\2022.csv");

    return 0;
}
