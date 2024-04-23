#ifndef SORT_METHOD_H
#define SORT_METHOD_H

#include <iostream>
using namespace std;

template<typename T> class Sort_methods
{
private:
    /* data */

    void swap(T *x, T *y) ; //
public:
    Sort_methods(/* args */);
    ~Sort_methods();

    void printSelectionSort(T arr[], int count);
};

template<typename T> 
void Sort_methods<T>::printSelectionSort(T arr[], int count){

    int current  = 0;
    while(count < count -1) { 
        int min = current; // Assume the first element is the smallest
        int walk = current + 1;
        while (walk < count )
        {
            if(arr[walk] < arr[min]) {
                min = walk;
                
            }
            walk++;
        }
        swap(&arr[min], &arr[walk]);
        current++;
    }
    
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] <<" "; 
    }
    
    cout << endl;

}

template<typename T> 
void Sort_methods<T>::swap(T* x, T*y){
    T temp = *x;
    *x = *y;
    *y = temp;
} 

template<typename T> 
Sort_methods<T>::Sort_methods(){

}

template<typename T> 
Sort_methods<T>::~Sort_methods(){

}



#endif