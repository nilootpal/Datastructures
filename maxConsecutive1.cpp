#include <iostream>
#include <vector>
#include <string>
using namespace std;


//longest substring without repeating 

int main(){
    string s;
    cin>>s;
    vector<int> dict(256, -1);

    int maxLen = 0, start = -1;
    for (int i = 0; i < s.size(); i++){
        if(dict[s[i]] > start){
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxLen = max(maxLen, i-start);
    }
    

    return 0;
}

// int main(){
//     int n, k;
//     cin>>n>>k;
//     vector<int> arr(n);

//     for(&i : arr){
//         cin>>i;
//     }

//     int zerocount=0, i=0, ans=0;

//     for (int j = 0; j < n; j++){
//         if(arr[j] == 0){
//             zerocount++;
//         }

//         while(zerocount > k){
//             if(arr[i] == 0){
//                 zerocount--;
//             }
//             i++;
//         }

//         ans = max(ans, j-i+1);
//     }
    
//     return 0;
// }

