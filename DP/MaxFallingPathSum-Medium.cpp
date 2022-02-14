//recursive TC=O(3^n)
//Memoization
//TC=o(n*m)
int f(int i,int j,vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(j<0 || j>=matrix[i].size()) return -1e9;
    if(i==0) return matrix[0][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int up = matrix[i][j]+f(i-1,j,matrix,dp);
    int ld = matrix[i][j]+f(i-1,j-1,matrix,dp);
    int rd = matrix[i][j]+f(i-1,j+1,matrix,dp);
    return dp[i][j]=max(up,max(ld,rd));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int maxi=-1e9;
    for(int i=0;i<m;i++){
        if(maxi<f(n-1,i,matrix,dp))
            maxi=f(n-1,i,matrix,dp);
    }
    return maxi;
}
