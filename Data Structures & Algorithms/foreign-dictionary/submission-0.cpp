class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        for (string word : words) {
            for (char c : word) {
                inDegree[c] = 0;
            }
        }

        for(int i=0;i<n-1;i++) {
            string a = words[i];
            string b = words[i+1];

            if (a.length() > b.length() && a.substr(0, b.length()) == b) {
                return "";
            }

            for (int j = 0; j < min(a.length(), b.length()); j++) {
                if (a[j] != b[j]) {
                    char u = a[j];
                    char v = b[j];
                    
                    if (adj[u].find(v) == adj[u].end()) {
                        adj[u].insert(v);
                        inDegree[v]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        string result = "";

        for (auto& pair : inDegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }

        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            
            result += curr;
            
            for (char neighbor : adj[curr]) {
                inDegree[neighbor]--;
                
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if (result.length() != inDegree.size()) {
            return "";
        }
        
        return result;
    }
};
