class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int totalXor = 0;
        unordered_map<int,int> mp;
        long ans = 0;
        mp[0] = 1;
        for(int i=0;i<n;i++) {
            totalXor ^= arr[i];
            if(mp.count(totalXor ^ k)) {
                ans += mp[totalXor ^ k];
            }
            mp[totalXor]++;
        }
        return ans;
    }
};