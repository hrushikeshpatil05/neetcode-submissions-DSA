class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int n = wordList.size();

        unordered_map<string,int>mp;

        for(auto x:wordList) {
            mp[x] = 1;
        }
        
        if(mp.find(endWord) == mp.end()) {
            return 0;
        }

        queue<pair<string,int>>q;

        q.push({beginWord,1});

        while(!q.empty()) {
            auto [word,steps] = q.front();
            q.pop();

            if(endWord == word) {
                return steps;
            }

            for(int i=0;i<word.length();i++) {
                char originalChar = word[i];

                for(char c='a';c<='z';c++) {
                    word[i] = c;

                    if(mp.find(word) != mp.end()) {
                        mp.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = originalChar;
            }
        }
        return 0;
    }
};
