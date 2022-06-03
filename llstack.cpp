#include <iostream>
using namespace std;

class node{
    public:
        node* next;
        int data;

        node( int value ){
            data = value;
            next = NULL;
        }
};

class stack{
    node* top;

    public:
        stack(){
            top = NULL;
        }

        void push(int x){
            node* n = new node( x );

            if(top == NULL){
                top = n;
                return;
            }

            n->next = top;
            top = n;

        }

        void pop(){
            if(top == NULL){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            
            node* todelete = top;
            top = top->next;
            delete todelete;
        }

        int Top(){

            if(top == NULL){
                cout<<"No element in stack"<<endl;
                return -1;
            }

            return top->data;
        }

        bool empty(){
            return top == NULL;
        }
};

int main(){
    stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    
    cout<<st.empty()<<endl;

    return 0;
}