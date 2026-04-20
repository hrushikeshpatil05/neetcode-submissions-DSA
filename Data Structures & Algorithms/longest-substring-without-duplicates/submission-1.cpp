class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0,j=0;
        int ans = 0;
        unordered_map<char,int>freq;
        while(j<n) {
            freq[s[j]]++;

            while(freq[s[j]] > 1) {
                freq[s[i++]]--;
            }

            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
