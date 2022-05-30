#include <iostream>
#include <vector>
using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int> p2){
    return p1.first<p2.first;
}

int main(){
    // vector<int> v;

    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

    // for (int i = 0; i < v.size(); i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;

    // vector<int>::iterator it;
    // for(it = v.begin(); it!= v.end(); it++){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;

    // for(auto element: v){
    //     cout<<element<<" ";
    // }

    // cout<<endl;

    // v.pop_back();

    // vector<int> a(5, 50);

    int arr[] = {10, 16, 7, 14, 5, 3, 2, 9};

    vector<pair<int,int>> vect;

    for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++){
        vect.push_back(make_pair(arr[i], i));
    }

    sort(vect.begin(), vect.end(), myCompare);

    for (int i = 0; i < vect.size(); i++){
        arr[vect[i].second] = i;
    }

    for (int i = 0; i < vect.size(); i++){
        cout<<arr[i];
    }
    cout<<endl;
    
    return 0;
}