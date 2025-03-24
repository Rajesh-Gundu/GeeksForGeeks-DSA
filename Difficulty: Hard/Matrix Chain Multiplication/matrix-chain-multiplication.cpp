//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int solve(vector<int> &arr,int i,int j,vector<vector<int>>& dp) {
        if(i+1 == j)
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int res = INT_MAX;
        for(int k=i+1;k<j;k++) {
            int cur = solve(arr,i,k,dp) + solve(arr,k,j,dp) + arr[i]*arr[k]*arr[j];
            res = min(res,cur);
        }
        
        return dp[i][j] = res;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(arr,0,n-1,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends