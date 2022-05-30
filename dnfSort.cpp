#include <iostream>
#include <algorithm>

using namespace std;

void dnfSort(int *arr, int size){
    int low = 0, mid = 0, high = size-1;
    while(mid <= high){
        if(arr[mid] == 0){
            std::swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 2){
            std::swap(arr[mid], arr[high]);
            high--;
        }
        else{
            mid++;
        }
    }
}

int main(){
    int arr[] = {1, 1, 2, 0, 0, 1, 2, 2, 1, 0};

    dnfSort(arr, 10);

    for (int i = 0; i < 10; i++){
        cout<<arr[i];
    }
    
    return 0;
}