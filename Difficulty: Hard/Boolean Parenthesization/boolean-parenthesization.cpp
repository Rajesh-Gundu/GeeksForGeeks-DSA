//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
    bool evaluate(int b1, int b2, char op)
    {
        if (op == '&')
        {
            return b1 & b2;
        }
        else if (op == '|')
        {
            return b1 | b2;
        }
        return b1 ^ b2;
    }
    int countRecur(int i, int j, int req, string &s, vector<vector<vector<int>>> &memo)
    {
    
        if (i == j)
        {
            return (req == (s[i] == 'T')) ? 1 : 0;
        }
    
        if (memo[i][j][req] != -1)
            return memo[i][j][req];
    
        int ans = 0;
        for (int k = i + 1; k < j; k += 1)
        {
    
            int leftTrue = countRecur(i, k - 1, 1, s, memo);
            int leftFalse = countRecur(i, k - 1, 0, s, memo);
            int rightTrue = countRecur(k + 1, j, 1, s, memo);
            int rightFalse = countRecur(k + 1, j, 0, s, memo);
    
            if (evaluate(1, 1, s[k]) == req)
            {
                ans += leftTrue * rightTrue;
            }
            if (evaluate(1, 0, s[k]) == req)
            {
                ans += leftTrue * rightFalse;
            }
            if (evaluate(0, 1, s[k]) == req)
            {
                ans += leftFalse * rightTrue;
            }
            if (evaluate(0, 0, s[k]) == req)
            {
                ans += leftFalse * rightFalse;
            }
        }
    
        return memo[i][j][req] = ans;
    }
  public:
    int countWays(string &s) {
        // code here
        int n = s.length();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return countRecur(0, n - 1, 1, s, memo);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends