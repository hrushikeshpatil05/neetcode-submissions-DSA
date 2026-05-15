class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

        int currDist = 0;

        while(!q.empty()) {
            int size = q.size();
            currDist++;
            for(int i=0;i<size;i++) {
                auto top = q.front();
                q.pop();
                for(int k=0;k<4;k++) {
                    int nr = top.first + dir[k][0];
                    int nc = top.second + dir[k][1];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 2147483647) {
                        grid[nr][nc] = min(grid[nr][nc],currDist);
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
};
