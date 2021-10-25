#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(
                          sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
queue<Node*>q;
void rightview(struct Node* n,int l){
    if(n==NULL)
    return;
    if(l==q.size())
    q.push(n);
    rightview(n->right,l+1);
    rightview(n->left,l+1);
}
void printQ(){
    while(!q.empty()){
       cout<<q.front()<<endl;
       q.pop();
    }
    return;
}

int main() {
	// your code goes here
	
    struct Node *n = newNode(1);
    n->left = newNode(2);
    n->right = newNode(3);
    n->left->left = newNode(4);
    n->left->right = newNode(5);
    n->right->left = newNode(6);
    n->right->right = newNode(7);
    n->right->left->right = newNode(8);
 
    rightview(n,0);
    printQ();
	return 0;
}
