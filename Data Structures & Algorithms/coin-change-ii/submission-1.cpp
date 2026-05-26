class Solution {
public:
    int n;
    int solve(int i,int amount,vector<int>& coins,int sum,vector<vector<int>>& dp) {
        if(sum == amount) {
            return 1;
        }
        if(i>=n || sum>amount) {
            return 0;
        }
        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }
        int nottake = solve(i+1,amount,coins,sum,dp);
        int take = 0;
        if(coins[i] + sum <= amount) {
            // int case1 = solve(i+1,amount,coins,sum+coins[i],dp);
            int case2 = solve(i,amount,coins,sum+coins[i],dp);
            take = case2;
        }
        return dp[i][sum] = take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(0,amount,coins,0,dp);
    }
};
