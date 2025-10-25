class Solution {
    int solve(int i,int j,vector<int>& arr,vector<vector<int>>& dp) {
        if(i == j)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        
        int mini = 1e9;
        for(int k=i;k<j;k++) {
            int cur = solve(i,k,arr,dp) + solve(k+1,j,arr,dp) + arr[i]*arr[k+1]*arr[j+1];
            mini = min(mini,cur);
        }
        return dp[i][j] = mini;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(0,n-2,arr,dp);
    }
};