#include "insertion.h" //include the insertion header

Insertion::Insertion() //constructor
{
	this->size = 0;
    this->insertionArray = nullptr;
}

void Insertion::initialize(int inputSize, int inputArray[])
{
    this->size = inputSize;
    this->insertionArray = inputArray;
}

void Insertion::insertionSort()
{
    int key = 0;
    int i = 0;
    for(int j = 1; j < size; j++)
    {
        key = insertionArray[j];
        //Insert insertionArray[j] into the sorted sequence insertionArray[1..j-1]
        i = j-1;
        while((i >= 0) && (insertionArray[i] > key))
        {
            insertionArray[i+1] = insertionArray[i];
            i--;
        }
        insertionArray[i+1] = key;
    }
}

int* Insertion::insertionSortReturn()
{
    return this->insertionArray;
}