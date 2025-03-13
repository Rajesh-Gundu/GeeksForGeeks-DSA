//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int memoi(vector<int> &val, vector<int> &wt,int w,int i,vector<vector<int>>& dp) {
        if(i <= 0 || w <= 0)
            return 0;
        if(dp[i-1][w-1] != -1)
            return dp[i-1][w-1];
        int skip = memoi(val,wt,w,i-1,dp);
        int take = (w >= wt[i-1]) ? (memoi(val,wt,w-wt[i-1],i-1,dp)+val[i-1]) : 0;
        return dp[i-1][w-1] = max(skip,take);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(val.size(),vector<int> (W,-1));
        return memoi(val,wt,W,val.size(),dp);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends