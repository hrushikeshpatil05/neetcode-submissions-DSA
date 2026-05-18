class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];

        for(int i=0;i<times.size();i++) {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int>dist(n+1,1e8);

        dist[k] = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,k});

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int currDist = top.first;
            int node = top.second;

            if(currDist > dist[node]) continue;

            for(auto x:adj[node]) {
                int neighbor = x.first;
                int d = x.second;

                if(currDist + d < dist[neighbor]) {
                    dist[neighbor] = currDist + d;
                    pq.push({dist[neighbor],neighbor});
                }
            }
        }

        int maxTime = 0;

        for(int i=1;i<=n;i++) {
            if (dist[i] == 1e8) return -1;
            maxTime = max(maxTime,dist[i]);
        }
        return maxTime;
    }
};
