#include "quick.h" //include the quick header

Quick::Quick() //constructor
{
	this->size = 0;
    this->quickArray = nullptr;
}

void Quick::initialize(int inputSize, int inputArray[])
{
    this->size = inputSize;
    this->quickArray = inputArray;
}

int Quick::partition(int pStart, int rEnd)
{
    int x = this->quickArray[rEnd];
    int i = pStart - 1;
    for(int j = pStart; j < rEnd; j++)
    {
        if(this->quickArray[j] <= x)
        {
            i++;
            int temp = this->quickArray[i];
            this->quickArray[i] = this->quickArray[j];
            this->quickArray[j] = temp;
        }
    }
    int temp = this->quickArray[i+1];
    this->quickArray[i+1] = this->quickArray[rEnd];
    this->quickArray[rEnd] = temp;
    
    return i+1;
}

void Quick::quickSort(int pStart, int rEnd)
{
    if(pStart < rEnd)
    {
        int q = partition(pStart,rEnd);
        quickSort(pStart, q-1);
        quickSort(q+1, rEnd);
    }
}

int* Quick::quickSortReturn()
{
    return this->quickArray;
}