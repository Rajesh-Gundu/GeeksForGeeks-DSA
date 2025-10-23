// User function Template for C++

class Solution {
    int solve(int idx,int cap,vector<int>& val, vector<int>& wt,vector<vector<int>>& dp) {
        if(idx == 0) return ((cap/wt[0]) * val[0]);
        if(dp[idx][cap] != -1)  return dp[idx][cap];
        
        int take = INT_MIN;
        if(cap >= wt[idx])
            take = val[idx] + solve(idx,cap-wt[idx],val,wt,dp);
        int skip = solve(idx-1,cap,val,wt,dp);
        
        return dp[idx][cap] = max(take,skip);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n,vector<int> (capacity+1,-1));
        return solve(n-1,capacity,val,wt,dp);
    }
};