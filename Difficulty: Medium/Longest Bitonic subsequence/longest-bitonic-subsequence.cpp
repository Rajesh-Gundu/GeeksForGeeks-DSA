
class Solution {
    int getIndex(vector<int>& lis,int num) {
        int lo = 0;
        int hi = lis.size();
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(lis[mid] < num) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return lo;
    }
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n);
        vector<int> dp2(n);
        
        vector<int> lis;
        for(int i=0;i<n;i++) {
            if(i == 0 || lis.back() < nums[i]) {
                lis.push_back(nums[i]);
                dp1[i] = lis.size(); 
            }
            else {
                int idx = getIndex(lis,nums[i]);
                lis[idx] = nums[i];
                dp1[i] = idx+1;
            }
        }
        
        lis.resize(0);
        for(int i=n-1;i>=0;i--) {
            if(i == n-1 || lis.back() < nums[i]) {
                lis.push_back(nums[i]);
                dp2[i] = lis.size();
            }
            else {
                int idx = getIndex(lis,nums[i]);
                lis[idx] = nums[i];
                dp2[i] = idx+1;
            }
        }
        
        int ans = 0;
        for(int i=1;i<n-1;i++) {
            if(dp1[i] > 1 && dp2[i] > 1) {
                ans = max(ans,dp1[i]+dp2[i]-1);
            }
        }
        return ans;
    }
};
