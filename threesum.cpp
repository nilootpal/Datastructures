#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, target;
    cin>>n>>target;

    vector<int> a(n);
    for(auto &x: a){
        cin>>x;
    }

    bool found = false;
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++){
        int lo = i+1;
        int hi = n-1;
        while(lo < hi){
            int current = a[i] + a[hi] + a[lo];
            if(current == target){
                found == true;
                break;
            }
            else if(current < target){
                lo++;
            }
            else{
                hi--;
            }
        }
        // if(found == true){
        //     break;
        // }
    }

    return 0;
}