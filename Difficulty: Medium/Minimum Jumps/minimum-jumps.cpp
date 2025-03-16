//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr,int i,vector<int>& dp) {
        if(i >= arr.size()-1)
            return 0;
            
        if(dp[i] != -1) return dp[i];
        
        int mini = 1e7;
        int j = i+1;
        int steps = arr[i];
        while(j < arr.size() && steps) {
            mini = min(mini,solve(arr,j,dp));
            steps--;
            j++;
        }
        
        return dp[i] = mini + 1;
    }
    
    int minJumps(vector<int>& arr) {
        vector<int> dp(arr.size(),-1);
        int ans = solve(arr,0,dp);
        return (ans >= 1e7) ? -1 : ans; 
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends