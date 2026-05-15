class Solution {
public:

    int n,m;
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    bool dfs(int i,int j,vector<vector<int>>& heights,vector<vector<int>>& vis) {
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]) {
            return false;
        }

        vis[i][j] = 1;

        for(int k=0;k<4;k++) {
            int nr = dir[k][0] + i;
            int nc = dir[k][1] + j;

            if(nr>=0 && nc>=0 && nr<n && nc<m && heights[nr][nc]>=heights[i][j] && !vis[nr][nc]) {
                dfs(nr,nc,heights,vis);
            }
        }
        return true;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));

        for(int i=0;i<n;i++) {
            dfs(i,0,heights,pacific);
            dfs(i,m-1,heights,atlantic);
        }

        for(int i=0;i<m;i++) {
            dfs(0,i,heights,pacific);
            dfs(n-1,i,heights,atlantic);
        }

        vector<vector<int>>ans;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
