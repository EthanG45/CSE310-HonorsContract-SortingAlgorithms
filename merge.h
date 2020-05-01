#ifndef _MERGE_H_
#define _MERGE_H_

class Merge {
private:
    /**
     * @brief Size is an int representing the number of ints in the array
     * 
     */
    int size;
    int* mergeArray;

public:
    Merge(); //constructor
    
    void initialize(int inputSize, int inputArray[]);

    void mergeHelper(int pStart, int qMid, int rEnd);; //this is the merge function just can't call it merge directly because same as overall class
    
    void mergeSort(int pStart, int rEnd);
    
    int* mergeSortReturn();
};

#endif