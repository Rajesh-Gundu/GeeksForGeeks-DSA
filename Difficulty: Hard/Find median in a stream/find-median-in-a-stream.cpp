//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int>maxi;
        priority_queue<int,vector<int>,greater<int>>mini;
        maxi.push(arr[0]);
        int n = arr.size();
        vector<double>ans(n);
        ans[0] = (double)arr[0];
        for(int i=1;i<n;i++){
            if(arr[i] >= maxi.top())
                mini.push(arr[i]);
            else
                maxi.push(arr[i]);
            if(abs(maxi.size()-mini.size()) > 1){
                if(maxi.size() > mini.size()){
                    mini.push(maxi.top());
                    maxi.pop();
                }
                else{
                    maxi.push(mini.top());
                    mini.pop();
                }
            }
            if(abs(maxi.size()-mini.size()) == 0){
                ans[i] = (double)(maxi.top()+mini.top())/2;
            }
            else{
                ans[i] = (double)maxi.top();
            }
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends