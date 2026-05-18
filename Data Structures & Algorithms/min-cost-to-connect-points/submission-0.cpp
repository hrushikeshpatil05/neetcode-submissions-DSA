class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int>vis(n,0);

        int totalCost = 0;
        int visitedNodes = 0;
        pq.push({0,0});

        while(visitedNodes<n) {
            auto [dist,node] = pq.top();
            pq.pop();

            if(vis[node]) {
                continue;
            }

            vis[node] = 1;
            totalCost += dist;
            visitedNodes++;

            for(int i=0;i<n;i++) {
                if(!vis[i]) {
                    int currDist = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1]);
                    pq.push({currDist,i});
                }
            }
        }
        return totalCost;
    }
};
