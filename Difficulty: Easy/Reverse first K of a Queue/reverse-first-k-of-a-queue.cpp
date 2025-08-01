class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(q.size() < k)
            return q;
        stack<int> st;
        while(k--) {
            st.push(q.front());
            q.pop();
        }
        queue<int> ans;
        while(!st.empty()) {
            ans.push(st.top());
            st.pop();
        }
        while(!q.empty()) {
            ans.push(q.front());
            q.pop();
        }
        return ans;
    }
};