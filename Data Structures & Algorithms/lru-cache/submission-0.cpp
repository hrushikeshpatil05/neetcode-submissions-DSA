struct Node {
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {

    void addNode(Node* root) {
        Node* temp = head->next;
        root->next = temp;
        root->prev = head;
        head->next = root;
        temp->prev = root;
    }

    void deleteNode(Node* root) {
        Node* nextNode = root->next;
        Node* prevNode = root->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }

public:

    unordered_map<int,Node*>mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int size;
    
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* currNode = mp[key];
            int val = currNode->val;
            mp.erase(key);
            deleteNode(currNode);
            addNode(currNode);
            mp[key] = head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* currNode = mp[key];
            mp.erase(key);
            deleteNode(currNode);
        }
        if(mp.size() == size) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key] = head->next;
    }
};
