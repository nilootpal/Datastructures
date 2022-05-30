#include <iostream>
#include <algorithm>
using namespace std;

void waveSort(int *arr, int size){
    for (int i = 1; i < size; i+=2){
        if(arr[i] > arr[i-1]){
            std::swap(arr[i], arr[i-1]);
        }
        if(arr[i] > arr[i+1]){
            std::swap(arr[i], arr[i+1]);
        }
    }
    
}

int main(){
    int arr[] = {1, 3, 4, 7, 5, 6, 2};

    waveSort(arr, 7);

    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i];
    }
    
    return 0;
}