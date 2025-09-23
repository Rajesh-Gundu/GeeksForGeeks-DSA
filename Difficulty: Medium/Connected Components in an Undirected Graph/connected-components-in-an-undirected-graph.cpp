
class Solution {
    void dfs(int node,vector<bool>& vis, vector<vector<int>>& adj,vector<int>& cur) {
        vis[node] = true;
        cur.push_back(node);
        for(auto& v : adj[node]) {
            if(!vis[v]) 
                dfs(v,vis,adj,cur);
        }
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(V,false);
        vector<vector<int>> ans;
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                vector<int> cur;
                dfs(i,vis,adj,cur);
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
