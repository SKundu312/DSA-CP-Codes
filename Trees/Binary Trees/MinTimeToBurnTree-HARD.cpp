#include<bits/stdc++.h>
int timeMap(map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &m, BinaryTreeNode<int>* target){
    map<BinaryTreeNode<int>*,int> vis;
    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    int t=0;
    vis[target]=1;
    while(!q.empty()){
        int size=q.size();
        int fl=0;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* curr=q.front();
            q.pop();
            if(curr->left && !vis[curr->left]){
                fl=1;
                vis[curr->left]=1;
                q.push(curr->left);
            }
            if(curr->right && !vis[curr->right]){
                fl=1;
                vis[curr->right]=1;
                q.push(curr->right);
            }
            if(m[curr] && !vis[m[curr]]){
                fl=1;
                vis[m[curr]]=1;
                q.push(m[curr]);
            }
        }
        if(fl) t++;
    }
    return t;
}
BinaryTreeNode<int>* toParent(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>& m, int start){
    BinaryTreeNode<int>* res;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* curr=q.front();
        q.pop();
        if(curr->data==start) res=curr;
        if(curr->left){
            m[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            m[curr->right]=curr;
            q.push(curr->right);
        }
    }
    return res;
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> m;
    BinaryTreeNode<int>* target=toParent(root,m,start);
    return timeMap(m,target);
}
