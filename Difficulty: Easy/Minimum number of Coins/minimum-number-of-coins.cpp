class Solution {
  public:
    int findMin(int n) {
        // code here
        vector<int> currency = {1,2,5,10};
        int ans = 0;
        int idx = 3;
        while(n) {
            int take = n/currency[idx];
            ans += (take);
            n -= (take*currency[idx]);
            idx--;
        }
        return ans;
    }
};