/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (mp.count(head)) return mp[head]; //if found, return the copy node of it

        //if not found, create it in the map
        Node* copy = new Node(head->val); //next and random are null for this copy
        mp[head] = copy;
        //get or create ->next copy node
        copy->next = copyRandomList(head->next);
        copy->random = mp[head->random];
        return copy;
    }
};
