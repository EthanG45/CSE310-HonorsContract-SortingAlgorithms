#ifndef _INSERTION_H_
#define _INSERTION_H_

class Insertion {
private:
    /**
     * @brief Size is an int representing the number of ints in the array
     * 
     */
    int size;
    int* insertionArray;

public:
    Insertion(); //constructor
    
    void initialize(int inputSize, int inputArray[]);

    void insertionSort();
    
    int* insertionSortReturn();
};

#endif