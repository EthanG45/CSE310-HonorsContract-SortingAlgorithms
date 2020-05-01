#ifndef _BUBBLE_H_
#define _BUBBLE_H_

class Bubble {
private:
    /**
     * @brief Size is an int representing the number of ints in the array
     * 
     */
    int size;
    int* bubbleArray;

public:
    Bubble(); //constructor
    
    void initialize(int inputSize, int inputArray[]);

    void bubbleSort();
    
    int* bubbleSortReturn();
};

#endif