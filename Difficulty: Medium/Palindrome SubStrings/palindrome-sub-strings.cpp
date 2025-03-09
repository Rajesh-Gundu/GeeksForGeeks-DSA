//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++) {
            int p1 = i;
            int p2 = i;
            while(p1 >= 0 && p2 < n && s[p1] == s[p2]) {
                p1--;
                p2++;
            }
            
            if(p2-p1-1 > 1) {
                ans += (p2-p1-1)/2;
            }
            
            p1 = i;
            p2 = i+1;
            while(p1 >= 0 && p2 < n && s[p1] == s[p2]) {
                p1--;
                p2++;
            }
            
            if(p2-p1-1 > 1) {
                ans += (p2-p1-1)/2;
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends