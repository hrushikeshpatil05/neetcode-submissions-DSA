class Solution {
public:
    int n;
    int solve(int i,vector<int>& prices,int status,vector<vector<int>>& dp) {

        if(i>=n) {
            return 0;
        }
        if(dp[i][status] != -1) {
            return dp[i][status];
        }

        int profit = 0;

        if(!status) {
            int case1 = (-1*prices[i]) + solve(i+1,prices,1,dp);
            int case2 = 0 + solve(i+1,prices,0,dp);
            profit = max(case1,case2);
        }
        else {
            int case1 = prices[i] + solve(i+2,prices,0,dp);
            int case2 = solve(i+1,prices,1,dp);
            profit = max(case1,case2);
        }

        return dp[i][status] = profit;
        
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,prices,0,dp);
    }
};
