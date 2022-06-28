#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node( int val ){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST( Node* root, int val ){
    if(root == NULL){
        return new Node(val);
    }

    if( val < root->data){
        root->left = insertBST(root->left, val);
    }else{
        root->right = insertBST(root->right, val);
    }

    return root;
}

Node* searchBST(Node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(root->data == key){
        return root;
    }
    
    if(root->data > key){
        searchBST(root->left, key);
    }
    else{
        searchBST(root->right, key);
    }
}

void inorder( Node* root ){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 2);
    insertBST(root, 3);
    insertBST(root, 4);

    inorder(root);
    return 0;
}