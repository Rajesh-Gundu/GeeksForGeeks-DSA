//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    bool memoi(int i,int sum,vector<int>& arr,vector<vector<int>>& dp) {
        if(sum == 0)    return true;
        if(i < 0 || sum < 0)   return false;
        if(dp[sum][i] != -1)    return dp[sum][i];
        
        return dp[sum][i] = memoi(i-1,sum-arr[i],arr,dp) || memoi(i-1,sum,arr,dp);
    }
    
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(sum+1,vector<int> (n,-1));
        return memoi(arr.size()-1,sum,arr,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends