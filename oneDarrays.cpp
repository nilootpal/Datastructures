#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void primeFactor(int n){
    int spf[100] = {0};
    for (int i = 2; i < n; i++){
        spf[i] = i;
    }
    
    for (int i = 2; i <= count; i++){
        if(spf[i] == i){
            for (int j = i*i; j <= count; j++){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }

    while(n!=1){
        cout<<spf[n]<<" ";
        n/=spf[n];
    }
}


void sieve(int n){
    int prime[100] = {1};
    for(int i = 2; i <= n; ++i){
        if(prime(i)){
            for(int j = i*i; j <= n; ++i){
                prime[j] = 0;
            }
        }
    }

    for (int i = 2; i < n; i++){
        if (prime(i)){
            cout<<i<<" ";
        }
    }

}


int main(){
    int n, k;
    cin>>n>>k;

    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort( arr, arr+n );

    int st = 0, en = n-1;

    while(st <= en){
        if((arr[st] + arr[en]) > k){
            --en;
        }
        else if((arr[st] + arr[en]) < k){
            ++st;
        }
        else{
            cout<<st<<" "<<en<<endl;
            break;
        }
    }


    
    return 0;
}
//max Circular Sum

// int kadane(int *arr, int size){
//     int maxSum = INT_MIN;
//     int currentSum = 0;
//     for (int i = 0; i < size; i++){
//         currentSum += arr[i];
//         if(currentSum<0){
//             currentSum = 0;
//         }
//         maxSum = max(currentSum, maxSum);
//     }
//     return maxSum;
// }

// int main(){
//     int n;
//     cin>>n;

//     int arr[n], sum = 0;

//     for(int i = 0; i < n; i++){
//         cin>>arr[i];     
//     }

//     int nonCircularSum = kadane(arr, n);

//     for(int i = 0; i < n; i++){
//         sum += arr[i];       
//         arr[i] = -arr[i];
//     }

//     int CircularSum = sum + kadane(arr, n);

//     cout<<max(nonCircularSum, CircularSum)<<endl;
    
    
//     return 0;
// }


//maximumSubarray sum

// int main(){
//     int n;
//     cin>>n;

//     int arr[n];

//     for (int i = 0; i < n; i++){
//         cin>>arr[i];
//     }

//     int maxSum = INT_MIN;
//     int currentSum = 0;
//     for (int i = 0; i < n; i++){
//         currentSum += arr[i];
//         if(currentSum<0){
//             currentSum = 0;
//         }
//         maxSum = max(currentSum, maxSum);
//     }

//     cout<<maxSum<<endl;
    
    
//     return 0;
// }

//smallest positive number missing in the array

// int main(){
//     int n;
//     cin>>n;

//     int arr[n], maxP = -1;
//     for (int i = 0; i < n; i++){
//         cin>>arr[i];
//         maxP = max(maxP, arr[i]);
//     }

//     bool temp[maxP+2];
//     for (int i = 0; i < maxP+2; i++){
//         temp[i] = false;
//     }

//     for (int i = 0; i < n; i++){
//         if(arr[i] >= 0){
//             temp[arr[i]] = true;
//         }
//     }

//     for (int i = 0; i < maxP; i++)
//     {
//         if(temp[i] == false){
//             cout<<i<<endl;
//             break;
//         }
//     }

//     return 0;
// }

//find the index in the array that sums up to the given sum

// int main(){
//     int n, s;
//     cin>>n>>s;

//     int arr[n];

//     for (int i = 0; i < n; i++){
//         cin>>arr[i];
//     }

//     int i = 0, j = 0, st = -1, en = -1, sum;

//     while ((j < n) && (sum+arr[j] < s)){
//         sum += arr[j++];
//     }

//     if(sum == s){
//         cout<<i+1<<" "<<j<<endl;
//         return 0;
//     }

//     while(j < n){
//         sum += arr[j];
//         while(sum > s){
//             sum -= arr[i++];
//         }
//         if(sum == s){
//             st = i+1;
//             en = j+1;
//             break;
//         }
//         j++;
//     }
    
//     cout<<st<<" "<<en<<endl;

    
//     return 0;
// }

//index of the first repeating element

// int main(){
//     int n;
//     cin>>n;

//     int arr[n], maxNum = 0;

//     for(int i = 0; i < n; ++i){
//         cin>>arr[i];
//         maxNum = max(maxNum, arr[i]);
//     }

//     int temparr[maxNum+1];

//     for(int i = 0; i < maxNum+1; ++i){
//         temparr[i] = -1;
//     }

//     int minidx = INT_MAX;

//     for(int i = 0; i < n; ++i){
//         if(temparr[arr[i]] == -1){
//             temparr[arr[i]] = i;
//         }
//         else{
//             minidx = min(minidx, temparr[arr[i]]);
//         }
//     }

//     if(minidx == INT_MIN){
//         cout<<"-1"<<endl;
//     }
//     else{
//         cout<<minidx+1<<endl;
//     }

//     return 0;
// }

//record-breaking day

// int main(){
//     int n;
//     cin>>n;

//     int arr[n];
//     for(int i = 0; i < n; ++i){
//         cin>>arr[i];
//     }

//     int prevMax = -1;
//     int ans = 0;

//     for(int i = 0; i < n; ++i){
//         if((arr[i] > prevMax) && ((arr[i]>arr[i+1]) || (i == n-1))){
//             ++ans;
//         }
//         prevMax = max(arr[i], prevMax);
//     }

//     cout<<ans<<endl;


//     return 0;
// }




//Max arithmetic subarray

// int main(){
//     int n;
//     cin>>n;

//     int arr[n];

//     for(int i = 0; i < n; ++i){
//         cin>>arr[i];
//     }

//     int pd = arr[1] - arr[0];
//     int ans = 2;
//     int curr = 2;

//     for( int i = 1; i < n-1; ++i ){
//         if(pd == (arr[i+1] - arr[i])){
//             ++curr;
//         }
//         else{
//             curr = 2;
//             pd = arr[i+1] - arr[i];
//         }
//         ans = max(curr, ans);
//     }
//     cout<<ans<<endl;

//     return 0;
// }