#include <iostream>
using namespace std;

bool ispowerof2(int n){
    return (n && !(n & (n-1)));
}

int numof1(int n){
    int ans;
    while(n){
        ++ans;
        n = n & (n-1);
    }
    return ans;
}

void subsets(int *arr, int size){
    for(int i = 0; i < (1 << size); ++i){
        for (int j = 0; j < size; j++){
            if(i & (1 << j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}

//find unique element in an array where every number appears twice except for one
int uniqueElem(int *arr, int size){
    int unique = arr[0];
    for(int i = 1; i < size; ++i){
        unique = unique^arr[i];
    }
    return unique;
}

bool getBit(int pos, int n){
    return (n>>(pos) & 1);
}

int setBit(int pos, int n){
    return (n & (1<<pos));
}

//find unique element in an array where every number appears twice except for one
// int *twouniqueElem(int *arr, int size){
//     int temp = arr[0];
//     for(int i = 1; i < size; ++i){
//         temp = temp^arr[i];
//     }

//     int firstBit = 0;
//     while((temp & (1<<firstBit)) != 0){
//         ++firstBit;
//     }
//     int unique[] = {0, 0};

//     for (int i = 0; i < size; i++){
//         if((arr[i] & (1<<firstBit)) != 0){
//             unique[0] = unique[0] ^ arr[i];
//         }
//     }

//     unique[1] = temp ^ unique[0];
    
//     return unique;
// }

//find unique element in an array where every number appears thrice except one which appears only once
int uniqueofThree(int *arr, int size){
    int result = 0; 
    for (int i = 0; i < 64; i++)    {
        int sum = 0;
        for (int j = 0; j < size; j++){
            if(getBit(arr[j], i)){
                ++sum;
            }
        }

        if((sum%3) != 0){
            result = setBit(result, i);
        }
        
    }
    return result;
    
}


int main(){
    // int n;
    // cin>>n;

    
    return 0;
}