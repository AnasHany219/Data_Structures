#include<bits/stdc++.h>
using namespace std;

struct Node{
    int item;
    Node *left, *right;
};

void LevelOrder(Node *root){
// Check if root is empty
    if(root == NULL)
        return;
    queue<Node *>Q;
    Q.push(root);
    while(!Q.empty()){
        Node *current = Q.front();
        cout << current->item << " ";
        if(current->left != NULL)
            Q.push(current->left);
        if(current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}

// root left right
void PreOrder(Node *root){
// Check if root is not empty
    if(root != NULL){
        cout << root->item << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

// left root right 
void InOrder(Node *root){
// Check if root is not empty
    if(root != NULL){
        PreOrder(root->left);
        cout << root->item << " ";
        PreOrder(root->right);
    }
}

// left right root 
void PostOrder(Node *root){
// Check if root is not empty
    if(root != NULL){
        PreOrder(root->left);
        PreOrder(root->right);
        cout << root->item << " ";
    }
}

int main(){
    return 0;
}
