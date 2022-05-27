#include <iostream>
#include <string>

using namespace std;

// bool isArrSorted(int *arr, int size){
//     if(size == 1){
//         return true;
//     }
//     bool restArr = isArrSorted(arr+1, size-1);
//     return ((arr[0] < arr[1]) && restArr);
// }

// int firstOccurence(int *arr, int size, int elem, int i){
//     if(i == size){
//         return -1;
//     }

//     if(arr[i] == elem){
//         return i;
//     }

//     return firstOccurence(arr, size, elem, i+1);
// }

// int lastOccurence(int *arr, int size, int elem, int i){
//     if(i == size){
//         return -1;
//     }
//     int restArr = lastOccurence(arr, size, elem, i+1);
//     if(restArr != -1){
//         return restArr;
//     }

//     if(arr[i] == elem){
//         return i;
//     }
    
//     return -1;
// }

// void reverse(string s){
//     if(s.length() == 0){
//         // cout<<s[0];
//         return;
//     }
//     reverse(s.substr(1));
//     cout<<s[0];
// }

// void replacePi(string s){
//     if(s.length() == 0){
//         return;
//     }

//     if(s.substr(0,2) == "pi"){
//         cout<<"3.14";
//         replacePi(s.substr(2));
//     }
//     else{
//         cout<<s[0];
//         replacePi(s.substr(1));
//     }
// }

// void removeAllDuplicates(string s){
//     if(s.length() == 0){
//         return ;
//     }
//     if(s[0] == s[1]){
//         removeAllDuplicates(s.substr(1));
//     }
//     else{
//         cout<<s[0];
//         removeAllDuplicates(s.substr(1));
//     }
// }

// string moveAllxtoBack(string s){
//     if(s.length() == 0){
//         return "" ;
//     }

//     if(s.substr(0, 1).compare("x") == 0){
//         return moveAllxtoBack(s.substr(1)) + s.substr(0,1);
//     }
//     else{
//         return s.substr(0,1) + moveAllxtoBack(s.substr(1)); 
//     }
// }

// void subseq(string s, string ans){
//     if(s.length() == 0){
//         cout<<ans<<endl;
//         return;
//     }
//     char ch=s[0];
//     string ros = s.substr(1);

//     subseq(ros, ans);
//     subseq(ros, ans+ch);
// }

// string keyPad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// void keypad(string s, string ans){
//     if(s.length() == 0){
//         cout<<ans<<endl;
//         return;
//     }

//     char ch = s[0];
//     string code = keyPad[ch-'0'];
//     string ros = s.substr(1); 

//     for (int i = 0; i < code.length; i++){
//         keypad(ros, ans + code[i]);
//     }
    
// }

// void permutation(string s, string ans){
//     if(s.length() == 0){
//         cout<<ans<<endl;
//         return;
//     }

//     for (int i = 0; i < s.length(); i++){
//         char ch = s[i];
//         string ros = s.substr(0, i) + s.substr(i+1);
//         permutation(ros, ans+ch);
//     } 
// }

// int countPath(int s, int e){
//     if(s == e){
//         return 1;
//     }
//     if(s > e){
//         return 0;
//     }

//     int count = 0;

//     for (int i = 1; i <= 6; i++){
//         count += countPath(s+i, e);
//     }

//     return count;
// }

// int countPathMaze(int n, int i, int j){
//     if((i == n-1) && (j == n-1)){
//         return 1;
//     }
//     if((i > n-1) && (j > n-1)){
//         return 0;
//     }

//     return countPathMaze(n, i+1, j) + countPathMaze(n, i, j+1);
// }

// int tilingWays(int n){
//     if(n == 0){
//         return 0;
//     }
//     if(n == 1){
//         return 1;
//     }
//     return tilingWays(n-1) + tilingWays(n-2);
// }

// int pairUp(int n){
//     if(n == 0 || n == 1 || n == 2){
//         return n;
//     }

//     return pairUp(n-1) + pairUp(n-2) * (n-1);
// }

int knapSack(int *value, int *wt, int n, int w){
    if(n == 0 || w == 0){
        return 0;
    }

    if(wt[n-1] > w){
        return knapSack(value, wt, n-1, w);
    }

    return max(knapSack(value, wt, n-1, w-wt[n-1])+value[n-1], knapSack(value, wt, n-1, w));
}

int main(){
    // int arr[] = {4, 2, 1, 2, 5, 2, 7};
    // string s = "binod";
    // string s = "pippppiiiipi";
    // string s = "aaaaabbbbbcccdeeee";
    // removeAllDuplicates(s);

    // cout<<s;
    // replacePi(s1);

    // cout<<s1;

    // reverse(s);
    // cout<<lastOccurence(arr, 7, 2, 0);

    // string s = "axxbdxcefxhix";
    // cout<<moveAllxtoBack(s);

    // cout<<countPath(0,3)<<endl;

    return 0;
}