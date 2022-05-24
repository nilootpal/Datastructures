#include<iostream>
using namespace std;

//2d Matrix Search
bool matrixSearch(int **arr, int size, int elem){
    int i = 0, j = n-1;

    while((i>0) && (j>0)){
        if(arr[i][j] == elem){
            return true;
        }
        else if(arr[i][j] < elem){
            ++i;
        }
        else{
            ++j;
        }
    }
}

//matrix multiplication
// int main(){
//     int m1, m2, n1, n2;
//     cin>>m1>>n1>>m2>>n2;

//     int arr1[m][n];

//     for (int i = 0; i < m; i++){
//         for (int j = 0; j < n; j++){
//             cin>>arr[i][j];
//         }
//     }

//     //arr[i][j] += arr1[i][k]*arr2[k][j]
    
//     return 0;
// }