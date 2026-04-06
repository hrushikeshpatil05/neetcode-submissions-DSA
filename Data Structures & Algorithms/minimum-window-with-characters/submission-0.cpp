class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto x:t) {
            mp[x]++;
        }

        int required = mp.size();
        
        int n = s.size(), m = t.size();

        if(m>n) {
            return "";
        }

        unordered_map<char,int>curr;
        string ans = s;

        int i=0,j=0;
        int minLength = INT_MAX;
        int startIdx = 0;
        int formed = 0;
        while(j<n) {
            char c = s[j];
            curr[c]++;

            if(mp[c] > 0 && curr[c] == mp[c]) {
                formed++;
            }

            while(formed == required) {
                if(j - i + 1 < minLength) {
                    minLength = j - i + 1;
                    startIdx = i;
                }
                char leftChar = s[i];
                curr[leftChar]--;

                if(mp[leftChar] > 0 && curr[leftChar] < mp[leftChar]) {
                    formed--;
                }
                i++;
            }
            j++;
        }
        return minLength == INT_MAX ? "" : s.substr(startIdx,minLength);
    }
};
