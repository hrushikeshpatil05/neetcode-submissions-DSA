class Solution {
public:
    int n,m;
    int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
    bool solve(int i,int j,vector<vector<char>>& board, string& word, int curr) {
        
         if(curr == word.size()) {
            return true;
        }
        
        if(i>=n || i<0 || j>=m || j<0 || board[i][j] != word[curr]) {
            return false;
        }

        int temp = board[i][j];
        board[i][j] = '#';

        bool take = false;
        for(int k=0;k<4;k++) {
            int nr = i + dir[k][0];
            int nc = j + dir[k][1];
            take = take || solve(nr,nc,board,word,curr+1);
        }
        board[i][j] = temp;
        return take;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                    if(solve(i,j,board,word,0)) {
                        return true;
                    }
            }
        }
        return false;
    }
};
