class Solution {
public:
    int n;
    int solve(int i,vector<int>& nums, int prev,vector<vector<int>>& dp) {
        if(i>=n) {
            return 0;
        }

        if(dp[i][prev+1] != -1) {
            return dp[i][prev+1];
        }

        int nottake = solve(i+1,nums,prev,dp);
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(i+1,nums,i,dp);
        }
        return dp[i][prev+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,nums,-1,dp);
    }
};
