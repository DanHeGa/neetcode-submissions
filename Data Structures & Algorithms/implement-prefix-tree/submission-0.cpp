class TrieNode {
    private:
        char letter;
        bool isFinal;
        TrieNode* parent;
        TrieNode* children[26];
    public:
        TrieNode(TrieNode* parent, char c);
        TrieNode* getChild(char c); //get current node's children with that letter
        TrieNode* addChild(TrieNode* parent, char c); //add new child to current node}
        void setFinal(bool isFinal);
        bool getIsFinal();
};

TrieNode::TrieNode(TrieNode* parent, char c) {
    this->letter = c;
    this->parent = parent;
    isFinal = false;
    for (int i = 0; i < 26; i++) {
        children[i] = nullptr;
    }
}

TrieNode* TrieNode::getChild(char c) {
    return children[c - 'a'];
} 

TrieNode* TrieNode::addChild(TrieNode* parent, char c) {
    TrieNode* newChild = new TrieNode(parent, c);
    children[c - 'a'] = newChild;
    return children[c - 'a'];
}

void TrieNode::setFinal(bool isFinal) {
    this->isFinal = isFinal;
    cout << "isFinal was set to " << isFinal << endl;
}

bool TrieNode::getIsFinal() {
    return isFinal;
}


class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode(nullptr, '\0');
    }
    
    void insert(string word) {
        int n = word.length();
        TrieNode* curr = root; 
        for (int i = 0; i < n; i++) {
            char letter = word[i]; //get current parent
            TrieNode* child = curr->getChild(letter);
            if (child != nullptr) {
                curr = child; //child exists, :: just move pointer to keep moving forward
            } else {//not existing child, create it and keep moving
                curr->addChild(curr, letter);
                curr = curr->getChild(letter);
            }
        }
        curr->setFinal(true);
    }
    
    bool search(string word) {
        int n = word.length();
        TrieNode* curr = root;
        for (int i = 0; i < n; i++) {
            char letter = word[i];
            TrieNode* child = curr->getChild(letter);
            if (!child) {
                return false;
            }
            curr = child;
        }
        return curr->getIsFinal();
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (int i = 0; i < prefix.length(); i++) {
            char c = prefix[i];
            curr = curr->getChild(c);
            if (!curr) return false;
        }
        return true;
    }
};
