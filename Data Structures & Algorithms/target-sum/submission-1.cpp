class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(auto num:nums) totalSum += num;

        if(target > totalSum) return 0;

        if((totalSum+target)%2 != 0) return 0;

        int subSum = (target+totalSum)/2;

        vector<int>dp(subSum+1,0);
        dp[0] = 1;

        for(int i=0;i<n;i++) {
            for(int j=subSum;j>=nums[i];j--) {
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[subSum];
    }
};
