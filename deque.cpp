#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_front(0);
    dq.push_front(-1);
    dq.push_front(-2);
    dq.push_front(-3);

    for(auto x: dq){
        cout<<x<<" ";
    }cout<<endl;

    dq.pop_back();
    dq.pop_front();

    for(auto x: dq){
        cout<<x<<" ";
    }cout<<endl;

    return 0;
}