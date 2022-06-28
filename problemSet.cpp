#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

void removeDuplicates(vector<int> arr){
    if(arr.size() == 0){
        return;
    }

    if(*arr.begin() == *(arr.begin() + 1)){
        arr.erase(arr.begin());
        removeDuplicates(arr);
    }
    else{
        ans.push_back(*arr.begin());
        arr.erase(arr.begin());
        removeDuplicates(arr);
    }
}

int main(){
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

    removeDuplicates(arr);

    for(auto i : ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}