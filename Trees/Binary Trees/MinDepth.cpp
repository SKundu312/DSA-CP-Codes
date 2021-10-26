/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root){
         if(root==NULL)
            return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
         return 1+max(l,r);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        int l=0,r=0;
        if(root->left!=NULL)
        l=minDepth(root->left);
        if(root->right!=NULL)
        r=minDepth(root->right);
        
        if(l && r)
         return 1+min(l,r);
        else
           return 1+max(l,r);  
    }
};
