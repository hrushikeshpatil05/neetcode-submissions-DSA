class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>adj;
    vector<string>res;

    void dfs(string path) {
        while(!adj[path].empty()) {
            string next = adj[path].top();
            adj[path].pop();

            dfs(next);
        }
        res.push_back(path);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto x:tickets){
            adj[x[0]].push(x[1]);
        }

        dfs("JFK");

        reverse(res.begin(),res.end());

        return res;
    }
};
