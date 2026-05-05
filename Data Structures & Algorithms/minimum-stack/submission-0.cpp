struct Node {
    int data;
    int min;
    Node* next;

    Node(int data) {
        this->data = data;
        this->min = data;
        this->next = nullptr;
    }

    Node(int data, int min){
        this->data = data;
        this->min = min;
        this->next = nullptr;
    }

    Node(int data, int min, Node* next) {
        this->data = data;
        this->min = min;
        this->next = next;
    }
};

class MinStack {
private: 
    Node* first;

public:
    MinStack() {
        first = nullptr;
    }

    bool empty(){
        if (first == nullptr){
            return true;
        }

        return false;
    }
    
    void push(int val) {
        Node *next = first;
        int minVal;
        int currMin = getMin();
        if (first == nullptr) {
            minVal = val;
        } else if (val < currMin) {
            minVal = val;
        } else {
            minVal = currMin;
        }

        if (first != nullptr) {
            Node* next = first;
            first = new Node(val, minVal, next);
        } else {
            first = new Node(val, minVal, nullptr);
        }
    }
    
    void pop() {
        Node* aux = first;
        first = aux->next;
        delete aux;
    }
    
    int top() {
        return first->data;
    }
    
    int getMin() {
        if (!empty()) {
            return first->min;
        }

        return 0;
    }
};
