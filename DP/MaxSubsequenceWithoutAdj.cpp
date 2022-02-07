//Memoization
//Time-O(n) Space-O(n)+O(n)
int f(int ind,vector<int>& nums, vector<int>& dp){
    if(ind==0)
        return dp[ind]=nums[ind];
    if(ind<0)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
    int pick=nums[ind]+f(ind-2,nums,dp);
    int notPick=f(ind-1,nums,dp);
    return dp[ind]=max(pick,notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int>dp(nums.size(),-1);
    return f(nums.size()-1,nums,dp);
}


//Tabulation
//Time-O(n) Space-O(1)
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1)
            take+=prev2;
        int nonTake=prev;
        int curr=max(take,nonTake);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
