struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        
        // 建立假頭與假尾 (給隨便的值如 -1 即可，因為我們不會去讀取它們)
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        // 把頭跟尾互相連起來
        head->next = tail;
        tail->prev = head;
    }
    
    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNode(Node* node){
        // Node* prevNode = node->prev;
        // Node* nextNode = node->next;
        
        Node* headNext = head->next;
        
        node->prev = head;
        node->next = headNext;
        head->next = node;
        headNext->prev = node;
    }

    int get(int key) {
        if (cache.find(key)!=cache.end()){
            Node* node = cache[key];
            removeNode(node);
            addNode(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key)!=cache.end()){
            // key alreaady exist, update
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            addNode(node);
        }
        else{
            // new key, create the node
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);

            while(cache.size()>capacity){
                // oldest node
                Node* lruNode = tail->prev;
                cache.erase(lruNode->key);
                removeNode(lruNode);
                delete lruNode;
            }
        }
    }
};
