class Solution {
public:
    int n;
    int solve(int i,int j, vector<int>& nums,vector<vector<int>>& dp) {
        if(i>j) return 0;

        int maxCoins = 0;

        if(dp[i][j] != -1 ) {
            return dp[i][j];
        }

        for(int k=i;k<=j;k++) {
            int leftCoins = solve(i,k-1,nums,dp);
            int rightCoins = solve(k+1,j,nums,dp);

            int kBurst = nums[i-1]*nums[j+1]*nums[k];
            int totalCoins = kBurst + leftCoins + rightCoins;

            maxCoins = max(maxCoins,totalCoins);
        }
        return dp[i][j] = maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n-2,nums,dp);
    }
};
