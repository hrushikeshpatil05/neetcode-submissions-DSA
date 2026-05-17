struct DSU {
    int component;

private:
    vector<int>parent;
    vector<int>size;

public:
    DSU(int n) {
        parent.resize(n+1,0);
        size.resize(n+1,0);
        component = n;

        for(int i=0;i<=n;i++) {
            parent[i] = i;
        }
    }

    int findParent(int root) {
        if(parent[root] == root) {
            return root;
        }
        return parent[root] = findParent(parent[root]);
    }

    void unionBySize(int u,int v) {
        int up_u = findParent(u);
        int up_v = findParent(v);

        if(up_u == up_v) {
            return;
        }

        if(size[up_u] >= size[up_v]) {
            size[up_u] += size[up_v];
            parent[up_v] = parent[up_u];
            component--;
        }

        else {
            size[up_v] += size[up_u];
            parent[up_u] = up_v;
            component--;
        }
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n-1) {
            return false;
        }

        DSU graph(n);

        for(int i=0;i<edges.size();i++) {
            graph.unionBySize(edges[i][0],edges[i][1]);
        }

        if(graph.component == 1) {
            return true;
        }

        return false;

    }
};
