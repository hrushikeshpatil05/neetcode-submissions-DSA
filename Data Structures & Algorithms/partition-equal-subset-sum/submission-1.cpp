class Solution {
public:
    int n;
    bool solve(int i,vector<int>& nums,int sum,vector<vector<int>>& dp) {
        if(i >= n) {
            return false;
        }
        if(sum == 0) {
            return true;
        }

        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }

        bool nottake = solve(i+1,nums,sum,dp);
        bool take = false;
        if(sum - nums[i] >= 0) {
            take = solve(i+1,nums,sum - nums[i],dp);
        }
        return dp[i][sum] = take | nottake;

    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int totalSum = 0;
        for(auto x: nums) totalSum += x;
        if(totalSum%2 != 0) {
            return false;
        }
        vector<vector<int>>dp(n+1,vector<int>(totalSum,-1));
        return solve(0,nums,totalSum/2,dp);
    }
};
