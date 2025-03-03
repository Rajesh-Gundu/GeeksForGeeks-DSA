//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        deque<pair<int,int>> maxDq;
        deque<pair<int,int>> minDq;
        maxDq.push_back({arr[0],0});
        minDq.push_back({arr[0],0});
        int curL = 0;
        int curR = 1;
        int ansL = 0;
        int ansR = 0;
        while(curR < n) {
            
            while(!maxDq.empty() && maxDq.back().first < arr[curR])
                maxDq.pop_back();
            maxDq.push_back({arr[curR],curR});
            
            while(!minDq.empty() && minDq.back().first > arr[curR])
                minDq.pop_back();
            minDq.push_back({arr[curR],curR});
            
            if(maxDq.front().first-minDq.front().first > x) {
                if(maxDq.front().first == arr[curR]) {
                    while((maxDq.front().first-minDq.front().first > x)) {
                        curL = minDq.front().second+1;
                        minDq.pop_front();
                    }
                }
                else {
                    while((maxDq.front().first-minDq.front().first > x)) {
                        curL = maxDq.front().second+1;
                        maxDq.pop_front();
                    }
                }
            }
            
            if((curR-curL+1) > (ansR-ansL+1)) {
                ansL = curL;
                ansR = curR;
            }
            curR++;
        }
        
        vector<int> ans(ansR-ansL+1);
        int i = 0;
        while(ansL <= ansR) {
            ans[i++] = arr[ansL];
            ansL++;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends