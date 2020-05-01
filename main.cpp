/**
 * @file main.cpp
 * @author Ethan Gilchrist (egilchr1@asu.edu)
 * @brief insert description!
 * @version 0.1
 * @date 2020-04-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream> //include the basic input output stream
#include <fstream> //input output stream for files
#include <string> //include string data types
#include <new> //allows for catching of memory allocation errors in the creation of the heapArray

#include "quick.h" //include the heap program
#include "heap.h" //include the heap program
#include "merge.h" //include the merge program
#include "insertion.h" //include the insertion program
#include "bubble.h" //include the merge program
#include "timer.h" //include the timer program

#include <stdlib.h> //include rand for number generation
#include <chrono> //include for time measurements

//The following lines apply the std scope resolution operator :: to some commonly used elements in the program.
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::nothrow;

using std::ofstream;
using std::to_string;
using namespace std::chrono;


Timer* globalTimerObject;

int* quickSorter(int arraySize, int arrayToSort[], int flag, int flag2);
int* heapSorter(int arraySize, int arrayToSort[], int flag, int flag2);
int* mergeSorter(int arraySize, int arrayToSort[], int flag, int flag2);
int* insertionSorter(int arraySize, int arrayToSort[], int flag, int flag2);
int* bubbleSorter(int arraySize, int arrayToSort[], int flag, int flag2);
void sortFileOutput(string sortType, int arraySize, int timeTotal, int timeSort, int arrayOutput[]);
void comparisonTool(int arraySize, int* quickArray, int* heapArray, int* mergeArray, int* insertionArray, int* bubbleArray);
void randomArrayfileOutput(int arraySize, int arrayOutput[]);
int* randomArrayGenerator(int arraySize);
char nextCommand(int* flag, int* flag2, int* keyValue, int* size);

/**
 * @brief insert description!
 * 
 * @return int 
 */
int main()
{
    srand (time(NULL));
    
    //variables for the parser
    char userInput = 'Z'; //initialize to a dummy letter
    int flag = -1; //initialize to a dummy value
    int flag2 = -1; //initialize to a dummy value
    int keyValue = -1; //initialize to a dummy value
    int size = -1; //initialize to a dummy value
    
    int* randomArray = nullptr; //pointer to localHeapArray
    int randomArraySize = 0;

    int* quickArray = nullptr;
    int* heapArray = nullptr;
    int* mergeArray = nullptr;
    int* insertionArray = nullptr;
    int* bubbleArray = nullptr;

    cout << "Welcome to the Sorting Algorithm Time Tester. Enter command: (F for help)" << endl;
    while(1) //run loop always for command line interfacing
    {
        userInput = nextCommand(&flag, &flag2, &keyValue, &size); //call util.cpp function for parsing input
        if(userInput == 'S' || userInput == 's') //stop command
        {
            cout << "COMMAND: " << userInput << endl;
            break; //break out of loop
        }
        else if(userInput == 'N' || userInput == 'n')
        {
            cout << "COMMAND: " << userInput << " with size " << size << " and flag " << flag << " and flag2 of " << flag2 << endl;
            randomArraySize = size;
            randomArray = randomArrayGenerator(randomArraySize);
            cout << "Generating random array of size " << randomArraySize << " using numbers 0-999999";
            if (flag == 2)
            {
                cout << " with local printing." << endl;
                for(int i = 0; i < randomArraySize; i++) //loop through the n ints storing the random array
                {
                    cout << randomArray[i] << endl; //store current array value
                }
            }
            else 
            {
                cout << " without local printing." << endl;
            }
            if(flag2 == 2)
            {
                cout << "See file RandomNumberArraySize" << randomArraySize << ".txt to see the created array." << endl;
                randomArrayfileOutput(randomArraySize, randomArray);
            }
            globalTimerObject = new Timer(randomArraySize);
        }
        else if(userInput == 'Q' || userInput == 'q')
        {
            quickArray = new int[randomArraySize]; //dynamically allocate memory to array of given size
            memcpy(quickArray, randomArray, randomArraySize * sizeof(int));
            cout << "COMMAND: " << userInput << " with flag of " << flag << " and flag 2 of " << flag2 << endl;
            cout << "Running Quicksort";
            if (flag == 2)
            {
                cout << " with local printing." << endl;
            }
            else 
            {
                cout << " without local printing." << endl;
            }
            if(flag2 == 2)
            {
                cout << "See file QuickSortedNumberArraySize" << randomArraySize << ".txt to see the sorted array." << endl;
            }
            quickArray = quickSorter(randomArraySize, quickArray, flag, flag2);
        }
        else if(userInput == 'H' || userInput == 'h')
        {
            heapArray = new int[randomArraySize]; //dynamically allocate memory to array of given size
            memcpy(heapArray, randomArray, randomArraySize * sizeof(int));
            cout << "COMMAND: " << userInput << " with flag of " << flag << " and flag 2 of " << flag2 << endl;
            cout << "Running Heapsort";
            if (flag == 2)
            {
                cout << " with local printing." << endl;
            }
            else 
            {
                cout << " without local printing." << endl;
            }
            if(flag2 == 2)
            {
                cout << "See file HeapSortedNumberArraySize" << randomArraySize << ".txt to see the sorted array." << endl;
            }
            heapArray = heapSorter(randomArraySize, heapArray, flag, flag2);
        }
        else if(userInput == 'M' || userInput == 'm')
        {
            mergeArray = new int[randomArraySize]; //dynamically allocate memory to array of given size
            memcpy(mergeArray, randomArray, randomArraySize * sizeof(int));
            cout << "COMMAND: " << userInput << " with flag of " << flag << " and flag 2 of " << flag2 << endl;
            cout << "Running Merge-sort";
            if (flag == 2)
            {
                cout << " with local printing." << endl;
            }
            else 
            {
                cout << " without local printing." << endl;
            }
            if(flag2 == 2)
            {
                cout << "See file MergeSortedNumberArraySize" << randomArraySize << ".txt to see the sorted array." << endl;
            }
            mergeArray = mergeSorter(randomArraySize, mergeArray, flag, flag2);
        }
        else if(userInput == 'I' || userInput == 'i')
        {
            insertionArray = new int[randomArraySize]; //dynamically allocate memory to array of given size
            memcpy(insertionArray, randomArray, randomArraySize * sizeof(int));
            cout << "COMMAND: " << userInput << " with flag of " << flag << " and flag 2 of " << flag2 << endl;
            cout << "Running Insertion-sort";
            if (flag == 2)
            {
                cout << " with local printing." << endl;
            }
            else 
            {
                cout << " without local printing." << endl;
            }
            if(flag2 == 2)
            {
                cout << "See file InsertionSortedNumberArraySize" << randomArraySize << ".txt to see the sorted array." << endl;
            }
            insertionArray = insertionSorter(randomArraySize, insertionArray, flag, flag2);
        }
        else if(userInput == 'B' || userInput == 'b')
        {
            bubbleArray = new int[randomArraySize]; //dynamically allocate memory to array of given size
            memcpy(bubbleArray, randomArray, randomArraySize * sizeof(int));
            cout << "COMMAND: " << userInput << " with flag of " << flag << " and flag 2 of " << flag2 << endl;
            cout << "Running Bubble-sort";
            if (flag == 2)
            {
                cout << " with local printing." << endl;
            }
            else 
            {
                cout << " without local printing." << endl;
            }
            if(flag2 == 2)
            {
                cout << "See file BubbleSortedNumberArraySize" << randomArraySize << ".txt to see the sorted array." << endl;
            }
            bubbleArray = bubbleSorter(randomArraySize, bubbleArray, flag, flag2);
        }
        else if(userInput == 'C' || userInput == 'c')
        {
            cout << "COMMAND: " << userInput << endl;
            cout << "Running comparisons" << endl;
            if(quickArray == nullptr || heapArray == nullptr || mergeArray == nullptr || insertionArray == nullptr || bubbleArray == nullptr)
            {
                cout << "can't compare what doesn't exist" << endl;
            }
            else
            {
                comparisonTool(randomArraySize, quickArray, heapArray, mergeArray, insertionArray, bubbleArray);
            }
        }
        else if(userInput == 'R' || userInput == 'r')
        {
            cout << "COMMAND: " << userInput << flag2 << endl;
            globalTimerObject->rank(flag2);
        }
        else if(userInput == 'F' || userInput == 'f')
        {
            cout << "COMMAND: " << userInput << endl;
            cout << "Flag controls printing to terminal (1 don't print or 2 print). Note files are always created as well." << endl;
            cout << "Flag2 controls writing a file (1 don't write or 2 write). This is to avoid creating massive files for large arrays." << endl;
            cout << "N #1 #2 #3 - creates new random array with #1 size. #2 is flag. #3 is flag2." << endl;
            cout << "Q #1 #2 - run quicksort on array and time it. #1 is flag. #2 is flag2." << endl;
            cout << "H #1 #2 - run heapsort on array and time it. #1 is flag. #2 is flag2." << endl;
            cout << "M #1 #2 - run merge-sort on array and time it. #1 is flag. #2 is flag2." << endl;
            cout << "I #1 #2 - run insertion-sort on array and time it. #1 is flag. #2 is flag2." << endl;
            cout << "B #1 #2 - run bubble-sort on array and time it. #1 is flag. #2 is flag2." << endl;
            cout << "C - compare sorted arrays (must have run all sorts) to see if results are the same." << endl;
            cout << "R #1 - compare sorted arrays (must have run all sorts) to see if results are the same. #1 is flag2." << endl;
            cout << "A #1 #2 - screw it run all the sorts! (don't do this with a large array because bubble). #1 is flag. #2 is flag2." << endl;
            cout << "D #1 #2 - run all sorts on a reverse sorted array. #1 is flag. #2 is flag2." << endl;
            cout << "S - stops program" << endl;
        }
        else if(userInput == 'A' || userInput == 'a')
        {
            quickArray = new int[randomArraySize]; //dynamically allocate memory to array of given size
            memcpy(quickArray, randomArray, randomArraySize * sizeof(int));
            heapArray = new int[randomArraySize]; //dynamically allocate memory to array of given size
            memcpy(heapArray, randomArray, randomArraySize * sizeof(int));
            mergeArray = new int[randomArraySize]; //dynamically allocate memory to array of given size
            memcpy(mergeArray, randomArray, randomArraySize * sizeof(int));
            insertionArray = new int[randomArraySize]; //dynamically allocate memory to array of given size
            memcpy(insertionArray, randomArray, randomArraySize * sizeof(int));
            bubbleArray = new int[randomArraySize]; //dynamically allocate memory to array of given size
            memcpy(bubbleArray, randomArray, randomArraySize * sizeof(int));

            cout << "COMMAND: " << userInput << " with flag of " << flag << " and flag 2 of " << flag2 << endl;
            cout << "Running all 5 sorts";
            if (flag == 2)
            {
                cout << " with local printing." << endl;
            }
            else 
            {
                cout << " without local printing." << endl;
            }
            if(flag2 == 2)
            {
                cout << "See file {Algorithm}SortedNumberArraySize" << randomArraySize << ".txt to see the sorted array." << endl;
            }
            
            quickArray = quickSorter(randomArraySize, quickArray, flag, flag2);
            heapArray = heapSorter(randomArraySize, heapArray, flag, flag2);
            mergeArray = mergeSorter(randomArraySize, mergeArray, flag, flag2);
            insertionArray = insertionSorter(randomArraySize, insertionArray, flag, flag2);
            bubbleArray = bubbleSorter(randomArraySize, bubbleArray, flag, flag2);
        }
        else if(userInput == 'D' || userInput == 'd')
        {
            int dumbArray[] = {99844,97960,94989,94342,94180,94152,92450,91546,87601,87131,86687,85895,85593,85148,85081,84511,83984,82841,81469,81130,81099,80949,80874,80853,80424,79553,77509,76817,75864,74653,73874,73601,72952,70768,70334,70259,70102,66613,65942,64018,63919,63101,62820,62452,61661,59955,59528,55933,55197,54729,53637,53471,53024,52279,51850,51465,51272,51088,48174,46952,46298,45973,45748,41813,41107,39545,38401,37077,36588,35811,33358,32524,29174,29060,29034,27453,27213,25157,23979,23324,21935,21419,21246,20560,20250,18479,18328,17146,16816,16587,13517,12064,10939,7674,5520,2313,2265,1518,1304};
            
            quickArray = new int[100]; //dynamically allocate memory to array of given size
            memcpy(quickArray, dumbArray, 100 * sizeof(int));
            heapArray = new int[100]; //dynamically allocate memory to array of given size
            memcpy(heapArray, dumbArray, 100 * sizeof(int));
            mergeArray = new int[100]; //dynamically allocate memory to array of given size
            memcpy(mergeArray, dumbArray, 100 * sizeof(int));
            insertionArray = new int[100]; //dynamically allocate memory to array of given size
            memcpy(insertionArray, dumbArray, 100 * sizeof(int));
            bubbleArray = new int[100]; //dynamically allocate memory to array of given size
            memcpy(bubbleArray, dumbArray, 100 * sizeof(int));

            cout << "COMMAND: " << userInput << " with flag of " << flag << " and flag 2 of " << flag2 << endl;
            cout << "Running all 5 sorts";
            if (flag == 2)
            {
                cout << " with local printing." << endl;
            }
            else 
            {
                cout << " without local printing." << endl;
            }
            if(flag2 == 2)
            {
                cout << "See file {Algorithm}SortedNumberArraySize" << 100 << ".txt to see the sorted array." << endl;
            }
            
            quickArray = quickSorter(100, quickArray, flag, flag2);
            heapArray = heapSorter(100, heapArray, flag, flag2);
            mergeArray = mergeSorter(100, mergeArray, flag, flag2);
            insertionArray = insertionSorter(100, insertionArray, flag, flag2);
            bubbleArray = bubbleSorter(100, bubbleArray, flag, flag2);
        }
        else if(userInput == 'E' || userInput == 'e')
        {
            int dumbArray[] = {0,1304,1518,2265,2313,5520,7674,10939,12064,13517,16587,16816,17146,18328,18479,20250,20560,21246,21419,21935,23324,23979,25157,27213,27453,29034,29060,29174,32524,33358,35811,36588,37077,38401,39545,41107,41813,45748,45973,46298,46952,48174,51088,51272,51465,51850,52279,53024,53471,53637,54729,55197,55933,59528,59955,61661,62452,62820,63101,63919,64018,65942,66613,70102,70259,70334,70768,72952,73601,73874,74653,75864,76817,77509,79553,80424,80853,80874,80949,81130,81469,82841,83984,84511,85081,85148,85593,85895,86687,87131,87601,91546,92450,94152,94180,94342,94989,97960,99844};
            
            quickArray = new int[100]; //dynamically allocate memory to array of given size
            memcpy(quickArray, dumbArray, 100 * sizeof(int));
            heapArray = new int[100]; //dynamically allocate memory to array of given size
            memcpy(heapArray, dumbArray, 100 * sizeof(int));
            mergeArray = new int[100]; //dynamically allocate memory to array of given size
            memcpy(mergeArray, dumbArray, 100 * sizeof(int));
            insertionArray = new int[100]; //dynamically allocate memory to array of given size
            memcpy(insertionArray, dumbArray, 100 * sizeof(int));
            bubbleArray = new int[100]; //dynamically allocate memory to array of given size
            memcpy(bubbleArray, dumbArray, 100 * sizeof(int));

            cout << "COMMAND: " << userInput << " with flag of " << flag << " and flag 2 of " << flag2 << endl;
            cout << "Running all 5 sorts";
            if (flag == 2)
            {
                cout << " with local printing." << endl;
            }
            else 
            {
                cout << " without local printing." << endl;
            }
            if(flag2 == 2)
            {
                cout << "See file {Algorithm}SortedNumberArraySize" << 100 << ".txt to see the sorted array." << endl;
            }
            
            quickArray = quickSorter(100, quickArray, flag, flag2);
            heapArray = heapSorter(100, heapArray, flag, flag2);
            mergeArray = mergeSorter(100, mergeArray, flag, flag2);
            insertionArray = insertionSorter(100, insertionArray, flag, flag2);
            bubbleArray = bubbleSorter(100, bubbleArray, flag, flag2);
        }
    }
    if(randomArray != NULL) //delete randomArray
    {
        delete[] randomArray;
    }
    exit(0); //EXIT_SUCCESS terminate program
}

int* quickSorter(int arraySize, int arrayToSort[], int flag, int flag2)
{
    auto quickStart = high_resolution_clock::now();
    Quick localQuickObject;
    int* sortedArray = nullptr;

    localQuickObject.initialize(arraySize, arrayToSort);
    
    auto quickSortStart = high_resolution_clock::now();
    localQuickObject.quickSort(0,arraySize-1);
    auto quickSortStop = high_resolution_clock::now();
    auto quickSortDuration = duration_cast<microseconds>(quickSortStop - quickSortStart);
    cout << "Time Taken (quick-sort only): " << quickSortDuration.count() << " microseconds" << endl;

    auto quickStop = high_resolution_clock::now();
    auto quickTotalDuration = duration_cast<microseconds>(quickStop - quickStart);
    cout << "Time Taken (whole thing): " << quickTotalDuration.count() << " microseconds" << endl;

    sortedArray = localQuickObject.quickSortReturn();

    if(flag == 2)
    {
        cout << "result" << endl;
        for(int i = 0; i < arraySize; i++)
        {
            cout << sortedArray[i] << endl;
        }
    }

    if(flag2 == 2)
    {
        sortFileOutput("Quick", arraySize, quickTotalDuration.count(), quickSortDuration.count(), sortedArray);
    }
    
    globalTimerObject->updateTimes(quickTotalDuration.count(), quickSortDuration.count(), "Quick");
    return sortedArray;
}

int* heapSorter(int arraySize, int arrayToSort[], int flag, int flag2)
{
    auto heapStart = high_resolution_clock::now();
    Heap* localHeap = nullptr; //localHeap object pointer
    struct Element* localHeapArray = nullptr; //pointer to localHeapArray
    int currentInput = 0;
    int* sortedArray = nullptr;
    
    //create empty heap
    if(localHeap) //if localHeap already initialized delete existing one
    {
        localHeap->deleteHeap(localHeap); //delete localHeap
    }
    
    if(arraySize >= 0) //if valid size (this is setting the capacity not size though the two should be the same here)
    {
        localHeap = localHeap->initialize(arraySize+1);
    }
    else
    {
        cout << "Error: invalid heap capacity" << endl;
    }

    //read the array
    if(localHeap) //if heap has been initialized using C (ie pointer isn't null)
    {
        if(localHeap->getCapacity() >= arraySize+1) //if capacity of existing heap is valid
        {
            if(localHeapArray) //if a heapArray already exists delete the existing one
            {
                Element* temp = localHeapArray;
                if(temp != nullptr)
                {
                    delete[] temp;
                }
            }
            localHeapArray = new (nothrow) Element[arraySize+1]; //dynamically allocate memory to local heap array of size from txt file
            if (localHeapArray == nullptr) //catch error if heapArray can't be created
            {
                cout << "Memory not allocated for array localHeapArray\n";
            }
            else //safe to create heap
            {
                // int brokenArray[] = {1,2,3,3,0,3,3,1,3,1,4,1,3,4,4,0,0,3,0,1};
                // int brokenArray2[] = {2,0,4,0,2};
                for(int i = 0; i <= arraySize+1; i++) //loop through the heapArraySize ints to create the array
                {
                    currentInput = arrayToSort[i]; //reset input value to be safe
                    // currentInput = brokenArray[i]; //reset input value to be safe
                    // currentInput = brokenArray2[i]; //reset input value to be safe
                    localHeapArray[i+1].key = currentInput; //pass into localHeapArray
                }
                localHeap->buildHeap(localHeap, localHeapArray, arraySize+1); //run buildHeap on the array
            }
        }
        else
        {
            cout << "Error: array size exceeds heap capacity" << endl;
        }
    }
    else //else heap wasn't intialized
    {
        cout << "Error: heap not initialized" << endl;
    }

    //print the regular heap
    // cout << "regular heap";
    // localHeap->printHeap(localHeap);
    
    auto heapSortStart = high_resolution_clock::now();
    //run heap sort
    localHeap->heapSort(localHeap);
    auto heapSortStop = high_resolution_clock::now();
    auto heapSortDuration = duration_cast<microseconds>(heapSortStop - heapSortStart);
    cout << "Time Taken (heapsort only): " << heapSortDuration.count() << " microseconds" << endl;

    auto heapStop = high_resolution_clock::now();
    auto heapTotalDuration = duration_cast<microseconds>(heapStop - heapStart);
    cout << "Time Taken (whole thing): " << heapTotalDuration.count() << " microseconds" << endl;
    
    sortedArray = localHeap->heapSortReturn(localHeap, arraySize);

    if(flag == 2)
    {
        cout << "result" << endl;
        for(int i = 0; i < arraySize; i++)
        {
            cout << sortedArray[i] << endl;
        }
    }
    
    if(flag2 == 2)
    {
        sortFileOutput("Heap", arraySize, heapTotalDuration.count(), heapSortDuration.count(), sortedArray);
    }

    if(localHeapArray != NULL) //delete localHeapArray
    {
        delete[] localHeapArray;
    }
    localHeap->deleteHeap(localHeap); //delete localHeap
    
    globalTimerObject->updateTimes(heapTotalDuration.count(), heapSortDuration.count(), "Heap");
    return sortedArray;

}

int* mergeSorter(int arraySize, int arrayToSort[], int flag, int flag2)
{
    // Timer mergeTotal;
    auto mergeStart = high_resolution_clock::now();
    // int arrayIndex1[arraySize+1];
    // for(int i = 0; i < arraySize+1; i++)
    // {
    //     arrayIndex1[i+1] = arrayToSort[i];
    // }
    int* sortedArray = nullptr;
    Merge localMergeObject;
    
    localMergeObject.initialize(arraySize, arrayToSort);
    // localMergeObject.initialize(arraySize+1, arrayIndex1);

    // Timer mergeSortOnly;
    auto mergeSortStart = high_resolution_clock::now();
    localMergeObject.mergeSort(0,arraySize-1);
    // localMergeObject.mergeSort(0,arraySize);
    auto mergeSortStop = high_resolution_clock::now();
    auto mergeSortDuration = duration_cast<microseconds>(mergeSortStop - mergeSortStart);
    cout << "Time Taken (merge-sort only): " << mergeSortDuration.count() << " microseconds" << endl;
    // cout << "Time Taken (merge-sort only with timer class thing): " << mergeSortOnly.elapsed() << " microseconds" << endl;

    auto mergeStop = high_resolution_clock::now();
    auto mergeTotalDuration = duration_cast<microseconds>(mergeStop - mergeStart);
    cout << "Time Taken (whole thing): " << mergeTotalDuration.count() << " microseconds" << endl;
    // cout << "Time taken (whole thing with timer class thing): " << mergeTotal.elapsed() << " seconds" << endl;

    sortedArray = localMergeObject.mergeSortReturn();

    if(flag == 2)
    {
        cout << "result" << endl;
        // for(int i = 1; i <= arraySize; i++)
        for(int i = 0; i < arraySize; i++)
        {
            cout << sortedArray[i] << endl;
        }
    }

    if(flag2 == 2)
    {
        sortFileOutput("Merge", arraySize, mergeTotalDuration.count(), mergeSortDuration.count(), sortedArray);
    }

    globalTimerObject->updateTimes(mergeTotalDuration.count(), mergeSortDuration.count(), "Merge");
    return sortedArray;
}

int* insertionSorter(int arraySize, int arrayToSort[], int flag, int flag2)
{
    // Timer insertionTotal;
    auto insertionStart = high_resolution_clock::now();
    Insertion localInsertionObject;
    int* sortedArray = nullptr;

    localInsertionObject.initialize(arraySize, arrayToSort);
    
    // Timer insertionSortOnly;
    auto insertionSortStart = high_resolution_clock::now();
    localInsertionObject.insertionSort();
    auto insertionSortStop = high_resolution_clock::now();
    auto insertionSortDuration = duration_cast<microseconds>(insertionSortStop - insertionSortStart);
    cout << "Time Taken (insertion-sort only): " << insertionSortDuration.count() << " microseconds" << endl;
    // cout << "Time Taken (merge-sort only with timer class thing): " << insertionSortOnly.elapsed() << " microseconds" << endl;

    auto insertionStop = high_resolution_clock::now();
    auto insertionTotalDuration = duration_cast<microseconds>(insertionStop - insertionStart);
    cout << "Time Taken (whole thing): " << insertionTotalDuration.count() << " microseconds" << endl;
    // cout << "Time taken (whole thing with timer class thing): " << insertionTotal.elapsed() << " seconds" << endl;

    sortedArray = localInsertionObject.insertionSortReturn();

    if(flag == 2)
    {
        cout << "result" << endl;
        for(int i = 0; i < arraySize; i++)
        {
            cout << sortedArray[i] << endl;
        }
    }

    if(flag2 == 2)
    {
        sortFileOutput("Insertion", arraySize, insertionTotalDuration.count(), insertionSortDuration.count(), sortedArray);
    }
    
    globalTimerObject->updateTimes(insertionTotalDuration.count(), insertionSortDuration.count(), "Insertion");
    return sortedArray;
}

int* bubbleSorter(int arraySize, int arrayToSort[], int flag, int flag2)
{
    auto bubbleStart = high_resolution_clock::now();
    Bubble localBubbleObject;
    int* sortedArray = nullptr;

    localBubbleObject.initialize(arraySize, arrayToSort);
    
    auto bubbleSortStart = high_resolution_clock::now();
    localBubbleObject.bubbleSort();
    auto bubbleSortStop = high_resolution_clock::now();
    auto bubbleSortDuration = duration_cast<microseconds>(bubbleSortStop - bubbleSortStart);
    cout << "Time Taken (bubble-sort only): " << bubbleSortDuration.count() << " microseconds" << endl;

    auto bubbleStop = high_resolution_clock::now();
    auto bubbleTotalDuration = duration_cast<microseconds>(bubbleStop - bubbleStart);
    cout << "Time Taken (whole thing): " << bubbleTotalDuration.count() << " microseconds" << endl;

    sortedArray = localBubbleObject.bubbleSortReturn();

    if(flag == 2)
    {
        cout << "result" << endl;
        for(int i = 0; i < arraySize; i++)
        {
            cout << sortedArray[i] << endl;
        }
    }

    if(flag2 == 2)
    {
        sortFileOutput("Bubble", arraySize, bubbleTotalDuration.count(), bubbleSortDuration.count(), sortedArray);
    }
    
    globalTimerObject->updateTimes(bubbleTotalDuration.count(), bubbleSortDuration.count(), "Bubble");
    return sortedArray;
}

void sortFileOutput(string sortType, int arraySize, int timeTotal, int timeSort, int arrayOutput[])
{
    string fileOutName =  sortType + "SortedNumberArraySize" + to_string(arraySize) + ".txt";
    ofstream outFileVar; //file variable for saving
	outFileVar.open(fileOutName); //open a file called RandomNumberArraySizeN.txt
	if(outFileVar.is_open()) //check file is open
	{
		outFileVar << "Total time taken (entire algorithm): " << timeTotal << endl;
		outFileVar << "Time taken for " << sortType << " Sort: " << timeSort << endl;
        for(int i = 0; i < arraySize; i++) //loop through the n ints storing the array
		{
			outFileVar << arrayOutput[i]; //store current array value
			if(i != arraySize-1) // don't add the line break on last execution to match original file format
			{
				outFileVar << "\n"; //line break to file
			}
		}
		outFileVar.close(); //close file
	}
	else //else file is closed
	{
		cout << "File called \"output.txt\" can not be opened for writing!\n";
	}
}

void comparisonTool(int arraySize, int* quickArray, int* heapArray, int* mergeArray, int* insertionArray, int* bubbleArray)
{
    bool filesAreEqual = true;
    for(int i = 0; i < arraySize; i++)
    {
        if((heapArray[i] != quickArray[i]) || (heapArray[i]!= mergeArray[i]) || (heapArray[i] != insertionArray[i])  || (heapArray[i] != bubbleArray[i]))
        {
            cout << "Error at i = " << i << endl;
            cout << heapArray[i] << endl << quickArray[i] << endl << mergeArray[i] << endl << insertionArray[i] << endl << bubbleArray[i] << endl;
            filesAreEqual = false;
            break;
        }
    }
    
    if(filesAreEqual)
    {
        cout << "The sorted arrays of all 5 algorithms are the same." <<endl;
    }
}

void randomArrayfileOutput(int arraySize, int arrayOutput[])
{
    string fileOutName = "RandomNumberArraySize" + to_string(arraySize) + ".txt";
    ofstream outFileVar; //file variable for saving
	outFileVar.open(fileOutName); //open a file called RandomNumberArraySizeN.txt
	if(outFileVar.is_open()) //check file is open
	{
		for(int i = 0; i < arraySize; i++) //loop through the n ints storing the random array
		{
			outFileVar << arrayOutput[i]; //store current array value
			if(i != arraySize-1) // don't add the line break on last execution to match original file format
			{
				outFileVar << "\n"; //line break to file
			}
		}
		outFileVar.close(); //close file
	}
	else //else file is closed
	{
		cout << "File called \"output.txt\" can not be opened for writing!\n";
	}
}

int* randomArrayGenerator(int arraySize)
{
    int randomNumber = 0;
    int* inputArray = nullptr;
    inputArray = new (nothrow) int[arraySize]; //dynamically allocate memory to array of given size
    if (inputArray == nullptr) //catch error
    {
        cout << "Memory not allocated for array" << endl;
    }

    for(int i = 0; i < arraySize; i++)
    {
        // randomNumber = rand() % 1000000000;
        // randomNumber = rand() % 100000000;
        // randomNumber = rand() % 10000000;
        // randomNumber = rand() % 1000000;
        randomNumber = rand() % 100000;
        // randomNumber = rand() % 5;
        inputArray[i] = randomNumber;
    }
    return inputArray;
}

char nextCommand(int* flag, int* flag2, int* keyValue, int* size)
{
    char userInput = 'Z'; //initialize to a dummy letter

    while(1)
    {
        scanf("%c", &userInput); //read in the char userInput
        if(userInput == ' ' || userInput == '\t' || userInput == '\n' || userInput == '\r') //if user enters a non-valid character pass back the dummy char to skip an iteration of the command interface
        {
            userInput = 'Z'; //set to dummy char and return
            return userInput;
        }
        if(userInput == 'S' || userInput == 's') //stop command S
        {
            return userInput; //if stop just pass the char S
        }
        else if(userInput == 'N' || userInput == 'n') //generate random array command
        {
            scanf("%d", size); //read in size
            scanf("%d", flag); //read in flag
            scanf("%d", flag2); //read in flag2
            return userInput; //return char N
        }
        else if(userInput == 'Q' || userInput == 'q') //quick sorter
        {
            scanf("%d", flag); //read in flag
            scanf("%d", flag2); //read in flag2
            return userInput;
        }
        else if(userInput == 'H' || userInput == 'h') //heap sorter
        {
            scanf("%d", flag); //read in flag
            scanf("%d", flag2); //read in flag2
            return userInput;
        }
        else if(userInput == 'M' || userInput == 'm') //merge sorter
        {
            scanf("%d", flag); //read in flag
            scanf("%d", flag2); //read in flag2
            return userInput;
        }
        else if(userInput == 'I' || userInput == 'i') //insertion sorter
        {
            scanf("%d", flag); //read in flag
            scanf("%d", flag2); //read in flag2
            return userInput;
        }
        else if(userInput == 'B' || userInput == 'b') //bubble sorter
        {
            scanf("%d", flag); //read in flag
            scanf("%d", flag2); //read in flag2
            return userInput;
        }
        else if(userInput == 'C' || userInput == 'c') //comparison tool
        {
            return userInput;
        }
        else if(userInput == 'R' || userInput == 'r') //rank tool
        {
            scanf("%d", flag2); //read in flag2
            return userInput;
        }
        else if(userInput == 'F' || userInput == 'f') //rank tool
        {
            return userInput;
        }
        else if(userInput == 'A' || userInput == 'a') //all sorter
        {
            scanf("%d", flag); //read in flag
            scanf("%d", flag2); //read in flag2
            return userInput;
        }
        else if(userInput == 'D' || userInput == 'd') //reverse array case
        {
            scanf("%d", flag); //read in flag
            scanf("%d", flag2); //read in flag2
            return userInput;
        }
        else if(userInput == 'E' || userInput == 'e') //sorted array case
        {
            scanf("%d", flag); //read in flag
            scanf("%d", flag2); //read in flag2
            return userInput;
        }
        else //any other possible letters entered just return dummy char
        {
            userInput = 'Z'; //set to a dummy letter
            return userInput;
        }
    }
}