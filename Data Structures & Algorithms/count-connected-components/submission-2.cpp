class DSU {

private:
    vector<int>size;
    vector<int>parent;

public:
    int components;

    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1,1);
        components = n;

        for(int i=0;i<=n;i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u,int v) {
        int up_u = findParent(u);
        int up_v = findParent(v);

        if(up_u == up_v) {
            return;
        }

        if(size[up_u] >= size[up_v]) {
            size[up_u] += size[up_v];
            parent[up_v] = up_u;
            components--;
        }

        else {
            size[up_v] += size[up_u];
            parent[up_u] = up_v;
            components--;
        }
    }

};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        DSU graph(n);

        for(int i=0;i<edges.size();i++) {
            graph.unionBySize(edges[i][0],edges[i][1]);
        }

        return graph.components;
    }
};
