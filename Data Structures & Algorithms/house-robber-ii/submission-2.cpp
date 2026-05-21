class Solution {
public:
    int n;
    int solve(int i, vector<int>& nums,int end, vector<int>& dp) {
        if(i > end) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int nottake = solve(i+1,nums,end,dp);
        int take = nums[i] + solve(i+2,nums,end,dp);
        return dp[i] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        int ans1 = solve(0,nums,n-2,dp1);
        int ans2 = solve(1,nums,n-1,dp2);
        return max(ans1,ans2);
    }
};
