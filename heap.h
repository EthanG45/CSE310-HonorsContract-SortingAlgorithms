#ifndef _HEAP_H_
#define _HEAP_H_

/**
 * @file heap.h
 * @author Ethan Gilchrist (egilchr1@asu.edu)
 * @brief The heap program constructs a heap object with an array of type element. It is the driving part of the program that stores all of the necessary parts for a max-heap. This is the header.
 * @version 0.1
 * @date 2020-03-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief Element is a data type that contains a field named key, which is of type int.
 * 
 */
struct Element
{
    int key;
};

/**
 * @brief HEAP is a data type that contains three fields named capacity (of type int), size (of type int), and H (an array of type ELEMENT with index ranging from 0 to capacity though only index 1 to capacity are used).
 * 
 */
class Heap {
private:
    /**
     * @brief Capacity is an int that represents the number of elements possible in the heap. We have to increment it 1 past given inputs in order to work on index 1 to and including size.
     * 
     */
    int capacity;
    /**
     * @brief Size is an int that represents the number of elements currently in the heap.
     * 
     */
    int size;
    /**
     * @brief H is an element pointer for arrays of type element to store the actual heap key values.
     * 
     */
    struct Element* H;

public:
    /**
     * @brief Construct a new Heap:: Heap object. Sets capacity to realCapacity, sets size to 0, and creates an Element array of size realCapacity.
     * 
     * @param realCapacity 
     */
    Heap(int realCapacity); //constructor
    
    /**
     * @brief Initialize(inputSize) returns an object of type Heap with capacity inputSize and size 0. This function performs dynamic memory allocation according to the demand inputSize.
     * 
     * @param inputSize 
     * @return Heap* 
     */
    Heap* initialize(int inputSize); //initialize heap to size
    
    /**
     * @brief BuildHeap(heapObject, heapArray, heapArraySize), where heapObject is a Heap object, heapArray is an array of type Element, and heapArraySize is the size of array heapArray. This function copies the elements in heapArray into heapObject->H (starting from H[1] and uses the linear time build heap algorithm to obtain a max-heap of size n from the given array heapArray.
     * 
     * @param heapObject 
     * @param heapArray 
     * @param heapArraySize 
     */
    void buildHeap(Heap* heapObject, Element* heapArray, int heapArraySize); //build a max-heap
    
    /**
     * @brief Insert(heapObject, flag, keyValue) inserts an element with key equal to keyValue into the max-heap heapObject. When flag=1, no additional printing. When flag=2, the function prints out the heap content before and after the insertion.
     * 
     * @param heapObject 
     * @param flag 
     * @param keyValue 
     */
    void insert(Heap* heapObject, int flag, int keyValue); //insert a value into heap
    
    /**
     * @brief DeleteMax(heapObject, flag) deletes the element with maximum key and returns the element. When flag=1, no additional printing. When flag=2, the function prints out the heap content before and after the deletion.
     * 
     * @param heapObject 
     * @param flag 
     * @return int 
     */
    int deleteMax(Heap* heapObject, int flag); //delete max from heap
    
    /**
     * @brief IncreaseKey(heapObject, flag, index, keyValue) identifies an element at index and increases its key to the keyValue. It does so in the heapObject. It uses flag to determine if printing results before and after of operation.
     * 
     * @param heapObject 
     * @param flag 
     * @param index 
     * @param keyValue 
     */
    void increaseKey(Heap* heapObject, int flag, int index, int keyValue); //increase a value at index to new keyValue
    
    /**
     * @brief printHeap(heapObject) prints out the heap information including capacity, size, and the key fields of the elements in the array with index going from 1 to size.
     * 
     * @param heapObject 
     */
    void printHeap(Heap* heapObject); //print heap

    /**
     * @brief MaxHeapify(heapArray, index, heapSize) maintains the max-heap property. It does so on the heapArray with size heapSize on the specified index. It floats the value at index down to the correct space in the heap.
     * 
     * @param heapArray 
     * @param index 
     * @param heapSize 
     */
    void maxHeapify(Element* heapArray, int index, int heapSize); //maintains max-heap property

    /**
     * @brief Parent(index) returns the parent of the index
     * 
     * @param index 
     * @return int 
     */
    int parent(int index); //returns the parent of current index

    /**
     * @brief Left(index) returns the left child of current index
     * 
     * @param index 
     * @return int 
     */
    int left(int index); //returns the left child of current index
    
    /**
     * @brief Right(index) returns the right child of current index
     * 
     * @param index 
     * @return int 
     */
    int right(int index); //returns the right child of current index
    
    /**
     * @brief GetCapacity() returns the heap capacity
     * 
     * @return int 
     */
    int getCapacity(); //returns the capacity of heap
    
    /**
     * @brief GetSize() returns the heap size
     * 
     * @return int 
     */
    int getSize(); //returns the size of heap

    /**
     * @brief DeleteHeap(heapObject) is a function to assist the main that will delete the given heapObject for main. Note it's not really a destructor just an assistive delete function, so we don't have to write a getter for the heapObject->H and delete that in main.
     * 
     * @param heapObject 
     */
    void deleteHeap(Heap* heapObject); //delete heap

    
    void heapSort(Heap* heapObject); //do heap sort

    int* heapSortReturn(Heap* heapObject, int size); //return an array from heapSort

};

#endif