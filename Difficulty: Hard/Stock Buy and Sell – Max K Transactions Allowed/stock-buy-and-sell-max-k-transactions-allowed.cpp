//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& prices, int k,int idx,bool isBuy,vector<vector<vector<int>>>& dp) {
        if(idx == prices.size() || k == 0)
            return 0;
        
        if(dp[idx][k][isBuy] != -1) 
            return dp[idx][k][isBuy];
            
        int include = 0;
        int not_include = 0;
        if(isBuy) {
            include = prices[idx] + solve(prices,k-1,idx+1,false,dp);
            not_include = solve(prices,k,idx+1,isBuy,dp);
        }
        else {
            include = -prices[idx] + solve(prices,k,idx+1,true,dp);
            not_include = solve(prices,k,idx+1,isBuy,dp);
        }
        
        return dp[idx][k][isBuy] = max(include,not_include);
    }
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (k+1,vector<int> (2,-1)));
        return solve(prices,k,0,false,dp);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends