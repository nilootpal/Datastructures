#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node( int value ){
        data=value;
        left=NULL;
        right=NULL;
    }
};

bool isBalanced(Node* root){
    if(root == NULL){
        return true;
    }
    if(isBalanced(root->left) == false){
        return false;
    }
    if(isBalanced(root->right) == true){
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh - rh) <= 1){
        return true;
    }
    else{
        return false;
    }
}

void sumReplace(Node* root){
    if(root == NULL){
        return ;
    }

    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left != NULL){
        root->data += root->left->data;
    }

    if(root->right != NULL){
        root->data += root->right->data;
    }
}

int main(){
    return 0;
}