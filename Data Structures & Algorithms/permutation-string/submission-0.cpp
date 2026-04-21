class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();

        if(size1>size2) {
            return false;
        }

        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(int i=0;i<size1;i++) {
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }

        for(int i=0;i<(size2-size1);i++) {
            if(freq1 == freq2) {
                return true;
            }

            freq2[s2[size1+i]-'a']++;
            freq2[s2[i]-'a']--;
        }

        return freq1 == freq2;
    }
};
