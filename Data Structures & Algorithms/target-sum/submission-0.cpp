class Solution {
public:
    int n;
    int solve(int i,vector<int>& nums,int target,int sum) {
        if(i == n && target == sum) return 1;

        if(i>=n) return 0;

        int plus = solve(i+1,nums,target,sum+nums[i]);
        int minus = solve(i+1,nums,target,sum-nums[i]);

        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        return solve(0,nums,target,0);
    }
};
