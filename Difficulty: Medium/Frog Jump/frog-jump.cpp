class Solution {
    int memoi(int n,vector<int>& height,vector<int>& dp) {
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int jumpOneStep = abs(height[n]-height[n-1]) + memoi(n-1,height,dp);
        int jumpTwoSteps = INT_MAX;
        if(n > 1)
            jumpTwoSteps = abs(height[n]-height[n-2]) + memoi(n-2,height,dp);
        
        return dp[n] = min(jumpOneStep,jumpTwoSteps);
    }
    
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n,-1);
        dp[0] = 0;
        memoi(n-1,height,dp);
        return dp[n-1];
    }
};