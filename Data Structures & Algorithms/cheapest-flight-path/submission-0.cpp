using pii = pair<int,pair<int,int>>;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];

        for(auto x:flights) {
            adj[x[0]].push_back({x[1],x[2]});
        }

        queue<pii>pq;
        vector<int>dist(n,1e8);
        pq.push({0,{src,0}});
        dist[src] = 0;

        while(!pq.empty()) {
            auto top = pq.front();
            pq.pop();

            int weight = top.first;
            int node = top.second.first;
            int stops = top.second.second;

            if(stops > k) continue;

            for(auto x:adj[node]) {
                int nextNode = x.first;
                int nextWeight = x.second;

                if(weight + nextWeight <= dist[nextNode]) {
                    dist[nextNode] = weight + nextWeight;
                    pq.push({dist[nextNode],{nextNode,stops+1}});
                }
             }
        }

        return dist[dst] == 1e8 ? -1 : dist[dst];
    }
};
