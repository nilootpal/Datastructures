#include <iostream>
using namespace std;
#define n 100

class queue{
    int *arr;
    int front;
    int back;
    public:
        queue(){
            arr = new int[n];
            front = -1;
            back = -1;
        }

        void enqueue(int x){
            if(back == n-1){
                cout<<"Queue overflow"<<endl;
                return;
            }
            arr[++back] = x;
            front = (front == -1) ? 0 : front;
        }

        void dequeue(){
            if((front == -1) || (front > back)){
                cout<<"No Elements in queue"<<endl;
                return;
            }
            ++front;
        }

        int peek(){
            if((front == -1) || (front > back)){
                cout<<"No Elements in queue"<<endl;
                return -1;
            }
            return arr[front];
        }

        bool empty(){
            return (front == -1) || (front > back);
        }
};

int main(){
    queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    cout<<q.peek()<<endl;

    q.dequeue();

    cout<<q.peek()<<endl;

    return 0;
}