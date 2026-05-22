class Solution {
public:
    int n;
    int solve(int i,vector<int>& coins,int target,int sum) {
        if(i>=n || sum > target) {
            return 1e9;
        }

        if(sum == target) {
            return 0;
        }

        int nottake = solve(i+1,coins,target,sum);
        int take = 1e9;
        if(sum + coins[i] <= target) {
            take = 1 + solve(i,coins,target,sum + coins[i]);
        }
        return min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        int ans = solve(0,coins,amount,0);
        return ans >= 1e9 ? -1 : ans;
    }
};
