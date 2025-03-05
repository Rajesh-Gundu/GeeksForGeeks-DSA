//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool static cmp(const string& a, const string& b) {
        return a.size() < b.size();
    }
    
    int longestStringChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        unordered_map<string,int> dp;
        int ans = 1;
        for(auto& w : words) {
            dp[w] = 1;
            for(int i=0;i<w.length();i++) {
                string temp = w.substr(0,i) + w.substr(i+1);
                if(dp.count(temp)) {
                    dp[w] = max(dp[w],dp[temp]+1);
                }
            }
            ans = max(ans,dp[w]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends