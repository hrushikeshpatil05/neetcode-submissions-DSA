class Solution {
public:
    int n,m;
    bool solve(int i, unordered_map<string,int>& mp, string& s ,vector<int>& dp) {
        if (i == n) {
            return true;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        string temp = "";

        for(int j=i;j<n;j++) {
            temp += s[j];

            if(mp.find(temp) != mp.end()) {
                if(solve(j + 1,mp,s,dp)) {
                    dp[i] = 1;
                    return true;
                }
            }
        }

        return dp[i] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size(), m = wordDict.size();
        unordered_map<string,int>mp;

        for(auto x: wordDict) {
            mp[x]++;
        }

        vector<int>dp(n+1,-1);

        return solve(0,mp,s,dp);
    }
};
