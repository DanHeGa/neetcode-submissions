/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string res;
        queue<TreeNode*> q;
        q.push(root);
        cout << "initial value: " << res << endl;
        cout << "----------------" << endl;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (!curr) {
                res += "N ";
            } else {
                res += to_string(curr->val) + " ";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        istringstream ss(data);
        string val;
        ss >> val;

        queue<TreeNode*> q; 
        TreeNode* first = new TreeNode(stoi(val));
        q.push(first);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!(ss >> val)) break; //move sstream pointer
            if (val != "N") {
                TreeNode* aux = new TreeNode(stoi(val));
                curr->left = aux;
                q.push(aux);
            }
            
            if (!(ss >> val)) break;
            if (val != "N") {
                TreeNode* aux2 = new TreeNode(stoi(val));
                curr->right = aux2;
                q.push(aux2);
            }
        }

        return first;
    }
};
