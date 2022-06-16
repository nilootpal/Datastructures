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

int count(Node* root){
    if(root == NULL){
        return 0;
    }

    return count(root->right) + count(root->left) + 1;
}

int nodeSum(Node* root){
    if(root == NULL){
        return 0;
    }
    return nodeSum(node->right) + nodeSum(node->left) + root->data;
}

int Maxheight(Node* root){
    if(root->NULL){
        return 0;
    }
    int leftHeight = Maxheight(root->left);
    int rightHeight = Maxheight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int Diameter(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = Maxheight(root->left);
    int rightHeight = Maxheight(root->right);

    int currDiameter = leftHeight + rightHeight + 1;

    int lDia = Diameter(root->left);
    int rDia = Diameter(root->right);

    return max(lDia, rDia, currDiameter);
}

int calcDiameter(Node *root, int * height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;

    int lDia = calcDiameter(root->left &lh);
    int rDia = calcDiameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDia, rDia));
}

int main(){
    return 0;
}