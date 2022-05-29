#include <iostream>
#include <algorithm>
using namespace std;

// void swap(int *a, int *b){
//     *a = *a + *b;
//     *b = *a - *b;
//     *a = *a - *b
// }

int partition(int *arr, int l, int r){
    int pivot = arr[r];
    int i = l-1;

    for (int j = l; j < r; j++){
        if(arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i+1], arr[r]);
    return i+1;
    
}

void quickSort( int *arr, int l, int r ){
    if(l<r){
        int pi = partition(arr, l, r);

        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

int main(){
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    quickSort(arr, 0, 8);

    for (int i = 0; i < 9; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}