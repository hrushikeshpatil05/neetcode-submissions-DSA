class Solution {
public:

    void solve(int row,int n, vector<vector<string>>& ans, vector<string>& board, vector<bool>& diag1,vector<bool>& diag2, vector<bool>& cols) {
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {
            if(!cols[col] && !diag1[row-col+n] && !diag2[row+col]) {
                board[row][col] = 'Q';
                cols[col] = true;
                diag1[row-col+n] = true;
                diag2[row+col] = true;
                solve(row+1,n,ans,board,diag1,diag2,cols);
                board[row][col] = '.';
                cols[col] = false;
                diag1[row-col+n] = false;
                diag2[row+col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n,'.'));
        vector<bool>cols(n);
        vector<bool>diag1(2*n,false);
        vector<bool>diag2(2*n,false);

        solve(0,n,ans,board,diag1,diag2,cols);
        return ans;
    }
};
