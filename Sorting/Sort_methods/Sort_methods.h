#ifndef SORT_METHOD_H
#define SORT_METHOD_H

#include <bits/stdc++.h>
using namespace std;

#define QUICK_SORT_LUMUTO_PARTITION 100
#define QUICK_SORT_HOARE_PARTITION  200

template<typename T> class Sort_methods
{
private:
    /* data */
    T* arr;
    int count;
    void swap(T *x, T *y) ; //
    void QuickSort(int (*partitionFuntion)(T* arr,int left, int right), int left, int right);

public:
    Sort_methods(T arr[], int count);
    ~Sort_methods();
    
    void printArray();

    void printSelectionSort();
    void printInsertionSort();
    void printShellSort();
    void printBubbleSort();
    void printQuickSort(int PartitionFunctionOpt);

};

#endif