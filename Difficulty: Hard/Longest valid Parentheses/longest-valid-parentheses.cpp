//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        // code here
      stack<int>st;
      int n = s.length();
      int ans = 0;
      st.push(-1);
      for(int i=0;i<n;i++){
          if(s[i] == '(')
            st.push(i);
        else{
            st.pop();
            if(!st.empty()){
                ans = max(ans,i-st.top());
            }
            else
                st.push(i);
        }
      }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends