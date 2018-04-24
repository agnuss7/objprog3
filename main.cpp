#include "studentai.h"
#include "funkcijos.cpp"
#include <chrono>
#include <iostream>
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds TimeType;
int main()
{
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;

    t1=Clock::now();
    cont2v("2.txt",60);
    t2=Clock::now();
    std::cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<"\n";
    return 0;
}
