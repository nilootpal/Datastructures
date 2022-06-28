#include <iostream>
#include <queue>
#include <vector>
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

void rightView(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for (int i = 0; i < n; i++){
            Node* curr = q.front();
            q.pop();

            if(i == n-1){
                cout<<curr->data<<" ";
            }

            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
        
    }
}

void leftView(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for (int i = 0; i < n; i++){
            Node* curr = q.front();
            q.pop();

            if(i == 0){
                cout<<curr->data<<" ";
            }

            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
        
    }
}

// Node* LCA(Node* root, int n1, int n2){
//     if(root == NULL){
//         return NULL;
//     }

//     if((root->data == n1) || (root->data == n2)){
//         return root;
//     }
    
//     Node* left = LCA(root->left, n1, n2);
//     Node* right = LCA(root->right, n1, n2);

//     if( (left != NULL) && (right != NULL) ){
//         return root;
//     }

//     if( (left == NULL) && (right == NULL) ){
//         return NULL;
//     }

//     if(left != NULL){
//         return LCA(root->left, n1, n2);
//     }

//     return LCA(root->right, n1, n2);
// }

int LCA(Node* root, int n1, int n2){
    vector<int> path1, path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }
}

int findDist(Node* root, int k, int dist){
    if(root == NULL){
        return -1;
    }

    if(root->data == k){
        return dist;
    }

    int left = findDist(root->left, n1, dist+1);
    if( left != -1 ){
        return left;
    }

    return findDist(root->right, n1, dist+1);   
}

int DistBetNodes( Node* root, int n1, int n2 ){
    Node* lca = LCA(root, n1, n2);
    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);

    return d1+d2;
}

int main(){
    return 0;
}