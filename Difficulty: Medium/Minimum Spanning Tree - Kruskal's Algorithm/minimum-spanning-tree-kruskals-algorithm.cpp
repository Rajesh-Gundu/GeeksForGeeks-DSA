// User function Template for C++
class DisjointSet {
    vector<int> par,size;
public :
    
    DisjointSet(int n) {
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
            par[i] = i;
    } 
    
    int find(int x) {
        if(par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    
    void unionBySize(int u,int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)
            return;
        if(size[pu] >= size[pv]) {
            par[pv] = pu;
            size[pu] += size[pv];
        }
        else {
            par[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
  public:
    bool static comp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),comp);
        int sum = 0;
        DisjointSet ds(V+1);
        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(ds.find(u) == ds.find(v))
                continue;
            sum += w;
            ds.unionBySize(u,v);
        }
        return sum;
    }
};