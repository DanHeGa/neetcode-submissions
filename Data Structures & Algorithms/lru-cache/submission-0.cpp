struct Node {
    int key;
    int data;
    Node* next;
    Node* prev;

    Node(int key, int data){
        this->key = key;
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    };
};

class LRUCache {
private:
        unordered_map<int, Node*> mp;
        Node* head;
        Node* tail;
        int capacity;
public:
    LRUCache(int capacity) {
        mp.clear();
        head = nullptr;
        tail = head;
        this->capacity = capacity;
    }

    void remove_node(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        if (node == tail) {
            tail = node->prev;
        }
        
        if (node == head) {
            head = node->next;
        }

        if (prev != nullptr) {
            prev->next = next;
        }

        if (next != nullptr) {
            next->prev = prev;
        }

        //clean node pointers to avoid problem in insert
        node->next = nullptr;
        node->prev = nullptr;
    }

    void insert_node(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = head; //pointer to LRU cache element
        } else {
            Node* aux = head;
            head = node;
            head->next = aux;
            aux->prev = head;
        }
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()){
            Node* node = mp[key];
            remove_node(node);
            insert_node(node);
            return node->data;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) { //if it exists
            Node* node = mp[key];
            remove_node(node); 
            node->data = value; //update node value;
            insert_node(node); //put it in the head as the most recently used node
        } else { 
            Node* node = new Node(key, value);
            mp[key] = node;
            insert_node(node);

            //check if map size is less than capacity
            if (mp.size() > capacity) {
                //if yes, remove LRU element == tail
                Node* tmp_tail = tail;
                remove_node(tmp_tail);
                mp.erase(tmp_tail->key);
                delete tmp_tail;
            }
        }
    }
};
