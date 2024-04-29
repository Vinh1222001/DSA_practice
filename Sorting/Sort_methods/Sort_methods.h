#ifndef SORT_METHOD_H
#define SORT_METHOD_H

#include <iostream>
using namespace std;

template<typename T> class Sort_methods
{
private:
    /* data */
    T* arr;
    int count;
    void swap(T *x, T *y) ; //
    void printArray();

public:
    Sort_methods(T arr[], int count);
    ~Sort_methods();

    void printSelectionSort();
    void printInsertionSort();
    void printShellSort();
    void printBubbleSort();

};

#endif