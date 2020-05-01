/**
 * @file heap.cpp
 * @author Ethan Gilchrist (egilchr1@asu.edu)
 * @brief The heap program constructs a heap object with an array of type element. It is the driving part of the program that stores all of the necessary parts for a max-heap. This is the implementation.
 * @version 0.1
 * @date 2020-03-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "heap.h" //include the heap header
#include <limits> //include the numerical limits for negative infinity use
#include <iostream> //include the basic input output stream
#include <cmath> //include the math class for use of log base 2 and exponents

//include some standard namespace utilities
using std::cout;
using std::endl;
using std::numeric_limits;

/**
 * @brief Element is a data type that contains a field named key, which is of type int.
 * 
 */
struct Element;

/**
 * @brief Construct a new Heap:: Heap object. Sets capacity to realCapacity, sets size to 0, and creates an Element array of size realCapacity.
 * 
 * @param realCapacity 
 */
Heap::Heap(int realCapacity) //constructor
{
	this->capacity = realCapacity;
    this->size = 0;
    this->H = new Element[realCapacity];
}

/**
 * @brief Initialize(inputSize) returns an object of type Heap with capacity inputSize and size 0. This function performs dynamic memory allocation according to the demand inputSize.
 * 
 * @param inputSize 
 * @return Heap* 
 */
Heap* Heap::initialize(int inputSize) //initialize heap to inputSize
{
    Heap* newHeap = new Heap(inputSize);
    return newHeap;
}

/**
 * @brief BuildHeap(heapObject, heapArray, heapArraySize), where heapObject is a Heap object, heapArray is an array of type Element, and heapArraySize is the size of array heapArray. This function copies the elements in heapArray into heapObject->H (starting from H[1] and uses the linear time build heap algorithm to obtain a max-heap of size n from the given array heapArray.
 * 
 * @param heapObject 
 * @param heapArray 
 * @param heapArraySize 
 */
void Heap::buildHeap(Heap* heapObject, struct Element* heapArray, int heapArraySize) //build a max-heap
{
    //if using base index of 0 for(int i = 0; i < heapArraySize; i++)
    for(int i = 1; i <= heapArraySize; i++) //Loop across the starting index 1 to and including the size (because we write to the size index)
    {
        heapObject->H[i].key = heapArray[i].key; //transfer the heapArray elements into heapObject->H
    }
    //if using base index of 0 for(int i = heapArraySize/2; i >= 0; i--)
    for(int i = heapArraySize/2; i >= 1; i--) //loop across the first nonleaf node down to the first element running max-heapify each time
    {
        maxHeapify(heapObject->H, i, heapArraySize-1); //decrement heapsize because we bring in a size one too large to account for the base index being 1
    }
    heapObject->size = heapArraySize-1; //set size in the heapObject to -1 of the input size because the input is 1 greater in main due to us using a starting index of 1
}

/**
 * @brief Insert(heapObject, flag, keyValue) inserts an element with key equal to keyValue into the max-heap heapObject. When flag=1, no additional printing. When flag=2, the function prints out the heap content before and after the insertion.
 * 
 * @param heapObject 
 * @param flag 
 * @param keyValue 
 */
void Heap::insert(Heap* heapObject, int flag, int keyValue) //insert a value into heap
{
    if(flag == 2)
    {
        cout << "Before insert operation:" << endl;
        printHeap(heapObject);
    }
    if(!(heapObject->size < heapObject->capacity-1)) //check if there's room if there isn't increase the size to nearest power of 2. If index of 0 use >= heap->capacity-1
    {
        int exponent = ceil(log2(heapObject->size+1)); //get the closest base 2 power for a new size by using log2
        int newCapacity = pow(2,exponent)+1; //use 2 to the exponent to get the correct new capacity. Increase it by 1 because write from base index 1
        heapObject->capacity = newCapacity;
        Element* temp = heapObject->H; //store the old array for copying from and deletion
        heapObject->H = new Element[newCapacity];
        for (int i = 1; i <= heapObject->size; i++) //copy old elements of array
        {
            heapObject->H[i].key = temp[i].key;
        }
        if (temp != NULL) //delete temp
        {
            delete[] temp;
        }
    }
    heapObject->size++; //increment size for storing new element
    heapObject->H[heapObject->size].key = numeric_limits<int>::min(); //Set the new element to be negative infinity for shifting. If index of 0 use heap->H[heap->size-1].key
    increaseKey(heapObject, 1, heapObject->size, keyValue); //Run increase key to get the keyValue where it needs to be by comparing with the negative infinity element. if index of 0 use heap->size-1
    if(flag == 2)
    {
        cout << "After insert operation:" << endl;
        printHeap(heapObject);
    }
}

/**
 * @brief DeleteMax(heapObject, flag) deletes the element with maximum key and returns the element. When flag=1, no additional printing. When flag=2, the function prints out the heap content before and after the deletion.
 * 
 * @param heapObject 
 * @param flag 
 * @return int 
 */
int Heap::deleteMax(Heap* heapObject, int flag) //delete max from heap
{
    if(flag == 2)
    {
        cout << "Before delete max operation:" << endl;
        printHeap(heapObject);
    }
    int max = -1; //initialize max to dummy value
    if(heapObject->size < 1) //Check if the size of heap is valid. if index of 0 use if(heap->size < 0)
    {
        cout << "Error: heap underflow no values to be extracted";
    }
    else
    {
        max = heapObject->H[1].key; //Set max to the first element. if using index of 0 max = heap->H[0].key;
        heapObject->H[1].key = heapObject->H[heapObject->size].key; //Set the max key value to the smallest element. if using index of 0 heap->H[0].key = heap->H[heap->size-1].key;
        heapObject->size--;
        maxHeapify(heapObject->H, 1, heapObject->size); //Run maxHeapify to get the array in the correct order again. if using index of 0 maxHeapify(heap->H, 0, heap->size);
        if(flag == 2)
        {
            cout << "After delete max operation:" << endl;
            printHeap(heapObject);
        }
    }
    return max; //return the max
}

/**
 * @brief IncreaseKey(heapObject, flag, index, keyValue) identifies an element at index and increases its key to the keyValue. It does so in the heapObject. It uses flag to determine if printing results before and after of operation.
 * 
 * @param heapObject 
 * @param flag 
 * @param index 
 * @param keyValue 
 */
void Heap::increaseKey(Heap* heapObject, int flag, int index, int keyValue) //increase a value at index to new keyValue
{
    if((index < 1) || (index > heapObject->size)) //if index is outside of range from 1 to and including size
    {
        cout << "Error: invalid index" << endl;
    }
    else if(keyValue < heapObject->H[index].key) //if the new key is smaller than current key
    {
        cout << "Error: new key is smaller than current key" << endl;
    }
    else
    {
        if(flag == 2)
        {
            cout << "Before increase key operation:" << endl;
            printHeap(heapObject);
        }
        int temp = -1; //store dummy value
        heapObject->H[index].key = keyValue; //set index to the new value
        //if index of 0 while((index > 0) && (heap->H[parent(index)].key < heap->H[index].key))
        while((index > 1) && (heapObject->H[parent(index)].key < heapObject->H[index].key)) //while index is valid and the parent is smaller than child
        {
            //swap A[i] and A[parent(i)]
            temp = heapObject->H[index].key;
            heapObject->H[index].key = heapObject->H[parent(index)].key;
            heapObject->H[parent(index)].key = temp;
            index = parent(index); //set index to new proper parent value
        }
        if(flag == 2)
        {
            cout << "After increase key operation:" << endl;
            printHeap(heapObject);
        }
    }
}

/**
 * @brief printHeap(heapObject) prints out the heap information including capacity, size, and the key fields of the elements in the array with index going from 1 to size.
 * 
 * @param heapObject 
 */
void Heap::printHeap(Heap* heapObject) //print heap
{
    cout << "Capacity = " << heapObject->capacity-1 << endl; //decrease capacity when printing because its 1 element greater due to using a base index of 1
    cout << "Size = " << heapObject->size << endl;
    for(int i = 1; i <= heapObject->size; i++) //Loop across elements from 1 to and including size printing the keys. if index of 0 for(int i = 0; i < heap->size; i++)
    {
        cout << heapObject->H[i].key << endl;
    }
}


/**
 * @brief MaxHeapify(heapArray, index, heapSize) maintains the max-heap property. It does so on the heapArray with size heapSize on the specified index. It floats the value at index down to the correct space in the heap.
 * 
 * @param heapArray 
 * @param index 
 * @param heapSize 
 */
void Heap::maxHeapify(struct Element* heapArray, int index, int heapSize) //maintains max-heap property
{
    int leftIndex = left(index);
    int rightIndex = right(index);
    int largest = -1; //initialize to dummy value
    
    // heapSize--; //decremnt heapsize because we bring in a size one too large to account for the base index being 1
    
    //if index of 0 use if((leftIndex < heapSize) && (heapArray[leftIndex].key > heapArray[index].key))
    if((leftIndex <= heapSize) && (heapArray[leftIndex].key > heapArray[index].key)) //if the left index is valid and the left key is greater than current index
    {
        largest = leftIndex;
    }
    else //assume the index is current largest
    {
        largest = index;
    }
    //if index of 0 use if((rightIndex < heapSize) && (heapArray[rightIndex].key > heapArray[largest].key))
    if((rightIndex <= heapSize) && (heapArray[rightIndex].key > heapArray[largest].key)) //if right index is valid and right key is greater than current index
    {
        largest = rightIndex;
    }
    if(largest != index) // if largest is not the index
    {
        //swap A[i] and A[largest]
        int temp = heapArray[index].key; //store current index key in temp and do the swap
        heapArray[index].key = heapArray[largest].key;
        heapArray[largest].key = temp;
        maxHeapify(heapArray, largest, heapSize); //run max-heapify based on this swap
    }
}

/**
 * @brief Parent(index) returns the parent of the index
 * 
 * @param index 
 * @return int 
 */
int Heap::parent(int index) //returns the parent of current index
{
    // if index of 0 return (index-1)/2;
    return index/2;
}

/**
 * @brief Left(index) returns the left child of current index
 * 
 * @param index 
 * @return int 
 */
int Heap::left(int index) //returns the left child of current index
{
    //if index of 0 return (2*index)+1;
    return 2*index;
}

/**
 * @brief Right(index) returns the right child of current index
 * 
 * @param index 
 * @return int 
 */
int Heap::right(int index) //returns the right child of current index
{
    //if index of 0 return (2*index)+2;
    return (2*index)+1;
}

/**
 * @brief GetCapacity() returns the heap capacity
 * 
 * @return int 
 */
int Heap::getCapacity() //returns the capacity of heap
{
    return this->capacity;
}

/**
 * @brief GetSize() returns the heap size
 * 
 * @return int 
 */
int Heap::getSize() //returns the size of heap
{
    return this->size;
}

/**
 * @brief DeleteHeap(heapObject) is a function to assist the main that will delete the given heapObject for main. Note it's not really a destructor just an assistive delete function, so we don't have to write a getter for the heapObject->H and delete that in main.
 * 
 * @param heapObject 
 */
void Heap::deleteHeap(Heap* heapObject) //delete heap
{
    if(heapObject != nullptr) //if there is an object
    {
        delete[] heapObject->H; //delete the array
        delete heapObject; //delete heap itself
    }
}

/**
 * @brief 
 * 
 * @param heapObject 
 */
void Heap::heapSort(Heap* heapObject) //heap sort
{
    int temp = -1;
    int sizeTemp = 1;
    for(int i = heapObject->size; i >= 2; i--) //loop across the first nonleaf node down to the first element running max-heapify each time
    {
        //exchange A[1] and A[i]
        temp = heapObject->H[1].key;
        heapObject->H[1].key = heapObject->H[i].key;
        heapObject->H[i].key = temp;
        heapObject->size--;
        maxHeapify(heapObject->H, 1, heapObject->size);
        sizeTemp++;
    }
}

int* Heap::heapSortReturn(Heap* heapObject, int size) //heap sort
{
    int* sortedArray;
    sortedArray = new int[size];
    for(int i = 1; i <= size; i++)
    {
        sortedArray[i-1] = heapObject->H[i].key;
        // cout << heapObject->H[i].key << endl;
    }
    return sortedArray;
}