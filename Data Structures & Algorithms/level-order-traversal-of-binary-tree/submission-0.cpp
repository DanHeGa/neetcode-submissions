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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res = {};
        
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int q_size = q.size();
            cout << "size " << q_size << endl;
            vector<int> intra_res;
            for (int i = 0; i < q_size; i++) {
                TreeNode* curr = q.front();
                intra_res.push_back(curr->val);
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                q.pop();
            }
            res.push_back(intra_res);
        } 

        return res;
    }
};
