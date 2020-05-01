#ifndef _QUICK_H_
#define _QUICK_H_

class Quick {
private:
    /**
     * @brief Size is an int representing the number of ints in the array
     * 
     */
    int size;
    int* quickArray;

public:
    Quick(); //constructor
    
    void initialize(int inputSize, int inputArray[]);

    int partition(int pStart, int rEnd);

    void quickSort(int pStart, int rEnd);
    
    int* quickSortReturn();
};

#endif