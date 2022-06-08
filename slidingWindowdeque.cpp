#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    vector<int> a(n);

    for(auto &x: a){
        cin>>x;
    }

    deque<int> q;
    vector<int> ans;

    for (int i = 0; i < k; i++){
        while(!q.empty() && (a[q.back()] < a[i])){
            q.pop_back();
        }
        q.push_back(i);
    }
    
    ans.push_back(a[q.front()]);

    for (int i =  k; i < n; i++)      {
        if(q.front() == i-k){
            q.pop_front();
        }
        while(!q.empty() && (a[q.front()] < a[i])){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]); 
    }

    for (auto i: ans){
        cout<<i<<" ";
    }cout<<endl;
    
    //timeComplexity: nlog(n)
    // multiset<int, greater<int>> s;
    // vector<int> ans;

    // for (int i = 0; i < k; i++){
    //     s.insert(a[i])
    // }
    // ans.push_back(*s.begin());

    // for (int i = k; i < n; i++){
    //     s.erase(s.lower_bound(a[i-k]));
    //     s.insert(a[i]);
    //     ans.push_back(*s.begin());
    // }

    // for (auto x: ans){
    //     cout<<x<<" ";
    // }cout<<endl;
    

    return 0;
}