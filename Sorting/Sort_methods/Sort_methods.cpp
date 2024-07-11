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
void Sort_methods<T>::printShellSort(){
    int gap = 1, i,j;
    T temp;
    while(gap >= this->count/3)
        gap = gap*3+1;

    while (gap > 0)     
    {
        for(i = gap; i < this->count ; i++){
            temp = this->arr[i];
            j = i;
            while (this->arr[j-gap] > temp && j > gap - 1)
            {
                cout << "Swapped " << this->arr[j] << " and "<< this->arr[j-gap] << endl;
                this->arr[j] = this->arr[j-gap];
                j-=gap;
            }

            this->arr[j] = temp;
            
        }
        gap = (gap-1)/3;
    }
    
    this->printArray();
}

template<typename T>
void Sort_methods<T>::printBubbleSort(){

    int current = 0;
    bool flag = false;
    while(current < this->count && flag == false ){
        int step = this->count - 1;
        flag = true;
        while (step > current)
        {
            if(this->arr[step] < this->arr[step-1]){
                flag = false;
                this->swap(&(this->arr[step]), &(this->arr[step-1]));
            }
            step--;

        }
        current++;
    }
    this->printArray();
}

template<typename T>
int LomutoPartition(T* arr,int left, int right){
    T pivot = arr[right];

    int i = left -1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
        
    }
    
    swap(arr[i+1], arr[right]);
    
    return (i+1);
}

template<typename T>
int HoarePartition(T* arr,int left, int right){

    T pivot = arr[left];

    int i = left - 1;
    int j = right + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);
        
        if(i>=j){
            return j;
        }

        swap(arr[i],arr[j]);

    }

}

template<typename T> 
void Sort_methods<T>::QuickSort(int (*partitionFuntion)(T* arr,int left, int right), int left, int right){
    if(left < right){
        this->printArray();
        int pivot_pos = partitionFuntion(this->arr, left, right);
        this->QuickSort(partitionFuntion, left, pivot_pos-1);
        this->QuickSort(partitionFuntion, pivot_pos+1, right);
    }
}

template<typename T>
void Sort_methods<T>::printQuickSort(int PartitionFunctionOpt){

    switch (PartitionFunctionOpt)
    {
        case QUICK_SORT_LUMUTO_PARTITION:
            cout << "Quick sort with Lumoto Partition" << endl;
            this->QuickSort(LomutoPartition, 0, this->count-1);
            break;

        case QUICK_SORT_HOARE_PARTITION:
            cout << "Quick sort with Hoare Partition" << endl;
            this->QuickSort(HoarePartition, 0, this->count-1);
            break;

        default:

            cerr << "In Sortmethods.cpp -> printQuicksort(int), You entered a wrong Partition function ID, please try:" <<endl;
            cerr << "\tQUICK_SORT_LUMUTO_PARTITION" << endl;
            cerr << "\tor" << endl;
            cerr << "\tQUICK_SORT_HOARE_PARTITION" << endl;
            break;
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