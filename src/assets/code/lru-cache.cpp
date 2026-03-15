class LRUCache {
private:
    int capacity;
    DLL list;
    unordered_map<int, Node*> mp;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int k) {
        if(!mp.count(k)) return -1;
        Node* node = mp[k];
        list.remove(node);
        list.insertFront(node);
        return node->val;
    }
    
    void put(int k, int v) {
        if(!capacity) return;
        
        if(mp.count(k)) {
            Node* node = mp[k];
            node->val = v;
            list.remove(node);
            list.insertFront(node);
        } else {
            if(mp.size() == capacity) {
                Node* node = list.get_last();
                mp.erase(node->key);
                list.remove(node);
                delete node;
            }

            Node* node = new Node(k, v);
            list.insertFront(node);
            mp[k] = node;
        }
    }
};

// PUT() -> O(1)
// GET() -> O(1)