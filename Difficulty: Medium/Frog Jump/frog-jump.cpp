class Solution {
    int memoi(int n,vector<int>& height,vector<int>& dp) {
        if(n <= 0) return 0;
        if(n == 1)  return abs(height[1]-height[0]);
        if(dp[n] != -1) return dp[n];
        
        int one = memoi(n-1,height,dp)+abs(height[n]-height[n-1]);
        int two = memoi(n-2,height,dp)+abs(height[n]-height[n-2]);
        return dp[n] = min(one,two);
    }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n+1,-1);
        return memoi(n-1,height,dp);
    }
};