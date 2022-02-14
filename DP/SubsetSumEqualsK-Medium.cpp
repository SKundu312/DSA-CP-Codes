//Memoization
//TC=O(ind*target)
bool f(int ind,int target,vector<int> &arr,vector<vector<bool>> &dp ){
    if(target==0)
        return true;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=false)
        return dp[ind][target];
        
    bool notTaken = f(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<=target)
        taken = f(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken||taken;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    return f(n-1,k,arr,dp);
}
