#include <iostream>
using namespace std;

long long merge(int *arr, int l, int mid, int r){
    long long inversion = 0;

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2];

    for (int i = 0; i < n1; i++){
        a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++){
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while( (i<n1) && (j<n2) ){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            i++;
        }
        else{
            arr[k] = b[j];
            j++;
            inversion = n1-i;
        }
        k++;
    }

    while(i<n1){
        arr[k] = a[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = b[j];
        k++;
        j++;
    }

    return inversion;
    
}

long long mergeSort(int *arr, int l, int r){
    long long inversion = 0;
    if(l < r){
        int mid = (l+r)/2;

        inversion += mergeSort(arr, l, mid);
        inversion += mergeSort(arr, mid+1, r);

        inversion += merge(arr, l, mid, r);
    }
    
    return inversion;
}

int main(){
    int arr[] = {3, 2, 1};
    // int arr[] = {5, 4, 3, 2, 1};
    // int arr2[] = {2, 5, 4};

    int inversion = mergeSort(arr, 0, 2);
    // std::swap(*arr, *arr2);

    cout<<inversion; 

    // for (int i = 0; i < 8; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    

    return 0;
}