class Solution {
public:
    int x,y,z;
    bool solve(int i,int j,string& s1,string& s2,string& s3,vector<vector<int>>& dp) {
        if(i>=x && j>=y) {
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        bool leftPath = false, rightPath = false;
        if(s1[i] == s3[i+j]) {
            leftPath = solve(i+1,j,s1,s2,s3,dp);
        }
        if(s2[j] == s3[i+j]) {
            rightPath = solve(i,j+1,s1,s2,s3,dp);
        }
        return dp[i][j] = leftPath | rightPath;
    }
    bool isInterleave(string s1, string s2, string s3) {
        x = s1.size(), y = s2.size(), z = s3.size();
        if(x + y != z) {
            return false;
        }
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        return solve(0,0,s1,s2,s3,dp);
    }
};
