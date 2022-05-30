#include <iostream>
using namespace std;

// int maxElem(int *arr, int size){
//     int elem = arr[0];
//     for (int i = 1; i < size; i++){
//         elem = max(elem, arr[i]);
//     }
    
//     return elem;
// }

void countSort(int *arr, int size){
    // int tempS = maxElem(arr, size) + 1;
    int count[10] = {0};

    for (int i = 0; i < size; i++){
        ++count[arr[i]]; 
    }

    for (int i = 1; i < 10; i++){
        count[i] = count[i-1] + count[i];
    }

    int output[size];

    for (int i = size-1; i >= 0; i--){
        output[--count[arr[i]]] = arr[i];
    }
    
    for (int i = 0; i < size; i++){
        arr[i] = output[i];
    }
    
    
}

int main(){
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    countSort(arr, 9);

    for (int i = 0; i < 9; i++)
    {
        cout<<arr[i];
    }
    
    return 0;
}