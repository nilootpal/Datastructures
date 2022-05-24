#include <iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();

    char arr[n+1];
    cin.getline(arr, n);
    cin.ignore();

    int currLen = 0, maxLen = INT_MIN, i = 0;
    while(true){
        if(arr[i] == ' ' ||arr[i] == '\0'){
            maxLen = max(currLen, maxLen);\
            currLen = 0;
        }
        else{
            ++currLen;
        }
        
        if(arr[i] == '\0'){
            break;
        }
        ++i;
    }

    cout<<maxLen<<endl;

    return 0;
}