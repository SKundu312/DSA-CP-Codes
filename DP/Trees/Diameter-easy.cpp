 int f(TreeNode* root, int &res){
        if(root==NULL)
            return 0;
        int l=f(root->left,res);
        int r=f(root->right,res);
        int height=1+max(l,r);
        res=max(1+l+r,res);
        return height;
    }
     int diameterOfBinaryTree(TreeNode* root) {
         int res=-1e9;
        int temp= f(root,res);
         return res-1;
     }
