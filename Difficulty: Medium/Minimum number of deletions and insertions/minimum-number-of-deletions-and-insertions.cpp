class Solution {

  public:
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        int n = s1.length();
        int m = s2.length();
        vector<int> prev(m+1,0);

        for(int i=1;i<=n;i++) {
            vector<int> cur(m+1,0);
            for(int j=1;j<=m;j++) {
                if(s1[i-1] == s2[j-1]) 
                    cur[j] = 1 + prev[j-1];
                else
                    cur[j] = max(prev[j],cur[j-1]);
            }
            prev = cur;
        }

        return (n+m)-2*prev[m];
    }
};