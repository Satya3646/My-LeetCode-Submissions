struct Node // Node for a DLL
{
    Node* next;
    int key;
    int val;
    Node* prev;
    Node(int k,int v)
    {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map <int, Node*> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = tail = nullptr;
    }

    void moveToHead(Node* node)
    {
        if(node == head) // Already head
            return;
        // Connce the prev and next of the node
        // {
            if(node->next)
                node->next->prev = node->prev;
            if(node->prev)
                node->prev->next = node->next;
        // }
        if(node == tail) // Node is tail so move tail back
            tail = node->prev;
        // Disconnect node from list
        node->prev = nullptr;
        // Attach head next to node
        node->next = head;
        // Back connection from head to node
        if(head)
            head->prev = node;
        // Update head
        head = node;
        // Update tail if node is the only node
        if(!tail)
            tail = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        Node* node = cache[key];
        moveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        Node* node;
        if(cache.find(key) != cache.end())
        {
            node = cache[key];
            node->val = value;
            moveToHead(node);
        }
        else
        {
            if(cache.size() == capacity) // Need to delete tail (LRU)
            {
                node = tail;
                // Move the tail back
                tail = tail->prev;
                // Isolate the tail
                if(tail)
                    tail->next = nullptr;
                // Update head if list becomes empty
                if(!tail)
                    head = nullptr;
                // Erase node from map
                cache.erase(node->key);
                // Free the memory taken by node
                delete node;
            }
            // Create new node
            node = new Node(key, value);
            // Insert into map for instant access
            cache[key] = node;
            moveToHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
