//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getIdx(vector<int>& lis,int num) {
        int idx = lis.size();
        int lo = 0;
        int hi = lis.size()-1;
        while(lo <= hi) {
            int mid = lo+(hi-lo)/2;
            if(lis[mid] < num)
                lo = mid + 1;
            else {
                idx = mid;
                hi = mid - 1;
            }
        }
        return idx;
    }
    int lis(vector<int>& arr) {
        vector<int> lis;
        lis.push_back(INT_MIN);
        for(int& cur : arr) {
            int idx = getIdx(lis,cur);
            if(idx == lis.size())
                lis.push_back(cur);
            else
                lis[idx] = cur;
        }
        return lis.size()-1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends