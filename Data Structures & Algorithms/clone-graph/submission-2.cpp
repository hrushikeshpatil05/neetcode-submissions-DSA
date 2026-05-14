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

    unordered_map<Node*,Node*>mp;

    Node* cloneGraph(Node* node) {
        if(!node) {
            return nullptr;
        }

        Node* clone = new Node(node->val);

        if(mp.find(node) != mp.end()) {
            return mp[node];
        }

        mp[node] = clone;

        for(auto x:node->neighbors) {
            clone->neighbors.push_back(cloneGraph(x));
        }

        return clone;
    }
};
