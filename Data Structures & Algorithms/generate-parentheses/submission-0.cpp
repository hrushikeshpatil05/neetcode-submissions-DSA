class Solution {
public:
    void solve(int n, int openPar, int closingPar, vector<string>& ans, string& s) {
        if(s.size() == 2*n) {
            ans.push_back(s);
            return;
        }

        if(closingPar > openPar || openPar > n) return;

        if(openPar < n) {
            s += '(';
            solve(n,openPar+1,closingPar,ans,s);
            s.pop_back();
        }

        if(closingPar < openPar) {
            s += ')';
            solve(n,openPar,closingPar+1,ans,s);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string>ans;
        int openPar = 0;
        solve(n,openPar,0,ans,s);
        return ans;
    }
};
