class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int a = 0;
        int b = 0;
        int c = 0;
        int ans = 0;
        int n = s.length();
        int p1 = 0;
        int p2 = 0;
        while(p2 < n) {
            char ch = s[p2];
            if(ch == 'a')
                a++;
            else if(ch == 'b')
                b++;
            else
                c++;
            
            while(a && b && c) {
                ans += (n-p2);
                if(s[p1] == 'a')
                    a--;
                else if(s[p1] == 'b')
                    b--;
                else
                    c--;
                p1++;
            }
            
            p2++;
        }
        return ans;
    }
};