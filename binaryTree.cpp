#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(struct Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" "; 
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node* root){
    if(root == NULL){
        return;
    }

    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}

void postOrder(struct Node* root){
    if(root == NULL){
        return;
    }

    preOrder(root->left);
    preOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preOrder(root);
    cout<<endl;

    return 0;
}