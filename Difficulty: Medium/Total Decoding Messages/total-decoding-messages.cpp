//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(string &digits,int i,vector<int>& dp) {
        if(i >= digits.size())
            return 1;
        if(dp[i] != -1) return dp[i];
        
        char ch = digits[i];
        if(ch == '0')
            return dp[i] = 0;
        int ways = solve(digits,i+1,dp);
        if(i+1 < digits.size() && ((ch == '1') || (ch == '2' && digits[i+1] <= '6'))) {
            ways += solve(digits,i+2,dp);
        }
        
        return dp[i] = ways;
    }
    int countWays(string &digits) {
        vector<int> dp(digits.size(),-1);
        return solve(digits,0,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends