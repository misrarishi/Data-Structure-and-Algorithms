
class Node {
public:
    int key, val;
    Node* next;
    Node* prev;
    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};
class LRUCache {

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int limit;

public:
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
    }
    void delNode(Node* oldNode) {
        Node* oldNext = oldNode->next;
        Node* oldPrev = oldNode->prev;
        oldNext->prev = oldPrev;
        oldPrev->next = oldNext;
    }
    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        int ans = m[key]->val;
        Node* ansNode = m[key];
        m.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;
        return ans;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) // same key elements
        {
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }

        // capacity reached
        if (m.size() == limit) {
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */