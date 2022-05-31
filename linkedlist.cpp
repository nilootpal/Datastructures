#include <iostream>
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

void insertAtTail(node* &head, int value){
    node* n = new node(value);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while((temp->next) != NULL){
        temp = temp->next;
    }

    temp->next = n;
}

void insertAtHead(node* &head, int value){
    node* n = new node(value);
    
    n->next = head;
    head=n;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

void deletion(node* head, int key){
    node* temp = head;
    while(temp->next->data != key){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}

bool search(node* head, int key){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtHead(head, 0);
    insertAtHead(head, -1);
    insertAtHead(head, -2);
    insertAtHead(head, -3);
    insertAtHead(head, -5);
    display(head);
    deletion(head, 0);
    deleteAtHead(head);
    display(head);

    return 0;
}