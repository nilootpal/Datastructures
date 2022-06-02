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

int length(node* head){
    node* temp = head;
    int count = 0;
    while(temp != NULL){
        ++count;
        temp = temp->next;
    }
    return count;
}

node* appendLastK(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail = head;

    int l = length(head);
    k = k%l;
    int count = 1;

    while(tail->next != NULL){
        if(count == l-k){
            newTail = tail;
        }
        if(count == l-k+1){
            newHead = tail;
        }

        tail = tail->next;
        ++count;
    }

    newTail->next = NULL;
    // newHead->prev = NULL;
    tail->next = head;
    // head->prev = tail;

    return newHead;
}

void intersect(node* &head1, node* &head2, int pos){
    node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }
    node* temp2 = head2;

    while(temp2->next != NULL){
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

int intersectionPt(node* &head1, node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;
    node* ptr1;
    node* ptr2;

    if(l1>l2){
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d--){
        ptr1 = ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
    }

    while((ptr1!=NULL) && (ptr2!=NULL)){
        if(ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;

}

node* mergeSort(node* head1, node* head2){
    node* p1 = head1;
    node* p2 = head2;
    node* dummynode = new node(-1);
    node* p3 = dummynode;

    while((p1 != NULL) && (p2 != NULL)){
        if(p1->data < p2->data){
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while(p1 != NULL){
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while(p2 != NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummynode->next;
}

node* mergeRecursive( node* &head1, node* &head2 ){
    node* result;

    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }

    if(head1->data < head2->data){
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else{
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }

    return result;
}


int main(){
    node* head1 = NULL;
    node* head2 = NULL;

    insertAtTail(head1, 1);
    insertAtTail(head1, 3);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);
    insertAtTail(head1, 9);
    insertAtTail(head2, 2);
    insertAtTail(head2, 4);
    insertAtTail(head2, 6);
    insertAtTail(head2, 8);
    insertAtTail(head2, 10);

    // intersect(head1, head2, 3);

    // cout<<intersectionPt(head1, head2)<<endl;

    display(head1);
    display(head2);
    node* newHead = mergeRecursive(head1, head2);
    display(newHead);

    return 0;
}