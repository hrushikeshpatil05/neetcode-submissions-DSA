class Solution {
public:
    int n,m;
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp) {
        if(i>=n || j>=m || i<0 || j<0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 1;

        for(int k=0;k<4;k++) {
            int nr = i + dir[k][0];
            int nc = j + dir[k][1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && matrix[nr][nc] > matrix[i][j]) {
                ans = max(ans,1 + solve(nr,nc,matrix,dp));
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();

        int ans = 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans = max(ans,solve(i,j,matrix,dp));
            }
        }
        return ans;
    }
};
