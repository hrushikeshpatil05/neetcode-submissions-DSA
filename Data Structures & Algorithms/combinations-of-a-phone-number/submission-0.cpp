class Solution {
public:

    int n;

    void solve(int i, vector<string>& mapping, string& digits, string temp, vector<string>& ans) {
        if(i == n) {
            ans.push_back(temp);
            return;
        }

        string letters = mapping[digits[i] - '0'];

        for(char c:letters) {
            temp.push_back(c);
            solve(i+1,mapping,digits,temp,ans);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        n = digits.size();
        vector<string>mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        solve(0,mapping,digits,"",ans);
        return ans;
    }
};
