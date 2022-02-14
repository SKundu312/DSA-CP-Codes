//Memoization
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
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    int s=0;
    for(int i=0;i<n;i++)
        s+=arr[i];
    if(s%2) return false;
    int k=s/2;
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    return f(n-1,k,arr,dp);
}

