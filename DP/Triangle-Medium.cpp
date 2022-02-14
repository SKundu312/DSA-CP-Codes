//Memoization
int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp,int n){
    if(i==n-1) return triangle[n-1][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int diag=triangle[i][j]+f(i+1,j+1,triangle,dp,n);
    int dwn=triangle[i][j]+f(i+1,j,triangle,dp,n);
    return dp[i][j]=min(dwn,diag);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return f(0,0,triangle,dp,n);
}
