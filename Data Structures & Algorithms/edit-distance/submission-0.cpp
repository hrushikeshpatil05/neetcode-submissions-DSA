class Solution {
public:
    int n,m;
    int solve(int i,int j,string& word1,string& word2,vector<vector<int>>& dp) {
        if(j==m) {
            return n-i;
        }

        if(i>=n) {
            return m-j;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int res = 1e8;
        
        if(word1[i] == word2[j]) {
            res = solve(i+1,j+1,word1,word2,dp);
        }
        else {
            int insertChar = 1 + solve(i,j+1,word1,word2,dp);
            int deleteChar = 1 + solve(i+1,j,word1,word2,dp);
            int replaceChar = 1 + solve(i+1,j+1,word1,word2,dp);
            res = min({res,insertChar,deleteChar,replaceChar});
        }
        return dp[i][j] = res;
    }
    int minDistance(string word1, string word2) {
        n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,word1,word2,dp);
    }
};
