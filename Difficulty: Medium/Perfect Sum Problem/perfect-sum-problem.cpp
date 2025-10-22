class Solution {
    int memoi(int idx,int target,vector<int>& arr,vector<vector<int>>& dp) {
        if(target < 0)  return 0;
        if(idx < 0) return target == 0;
        if(dp[idx][target] != -1)   return dp[idx][target];
        
        return dp[idx][target] = memoi(idx-1,target-arr[idx],arr,dp) + memoi(idx-1,target,arr,dp);
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return memoi(n-1,target,arr,dp);
    }
};