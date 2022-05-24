#include <iostream>
using namespace std;

void bubbleSort( int *arr, int size ){
    for(int i = 0; i < size-1; ++i){
        for(int j = 0; j < size-i-1; ++j){
            if(arr[j] >arr[j+1]){
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[] = {12, 45, 23, 51, 19, 8};

    bubbleSort(arr, 6);

    for(int i = 0; i < 6; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}