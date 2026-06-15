class TrieNode {
    private:
        char letter;
        TrieNode* parent;
        bool isEnd;
        array<TrieNode*, 26> children;

    public:
        TrieNode(char letter, TrieNode* parent) {
            this->letter = letter;
            this->parent = parent;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            this->isEnd = false;
        } 

        void addChild(TrieNode* newChild) {
            children[newChild->letter - 'a'] = newChild;
            cout << "Added new child" << newChild->letter << " with parent: " << letter << endl;
        }

        TrieNode* getChild(char ele) {
            return children[ele - 'a'];
        }

        void setIsEnd(bool newIsEnd) {
            this->isEnd = newIsEnd;
            cout << "set isEnd to -> " << isEnd << endl;
        }
        bool getIsEnd() {
            return this->isEnd;
        }

        array<TrieNode*, 26> getChildren() {
            return children;
        }
};

class WordDictionary {
private:
    TrieNode* root;
    bool dfsSearch(int i, string word, TrieNode* curr) {
        if (i >= word.length()) {
            return curr->getIsEnd();
        }

        if (word[i] != '.') {
            TrieNode* child = curr->getChild(word[i]);
            if (child && dfsSearch(i + 1, word, child)) {
                return true;
            }
        } else {
            array<TrieNode*, 26> currChildren = curr->getChildren();
            for (TrieNode* currChild : currChildren) {
                if (currChild && dfsSearch(i + 1, word, currChild)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode('\0', nullptr);
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            TrieNode* child = curr->getChild(word[i]);
            if (!child) {
                //if not exists, create it and move curr pointer
                TrieNode* newChild = new TrieNode(word[i], curr);
                curr->addChild(newChild);
                curr = newChild;
            } else {
                //it DOES exists, so u nly move the pointer
                curr = child;
            }
            cout << word[i];
        }
        curr->setIsEnd(true);
        cout << " Added" << endl;
    }
    
    bool search(string word) {
        return dfsSearch(0, word, root);
    }
};
