using pii = pair<int,pair<int, int>>;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
        priority_queue<pii,vector<pii>,greater<pii>>pq;

        vector<vector<int>>vis(n,vector<int>(m,0));

        pq.push({grid[0][0],{0,0}});
        vis[0][0] = 1;

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int r = top.second.first;
            int c = top.second.second;
            int time = top.first;

            if(r == n-1 && c == m-1) {
                return time;
            }

            for(int i=0;i<4;i++) {
                int nr = dir[i][0] + r;
                int nc = dir[i][1] + c;

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    int nextTime = max(time,grid[nr][nc]);
                    pq.push({nextTime,{nr,nc}});
                }
            }
        }
        return 0;
    }
};
