class Solution {
public:
    int n;
    int solve(int i,vector<int>& coins,int target,int sum,vector<vector<int>>& dp) {
        if(sum == target) {
            return 0;
        }

        if(i>=n || sum > target) {
            return 1e9;
        }

        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }

        int nottake = solve(i+1,coins,target,sum,dp);
        int take = 1e9;
        if(coins[i] <= target - sum) {
            take = 1 + solve(i,coins,target,sum + coins[i],dp);
        }
        return dp[i][sum] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = solve(0,coins,amount,0,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};
