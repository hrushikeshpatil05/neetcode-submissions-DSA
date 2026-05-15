class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        int totalCountofFreshOrages = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                if(grid[i][j] == 1) {
                    totalCountofFreshOrages++;
                }
            }
        }

        int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

        int totalTimeTaken = 0;

        while(!q.empty()) {
            int size = q.size();
            bool flag = false;

            for(int i=0;i<size;i++) {
                auto top = q.front();
                q.pop();

                for(int k=0;k<4;k++) {
                    int nr = dir[k][0] + top.first;
                    int nc = dir[k][1] + top.second;

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        totalCountofFreshOrages--;
                        flag = true;
                    }
                }
            }
            if(flag) totalTimeTaken++;
        }

        return totalCountofFreshOrages == 0 ? totalTimeTaken : -1;
    }
};
