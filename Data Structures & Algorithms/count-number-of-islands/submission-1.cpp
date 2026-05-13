class Solution {
public:
    int n,m;
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    void solve(int i, int j, vector<vector<char>>& grid) {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';

        for(int k=0;k<4;k++) {
            int nr = i + dir[k][0];
            int nc = j + dir[k][1];

            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == '1') {
                solve(nr,nc,grid);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int numberOfIslands = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1') {
                    solve(i,j,grid);
                    numberOfIslands++;
                }
            }
        }

        return numberOfIslands;
    }
};
