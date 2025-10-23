// User function Template for C++

class Solution {
    int solve(int idx,int n,vector<int>& price,vector<vector<int>>& dp) {
        if(idx == 0) return n*price[0];
        if(dp[idx][n] != -1) return dp[idx][n];
        
        int take = 0;
        if(n >= idx+1)
            take = price[idx] + solve(idx,n-(idx+1),price,dp);
        int skip = solve(idx-1,n,price,dp);
        return dp[idx][n] = max(take,skip);
    }
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        
        
        return solve(n-1,n,price,dp);
    }
};