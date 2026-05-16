class Solution {
public:
    int n,m;
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

    void dfs(int i,int j,vector<vector<char>>& board) {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != 'O') {
            return;
        }

        board[i][j] = '#';

        for(int k=0;k<4;k++) {
            int nr = i + dir[k][0];
            int nc = j + dir[k][1];
            dfs(nr,nc,board);
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();

        for(int i=0;i<n;i++) {
            if(board[i][0] == 'O') {
                // board[i][0] = '#';
                dfs(i,0,board);
            }
            if(board[i][m-1] == 'O') {
                // board[i][m-1] = '#';
                dfs(i,m-1,board);
            }
        }

        for(int i=0;i<m;i++) {
            if(board[0][i] == 'O') {
                // board[0][i] = '#';
                dfs(0,i,board);
            }
            if(board[n-1][i] == 'O') {
                // board[n-1][i] = '#';
                dfs(n-1,i,board);
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
