int maxPath(TreeNode* node,int &maxi){
        if(node==NULL)
            return 0;
        int leftsum=max(0,maxPath(node->left,maxi));
        int rightsum=max(0,maxPath(node->right,maxi));
        maxi=max(maxi,leftsum+rightsum+node->val);
        return node->val+max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
       int maxi=INT_MIN;
       int sum=maxPath(root,maxi);
       return maxi;
    }
