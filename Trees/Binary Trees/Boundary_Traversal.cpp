#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};
struct Node *newNode(int item){
    struct Node *temp = (struct Node *)malloc(
                          sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}


bool isLeaf(struct Node* n){
    if(n->left==NULL && n->right==NULL)
    return true;
    else 
    return false;
}

void leaves(struct Node* n,queue<struct Node*>&q){
    
    if(isLeaf(n)){
      q.push(n);
       
    }
    if(n->left)
    leaves(n->left,q);
    if(n->right)
    leaves(n->right,q);
    
}

stack<struct Node*>st;
void rightBoundary(struct Node* n,queue<struct Node*>&q){
    if(n==NULL)
    return;
    if(n->left==NULL&&n->right==NULL)
    return;
    st.push(n);
    if(n->right!=NULL)
    rightBoundary(n->right,q);
    else
   rightBoundary(n->left,q);
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}

void leftBoundary(struct Node* n,queue<struct Node*>&q){
    if(n==NULL)
    return;
    if(n->left==NULL&&n->right==NULL)
    return;
    q.push(n);
    if(n->left!=NULL)
    leftBoundary(n->left,q);
    else
    leftBoundary(n->right,q);
}

void printQ(queue<struct Node*>&q){
    while(!q.empty()){
       cout<<q.front()->data<<endl;
       q.pop();
    }
    return;}
    
int main() {
    queue<struct Node*>q;
	  struct Node *n = newNode(1);
    n->left = newNode(2);
    n->right = newNode(3);
    n->left->left = newNode(4);
    n->left->right = newNode(5);
    n->right->left = newNode(6);
    n->right->right = newNode(7);
    n->right->left->right = newNode(8);
    
    leftBoundary(n,q);
    leaves(n,q);
    rightBoundary(n->right,q);
    printQ(q);
	return 0;
}
