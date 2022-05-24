#include <iostream>
using namespace std;

void selectionSort( int *arr, int size ){
    for(int i = 0; i < size-1; ++i){
        for(int j = i+1; j < size; ++j){
            if(arr[i] > arr[j]){
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

int main(){
    int arr[] = {12, 45, 23, 51, 19, 8};

    selectionSort(arr, 6);

    for(int i = 0; i < 6; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}