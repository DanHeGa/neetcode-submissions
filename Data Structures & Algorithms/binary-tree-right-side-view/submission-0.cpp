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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        res.push_back(q.front()->val);

        while (!q.empty()) {
            int len = q.size();
            //put the nodes from each level in the queue
            for (int i = 0; i < len; i++) {
                TreeNode* ele = q.front();
                if (ele != nullptr) {
                    q.push(ele->right);
                    q.push(ele->left);
                }
                q.pop();
            }
            //iterate over the nodes in that level to get the most visible one
            while(q.front() == nullptr) {
                q.pop();
            }

            if (!q.empty() && q.front() != nullptr) {
                res.push_back(q.front()->val);
            }
        }

        return res;
    }
};
