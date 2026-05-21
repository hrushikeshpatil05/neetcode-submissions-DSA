class Solution {
public:
    int countPalindrome(string& s,int left,int right) {
        int ct = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
            ct++;
        }
        return ct;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for(int i=0;i<n;i++) {
            int ct1 = countPalindrome(s,i,i);
            int ct2 = countPalindrome(s,i,i+1);
            ans += ct1 + ct2;
        }
        return ans;
    }
};
