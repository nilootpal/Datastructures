#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int value){
            data = value;
            next = NULL;
        }
};

void deleteAtHead(node* &head){
    node* temp = head;
    while(temp->next != head){
        temp=temp->next;
    }

    node* todelete = head;

    temp->next = head->next;
    head = head->next;
    delete todelete;
}

void deletion(node* &head, int pos){
    node* temp = head;

    if(pos == 1){
        deleteAtHead(head);
        return;
    }

    int count;

    while(count != pos-1){
        temp = temp->next;
        count++;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void insertAtHead(node* &head, int value){
    node* n = new node(value);
    if(head == NULL){
        n->next = n;
        head = n;
        return;
    }

    node* temp = head;

    while((temp->next) != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int value){
    node* n = new node(value);
    node* temp = head;

    if(head == NULL){
        insertAtHead(head, value);
        return;
    }

    while((temp->next) != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void display(node* head){
    node* temp = head;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp != head);
    
    cout<<endl;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    display(head);
    insertAtHead(head, 0);
    display(head);
    deletion(head, 3);
    display(head);
    deleteAtHead(head);
    display(head);

    return 0;
}