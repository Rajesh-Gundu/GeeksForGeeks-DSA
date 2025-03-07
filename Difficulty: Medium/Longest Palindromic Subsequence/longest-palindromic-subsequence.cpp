//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    
    int longestPalinSubseq(string &s) {
        int n = s.length();
        if(n == 1)
            return 1;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        for(int i=0;i<n-1;i++) {
            dp[i][i] = 1;
            dp[i][i+1] = (s[i] == s[i+1]) ? 2 : 1;
        }
        dp[n-1][n-1]  = 1;
        for(int i=n-3;i>=0;i--) {
            for(int j=i+2;j<n;j++) {
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends