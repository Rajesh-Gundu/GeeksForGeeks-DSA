// User function Template for C++

class Solution {
  public:
    int findNoOfOnes(int i,int n) {
        int cnt = 0;
        int p = n/(1ll<<(i+1));
        cnt += (p*(1<<i));
        int r = (n - (p*(1ll<<(i+1))));
        if(r > (1<<i)) {
            cnt += (r-(1<<i));
        }
        return cnt;
    }
    int findXOR(int l, int r) {
        // complete the function here
        int ans = 0;
        for(int i=0;i<31;i++) {
            int x = findNoOfOnes(i,r+1);
            int y = findNoOfOnes(i,l);
            if((x-y)&1)
                ans += (1<<i);
        }
        return ans;
    }
};