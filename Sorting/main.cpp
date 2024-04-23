#include "Sort_methods/Sort_methods.h"
#include "Sort_methods/Sort_methods.cpp"

#include <chrono>

using namespace std::chrono;

int main(void){

    auto start = high_resolution_clock::now();

    int arr[10] = {1,4,2,3,1,2,313,51,3,1};
    int count =10;
    Sort_methods<int> sort(arr, count);

    // sort.printSelectionSort(arr,count);
    sort.printInsertionSort();


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Run Time: " <<  duration.count() <<" microsecconds"<< endl;
    return 0;
}