#include <iostream>
#include <queue>

using namespace std;

//making pop costly
class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
        Stack(){
            N = 0;
        }

        void pop(){
            if(q1.empty()){
                return;
            }
            
            while(q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }

            q1.pop();
            N--;
            std::swap(q1, q2);
        }

        void push(int val){
            q1.push(val);
            N++;
        }

        int size(){
            return N;
        }

        int top(){
            if(q1.empty()){
                return -1;
            }
            
            while(q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }

            int ans = q1.front();
            q2.push(ans);
            q1.pop();

            std::swap(q1, q2);
            return ans;
        }
};


//making push costly
// class Stack{
//     int N;
//     queue<int> q1;
//     queue<int> q2;

//     public: 
//         Stack(){
//             N = 0;
//         }

//         void push(int val){
//             q2.push(val);
//             N++;
//             while(!q1.empty()){
//                 q2.push(q1.front());
//                 q1.pop();
//             }
//             std::swap(q1, q2);
//         }

//         void pop(){
//             q1.pop();
//             N--;
//         }

//         int top(){
//             return q1.front();
//         }

//         int size(){
//             return N;
//         }
// };

int main(){
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.size()<<endl;
    st.pop();

    cout<<st.top()<<endl;

    return 0;
}