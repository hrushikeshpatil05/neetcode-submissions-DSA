class Solution {
public:
    int dfs(int i,int j,string& s1,string& s2,int n,int m,vector<vector<int>>& dp) {
        if(i>=n || j>=m) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int a1 = dfs(i+1,j,s1,s2,n,m,dp);
        int b1 = 0;
        int c1 = dfs(i,j+1,s1,s2,n,m,dp);
        if(s1[i] == s2[j]) {
            b1 = 1 + dfs(i+1,j+1,s1,s2,n,m,dp);
        }
        return dp[i][j] = max({a1,b1,c1});
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return dfs(0,0,text1,text2,n,m,dp);
    }
};
