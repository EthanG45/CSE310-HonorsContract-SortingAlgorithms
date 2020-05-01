#include "merge.h" //include the merge header
#include <limits> //include the numerical limits for negative infinity use

using std::numeric_limits;

Merge::Merge() //constructor
{
	this->size = 0;
    this->mergeArray = nullptr;
}

void Merge::mergeHelper(int pStart, int qMid, int rEnd)
{
    int n1 = 0;
    int n2 = 0;
    int i = 0;
    int j = 0;
    int* leftArray = nullptr;
    int* rightArray = nullptr;

    n1 = qMid-pStart+1; //probably an error due to index
    // n1 = qMid-pStart; //probably an error due to index
    n2 = rEnd-qMid; //probably an error due to index
    // n2 = rEnd-qMid-1; //probably an error due to index
    // leftArray = new int[n1];
    leftArray = new int[n1+1];
    // rightArray = new int[n2];
    rightArray = new int[n2+1];

    // for(i = 0; i < n1; i++)
    for(i = 1; i <= n1; i++)
    {
        leftArray[i] = this->mergeArray[pStart+i-1]; //probably an error due to index
        // leftArray[i] = this->mergeArray[pStart+i]; //probably an error due to index
    }
    // for(j = 0; j < n2; j++)
    for(j = 1; j <= n2; j++)
    {
        rightArray[j] = this->mergeArray[qMid+j]; //probably an error due to index
    }
    
    leftArray[n1+1] = numeric_limits<int>::max(); //probably an error due to index
    // leftArray[n1] = numeric_limits<int>::max(); //probably an error due to index
    rightArray[n2+1] = numeric_limits<int>::max(); //probably an error due to index
    // rightArray[n2] = numeric_limits<int>::max(); //probably an error due to index

    i = 1; //probably an error due to index
    // i = 0; //probably an error due to index
    j = 1; //probably an error due to index
    // j = 0; //probably an error due to index

    // for(int k = pStart; k < rEnd; k++)
    for(int k = pStart; k <= rEnd; k++)
    {
        if(leftArray[i] <= rightArray[j])
        {
            this->mergeArray[k] = leftArray[i];
            i++;
        }
        else
        {
            this->mergeArray[k] = rightArray[j];
            j++;
        }
    }

}

void Merge::initialize(int inputSize, int inputArray[])
{
    this->size = inputSize;
    this->mergeArray = inputArray;
}

void Merge::mergeSort(int pStart, int rEnd)
{
    int qMid = 0;
    if(pStart < rEnd)
    {
        // qMid = ((pStart+rEnd)/2)-1; //minus 1 to fit base index of 0
        qMid = (pStart+rEnd)/2;
        mergeSort(pStart, qMid);
        mergeSort(qMid+1, rEnd);
        mergeHelper(pStart, qMid, rEnd);
    }
}

int* Merge::mergeSortReturn()
{
    return this->mergeArray;
}