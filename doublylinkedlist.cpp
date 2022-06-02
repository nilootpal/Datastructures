#include <iostream>
using namespace std;

class node{
    public: 
        int data;
        node* prev;
        node* next;

        node(int value){
            data = value;
            prev = NULL;
            next = NULL;
        }
};

void insertAthead(node* &head, int value){
    node* n = new node(value);
    n->next = head;
    if(head != NULL){
        head->prev = n;
    }
    head = n;
}

void insertAtTail(node* &head, int value){
    if(head == NULL){
        insertAthead(head, value);
        return;
    }

    node* n = new node(value);
    node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

void deleteAtHead(node* &head){
    node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void deletion(node* &head, int pos){
    if(pos == 1){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int count = 1;

    while((temp!=NULL) && (count!=pos)){
        temp=temp->next;
        count++;
    }

    temp->prev->next = temp->next;

    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    delete temp;

}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


int main(){
    

    // display(head);
    // insertAthead(head, 0);
    // display(head);
    // deletion(head, 5);
    // display(head);
    // deleteAtHead(head);
    // display(head);
    // node* newNode = appendLastK(head, 3);
    // display(newNode);


    return 0;
}