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

class queue{
    node* front;
    node* back;

    public:
        queue(){
            front = NULL;
            back = NULL;
        }

        void push(int x){
            node* n = new node(x);

            if(front == NULL){
                front = n;
                back = n;
                return;
            }

            back->next = n;
            back = n;
        }

        void pop(){
            if(front == NULL){
                cout<<"Queue underflow"<<endl;
                return;
            }

            node* todelete = front;
            front = front->next;

            delete todelete;
        }

        int peek(){
            if(front == NULL){
                cout<<"No element in queue"<<endl;
                return -1;
            }

            return front->data;
        }

        bool empty(){
            return front == NULL; 
        }
};

int main(){
    queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    // q.push(4);
    // q.push(5);

    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty()<<endl;

    return 0;
}