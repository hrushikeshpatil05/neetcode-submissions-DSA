class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1) return false;

        vector<int>adj[n];
        vector<int>vis(n,0);

        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int>q;

        q.push(0);
        vis[0] = 1;
        int completedNode = 0;

        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            completedNode++;

            for(auto x:adj[top]) {
                if(!vis[x]) {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }

        return completedNode == n;
    }
};
