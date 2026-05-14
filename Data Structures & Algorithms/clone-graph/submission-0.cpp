/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* cloneGraph(Node* node) {

        if(!node) return nullptr;

        queue<Node*>q;

        unordered_map<Node*,Node*>mp;

        Node* clone = new Node(node->val);

        mp[node] = clone;

        q.push(node);

        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            for(auto x:top->neighbors) {
                if(mp.find(x) == mp.end()) {
                    mp[x] = new Node(x->val);
                    q.push(x);
                }
                mp[top]->neighbors.push_back(mp[x]);
            }
        }
        return clone;
    }
};
