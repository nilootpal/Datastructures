#include <iostream>
using namespace std;

void insertionSort( int *arr, int size ){
    for( int i = 1; i < size; ++i){
        int temp = arr[i];
        int j = i-1;
        while((temp < arr[j]) && (j >= 0)){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(){
    int arr[] = {12, 45, 23, 51, 19, 8};

    insertionSort(arr, 6);

    for(int i = 0; i < 6; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}