//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& coins, int sum,int i,vector<vector<int>>& dp) {
        if(sum == 0)
            return 0;
        if(i < 0)
            return 1e7;
            
        if(dp[i][sum] != -1)
            return dp[i][sum];
            
        int not_take = solve(coins,sum,i-1,dp);
        int take = (sum >= coins[i]) ? (1 + solve(coins,sum-coins[i],i,dp)) : 1e7;
        
        return dp[i][sum] = min(not_take,take);
    }
  
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        int ans = solve(coins,sum,coins.size()-1,dp);
        return (ans == 1e7) ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends