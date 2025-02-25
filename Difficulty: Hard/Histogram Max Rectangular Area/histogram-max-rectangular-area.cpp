//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        vector<int> right(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(!st.empty())
                right[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        int ans = 0;
        for(int i=0;i<n;i++) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            int left = (st.empty()) ? -1 : st.top();
            int width = (right[i] - left - 1);
            int area = width*arr[i];
            ans = max(ans,area);
            st.push(i);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends