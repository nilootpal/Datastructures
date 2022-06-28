#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
}

bool getPath(Node* root, int key, vector<int> &path){
    path.push_back(root->data);
    if(root->data == key){
        return true;
    }
    if(getPath(root->left, key, path) || getPath(root->right, key, path)){
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2){
    vector<int> path1, path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }

    int pc;
    for(pc = 0; pc<path1.size() && path2.size(); ++pc){
        if(path1[pc] != path2[pc]){
            break
        }
    }

    return path1[pc-1];
}

void flatten(Node* root){
    if(root == NULL || root->left == NULL || root->right == NULL){
        return 
    }
    if(root->left != NULL){
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while(t->right != NULL){
            t = t->right;
        }

        t->right = temp;
    }

    flatten(root->right);
}

int main(){

}