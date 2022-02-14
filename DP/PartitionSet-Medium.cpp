//Tabulation
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int s=0;
    for(int i=0;i<n;i++)
        s+=arr[i];
    int k=s;
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    if(arr[0]<=k)
        dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTaken = dp[ind-1][target];
            bool taken = false;
            if(arr[ind]<=target)
              taken = dp[ind-1][target-arr[ind]];
            dp[ind][target]= notTaken||taken;
        }
    }
    int mini=1e9;
    for(int s1=0;s1<=s/2;s1++){
        if(dp[n-1][s1])
           mini=min(mini,abs((s-s1)-s1));
    }
    return mini;
}
