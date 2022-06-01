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

bool search(node* head, int key){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

node* reverse(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* next;

    while(curr != NULL){
        next = curr->next;
        
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

node* reversek(node* &head, int k){
    node* prev = NULL;
    node* curr = head;
    node* next;

    int count = 0;
    while(curr != NULL && count < k){
        next = curr->next;
         
        curr->next = prev;

        prev = curr;
        curr = next;

        count++;
    }

    if(next != NULL){
        head->next = reversek(next, k);
    }

    return prev;
    
}

node* reverseRecursive(node* &head){
    if((head->next == NULL) || (head == NULL)){
        return head;
    }

    node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
    // return head->next;
}

bool detectCycle(node* head){
    node* slow = head;
    node* fast = head;

    while((fast != NULL) && (fast->next != NULL)){

        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            return true;
        }
    }

    return false;
}

void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startNode;

    int count = 1;
    while (temp->next != NULL){
        if(count == pos){
            startNode = temp;
        }

        temp = temp->next;
        ++count;
    }

    temp->next = startNode;
    
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do{
        fast = fast->next->next;
        slow = slow->next;
    } while (slow != fast);
    

    fast = head;

    while(fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;

}



int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    // insertAtTail(head, 7);
    // insertAtTail(head, 8);

    makeCycle(head, 3);
    cout<<detectCycle(head)<<endl;

    removeCycle(head);
    cout<<detectCycle(head)<<endl;


    display(head);

    // node* temp = reversek(head, 2);

    // display(temp);

    return 0;
}