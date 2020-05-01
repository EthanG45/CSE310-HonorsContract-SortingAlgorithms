#include "bubble.h" //include the bubble header

Bubble::Bubble() //constructor
{
	this->size = 0;
    this->bubbleArray = nullptr;
}

void Bubble::initialize(int inputSize, int inputArray[])
{
    this->size = inputSize;
    this->bubbleArray = inputArray;
}

void Bubble::bubbleSort()
{
    int temp = 0;
    for(int i = 0; i < this->size; i++)
    {
        for(int j = this->size-1; j >= i+1; j--)
        {
            if(this->bubbleArray[j] < this->bubbleArray[j-1])
            {
                temp = bubbleArray[j];
                bubbleArray[j] = bubbleArray[j-1];
                bubbleArray[j-1] = temp;
            }
        }
    }
}

int* Bubble::bubbleSortReturn()
{
    return this->bubbleArray;
}