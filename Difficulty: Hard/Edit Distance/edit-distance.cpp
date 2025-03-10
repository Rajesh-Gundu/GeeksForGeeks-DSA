//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int solve(string& s1, string& s2,int i,int j,vector<vector<int>>& dp) {
        
        if(i >= s1.length())
            return (s2.length() - j);
        if(j >= s2.length())
            return (s1.length() - i);
            
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = solve(s1,s2,i+1,j+1,dp);
            
        return dp[i][j] = min({solve(s1,s2,i+1,j+1,dp),solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp)}) + 1;
    }
    
    int editDistance(string& s1, string& s2) {
        // code here
        vector<vector<int>> dp(s1.length(),vector<int> (s2.length(),-1));
        return solve(s1,s2,0,0,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends