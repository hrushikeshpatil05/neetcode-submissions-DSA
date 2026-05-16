class Solution {
public:
    bool dfs(int i, vector<int> adj[],vector<int>& vis,vector<int>& order) {
        if(vis[i] == 1) {
            return true;
        }

        if(vis[i] == 2) {
            return false;
        }

        vis[i] = 1;

        for(auto x:adj[i]) {
            if(dfs(x,adj,vis,order)) {
                return true;
            }
        }

        vis[i] = 2;
        order.push_back(i);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];

        vector<int>order;
        vector<int>vis(numCourses,0);

        for(int i=0;i<prerequisites.size();i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<numCourses;i++) {
            if(dfs(i,adj,vis,order)) {
                return {};
            }
        }

        return order;
    }
};
