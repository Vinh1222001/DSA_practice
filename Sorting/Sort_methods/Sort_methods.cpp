#include "Sort_methods.h"

template<typename T> 
void Sort_methods<T>::printSelectionSort(){

    int current  = 0;
    while(current < this->count -1) { 
        int min = current; // Assume the first element is the smallest
        int walk = current + 1;
        while (walk < this->count )
        {
            if(this->arr[walk] < this->arr[min]) {
                min = walk;
                
            }
            walk++;
        }
        swap(&(this->arr[min]), &(this->arr[current]));
        current++;
    }
    
    this->printArray();
    
    cout << endl;

}

template<typename T>
void Sort_methods<T>::printInsertionSort(){
    if(this->count > 1){
        int current = 1;
        while(current < this->count){
            T temp = this->arr[current];
            int step = current - 1;
            while (step >= 0 && temp < this->arr[step])
            {
                this->arr[step+1] = this->arr[step];
                step--;
            }
            this->arr[step +1 ] =temp;
            current++;
            
        }
    }

    this->printArray();
}

template<typename T> 
void Sort_methods<T>::swap(T* x, T*y){
    T temp = *x;
    *x = *y;
    *y = temp;
} 

template<typename T> void Sort_methods<T>::printArray(){
    for (int i = 0; i < this->count; i++)
    {
        cout << this->arr[i] << " ";
    }
    cout << endl;
    
}

template<typename T> 
Sort_methods<T>::Sort_methods(T arr[], int count){
    this->arr = arr;
    this->count = count;
}

template<typename T> 
Sort_methods<T>::~Sort_methods(){
    if (this->arr != nullptr)
    {
        delete[] this->arr;
        this->arr = nullptr;
        this->count =0;
    }
    
}