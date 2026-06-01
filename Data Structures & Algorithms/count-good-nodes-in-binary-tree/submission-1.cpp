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
    int count = 0;
    int maxVal = INT_MIN;
    TreeNode* goodNodesHelper(TreeNode* root) {
        if(!root) return nullptr;

        int oldVal = maxVal;
        if (root->val >= maxVal) {
            count++;
            maxVal = root->val;
        }

        goodNodes(root->left);
        goodNodes(root->right);
        maxVal = oldVal;
        return root;
    }
    
    int goodNodes(TreeNode* root) {
        TreeNode* aux = goodNodesHelper(root);
        return count;
    }
};
