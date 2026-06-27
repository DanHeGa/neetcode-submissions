/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> copies;
        queue<Node*> q;

        q.push(node); //start with first node
        copies[node] = new Node(node->val);

        while(!q.empty()) {
            Node* ogNode = q.front();
            q.pop(); 

            for(Node* neigh : ogNode->neighbors) {
                if (copies.find(neigh) == copies.end()) { //if not visited yet
                    copies[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }
                copies[ogNode]->neighbors.push_back(copies[neigh]);
            }
        }

        return copies[node];
    }
};

/*
  0    1    2  indexes  
  1    2    3  node
[[2],[1,3],[2]] neighbors

set visited
map = {
    og_node: cp_node(val, neighbors)
}

insert into queue the first node

while(queue)
    if node not visited
        get node copy copy from og
        insert into map
        insert into visited

        for neighin neighbors of og
            create a new node from og neighbor
            add it into the vector of neighbors from the copy already visited node
            insert into queue

return map[og input node];

*/



