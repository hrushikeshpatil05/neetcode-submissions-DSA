class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        int n = s.size();

        int maxLength = 1;
        int idx = 0;

        for(int i=0;i<n;i++) {
            int len1 = expandOnBothEnds(i,i,s);
            int len2 = expandOnBothEnds(i,i+1,s);

            int currMax = max(len1,len2);
            if(currMax > maxLength) {
                maxLength = currMax;
                idx = i - (currMax-1)/2;
            }
        }
        return s.substr(idx,maxLength);
    }

    int expandOnBothEnds(int left,int right,string& s) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right-left-1;
    }
};
