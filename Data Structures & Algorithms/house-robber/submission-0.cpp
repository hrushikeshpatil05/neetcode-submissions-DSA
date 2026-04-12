class Solution {
public:
    int n;

    int solve(int currIdx,vector<int>& nums,int prevIdx,vector<vector<int>>& dp) {
        if(currIdx>=n) {
            return 0;
        }

        if(dp[currIdx][prevIdx+1] != -1) {
            return dp[currIdx][prevIdx+1];
        }

        int take = 0;
        int nottake = solve(currIdx+1,nums,prevIdx,dp);

        if(prevIdx == -1 || currIdx - 1 != prevIdx) {
            take = nums[currIdx] + solve(currIdx+1,nums,currIdx,dp);
        }
        return dp[currIdx][prevIdx+1] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,nums,-1,dp);
    }
};
