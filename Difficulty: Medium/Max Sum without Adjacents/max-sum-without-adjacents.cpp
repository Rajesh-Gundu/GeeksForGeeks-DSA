// User function template for C++
class Solution {
    int solve(int idx,vector<int>& arr,vector<int>& dp) {
        if(idx < 0) return 0;
        if(dp[idx] != -1)   return dp[idx];
        int include = arr[idx] + solve(idx-2,arr,dp);
        int exclude = solve(idx-1,arr,dp);
        return dp[idx] = max(include,exclude);
    }
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n,-1);
        solve(n-1,arr,dp);
        return dp[n-1];
    }
};