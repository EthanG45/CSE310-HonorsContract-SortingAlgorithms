#ifndef _TIMER_H_
#define _TIMER_H_

#include <string> //include string data types
#include <iostream> //include the basic input output stream
#include <fstream> //input output stream for files
using std::ofstream;
using std::string;
using std::cout;
using std::endl;
using std::to_string;

struct Algorithm
{
    int total;
    int sort;
    int totalRank;
    int sortRank;
    string label;
};

class Timer {
private:
    int arraySize;
    Algorithm quick;
    Algorithm heap;
    Algorithm merge;
    Algorithm insertion;
    Algorithm bubble;
    struct Algorithm* rankArray;

public:
    Timer(int inputSize); //constructor
    
    void updateTimes(int totalTime, int sortTime, string sortType);

    void rank(int flag2);
};

#endif