//Position this line where user code will be pasted.
class Solution {
    void dfs(int node,vector<vector<int>> &adj,vector<bool>& vis,stack<int>& seq) {
        vis[node] = true;
        for(auto& v : adj[node]) {
            if(!vis[v])
                dfs(v,adj,vis,seq);
        }
        seq.push(node);
    }
    
    void exploreSCC(int node,vector<vector<int>>& adj,vector<bool>& vis) {
        vis[node] = true;
        for(auto& v : adj[node]) {
            if(!vis[v])
                exploreSCC(v,adj,vis);
        }
    }
    
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<bool> vis(n,false);
        stack<int> seq;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(i,adj,vis,seq);
            }
        }
        
        vector<vector<int>> revadj(n);
        for(int u=0;u<n;u++) {
            for(auto& v : adj[u]) {
                revadj[v].push_back(u);
            }
        }
        
        int cnt = 0;
        fill(vis.begin(),vis.end(),false);
        
        while(!seq.empty()) {
            int node = seq.top();
            seq.pop();
            if(vis[node])
                continue;
            cnt++;
            exploreSCC(node,revadj,vis);
        }
        return cnt;
    }
};