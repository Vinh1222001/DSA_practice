#include "includes/Sort_methods.h"

int main(void){

    Sort_methods<int> sort;

    int arr[10] = {1,4,2,3,1,2,313,51,3,1};
    int count =10;

    sort.printSelectionSort(arr,count);

    return 0;
}