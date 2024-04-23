#include <iostream>
#include "Sort_methods.cpp"

using namespace std;

int main(void){

    Sort_methods sort;

    int arr[10];
    int count =10;

    sort.printSelectionSort(arr,count);

    return 0;
}