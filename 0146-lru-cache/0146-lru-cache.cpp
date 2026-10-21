
class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int cap) {
        capacity = cap;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        removeNode(node);
        insertFront(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;
            removeNode(node);
            insertFront(node);

            return;
        }

        if (mp.size() == capacity) {
            Node* lru = tail->prev;

            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* newNode = new Node(key, value);

        insertFront(newNode);
        mp[key] = newNode;
    }

    ~LRUCache() {
        Node* curr = head;

        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */
