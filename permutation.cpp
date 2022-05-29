#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans;

void permute(vector<int> &a, int idx){
    if(idx == a.size()){
        ans.push_back(a);
        return;
    }

    for(int i = idx; i < a.size(); ++i){
        if((a[i] == a[idx]) && (i != idx)){
            continue;
        }
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

    permute(a, 0);

    for( auto v : ans ){
        for( auto i : v){
            cout<<i;
        }
        cout<<endl;
    }

    return 0;
}