#include "Sort_methods/Sort_methods.h"
#include "Sort_methods/Sort_methods.cpp"

#include <chrono>

using namespace std::chrono;

int main(void){

    int arr[1000]; 
    int count;
    cin >> count;

    srand(time(0));
    for (int i = 0; i < count; i++)
    {
        arr[i] = rand() % 100;
    }
    

    auto start = high_resolution_clock::now();

    Sort_methods<int> sort(arr, count);
    sort.printArray();
    // sort.printSelectionSort(arr,count);
    sort.printQuickSort(QUICK_SORT_LUMUTO_PARTITION);
    // sort.printQuickSort(QUICK_SORT_HOARE_PARTITION);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Run Time: " <<  duration.count() <<" microsecconds"<< endl;
    return 0;
}