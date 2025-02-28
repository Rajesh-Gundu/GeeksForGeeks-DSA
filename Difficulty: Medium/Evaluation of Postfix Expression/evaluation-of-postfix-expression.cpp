//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getResult(int a,int b,string s) {
        if(s == "+") return (a+b);
        else if(s == "-") return (a-b);
        else if(s == "*") return (a*b);
        return (a/b);
    }
    bool isOperator(string s) {
        if(s == "+" || s == "-" || s == "*" || s == "/")
            return true;
        return false;
    }
    int evaluate(vector<string>& arr) {
        stack<int> st;
        for(auto& s : arr) {
            if(isOperator(s)) {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int res = getResult(a,b,s);
                st.push(res);
            }
            else {
                int num = stoi(s);
                st.push(num);
            }
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends