class Solution {
public:
    
    bool dfs(int i,vector<int> adj[],vector<int>& vis) {
        
        if(vis[i] == 1) {
            return true;
        }

        if(vis[i] == 2) {
            return false;
        }

        vis[i] = 1;

        for(auto x:adj[i]) {
            if(dfs(x,adj,vis)) {
                return true;
            }
        }

        vis[i] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int>adj[numCourses];

        int n = prerequisites.size();
        for(int i=0;i<n;i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int>vis(numCourses,0);

        for(int i=0;i<numCourses;i++) {
            if(dfs(i,adj,vis) == true) {
                return false;
            }
        }
        return true;
    }
};
