#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans;

void permute(vector<int> &a, int idx){
    if(idx == a.length()){
        ans.push_back(idx);
        return;
    }

    for(int i = idx; i < s.length(); ++i){
        std::swap(a[i], a[idx]);
        permute(a, idx+1);
        std::swap(a[i], a[idx]);
    }

    return;
}


int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &x : a){
        cin>>x;
    }

    permute(a);

    for( auto v : ans ){
        for( auto i : v){
            cout<<i;
        }
        cout<<endl;
    }

    return 0;
}