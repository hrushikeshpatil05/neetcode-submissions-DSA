class DSU {
    vector<int>parent;
    vector<int>size;

public:
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++) parent[i] = i;
    }

    int findParent(int node) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    bool unionBySize(int u,int v) {
        int up_u = findParent(u);
        int up_v = findParent(v);

        if(up_u == up_v) {
            return false;
        }

        if(size[up_u] >= size[up_v]) {
            size[up_u] += size[up_v];
            parent[up_v] = up_u;
        }

        else {
            size[up_v] += size[up_u];
            parent[up_u] = up_v;
        }
        return true;
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        DSU graph(n);

        vector<int>redundantConnection = {};

        for(int i=0;i<n;i++) {
            if(graph.unionBySize(edges[i][0],edges[i][1]) == false) {
                redundantConnection = {edges[i][0],edges[i][1]};
            }
        }

        return redundantConnection;
    }
};
