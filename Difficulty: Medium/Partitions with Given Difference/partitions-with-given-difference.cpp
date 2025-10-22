class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int total = accumulate(arr.begin(),arr.end(),0);
        vector<int> prev(total+1,0);
        
        if(arr[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;
        
        if(arr[0] != 0)
            prev[arr[0]] = 1;
        
        for(int i=1;i<n;i++) {
            vector<int> cur(total+1,0);
            for(int j=0;j<=total;j++) {
                if(arr[i] <= j) {
                    cur[j] = prev[j-arr[i]];
                }
                cur[j] += prev[j];
            }
            prev = cur;
        }
        
        int ways = 0;
        for(int i=0;i<=total/2;i++) {
            int sum1 = i;
            int sum2 = total-i;
            if(abs(sum1-sum2) == d)
                ways += prev[i];
        }
        
        return ways;
    }
};