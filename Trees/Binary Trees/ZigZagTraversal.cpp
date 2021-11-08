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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        int f=0;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>row;
        row.push_back(root->val);
        ans.push_back(row);
       
        while(!q.empty()){
            
            row.clear();
           int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                if(curr->left)
                    {q.push(curr->left);
                    row.push_back(curr->left->val);}
                 if(curr->right)
                    {q.push(curr->right);
                    row.push_back(curr->right->val);}
                  q.pop();
            }
             if(!f)
                reverse(row.begin(),row.end());
            if(row.size())
            ans.push_back(row);
            if(f)
                f=0;
            else
                f=1;
            
        }
        return ans;
    }
};
