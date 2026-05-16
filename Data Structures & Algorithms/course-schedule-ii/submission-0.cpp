class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>inDegree(numCourses,0);

        for(int i=0;i<prerequisites.size();i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            inDegree[prerequisites[i][1]]++;
        }

        queue<int>q;

        for(int i=0;i<numCourses;i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int>ans;

        int completedCourses = 0;

        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            ans.push_back(top);

            for(auto x:adj[top]) {
                inDegree[x]--;

                if(inDegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        if(ans.size() == numCourses) {
            reverse(ans.begin(),ans.end());
            return ans;
        }
        return {};
    }
};
