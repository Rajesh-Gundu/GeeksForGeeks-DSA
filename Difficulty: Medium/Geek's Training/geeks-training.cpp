class Solution {
    int solve(int idx,int last,vector<vector<int>>& arr,vector<vector<int>>& dp) {
        if(idx < 0) return 0;
        if(dp[idx][last] != -1) return dp[idx][last];
        
        int maxi = 0;
        for(int task=0;task<3;task++) {
            if(task != last) {
                maxi = max(maxi,arr[idx][task] + solve(idx-1,task,arr,dp));
            }
        }
        return dp[idx][last] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (4,-1));
        solve(n-1,3,arr,dp);
        return dp[n-1][3];
    }
};