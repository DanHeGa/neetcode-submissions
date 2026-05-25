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
    bool isIdentical(TreeNode* root, TreeNode* sub) {
        if (!root  || !sub) return root == sub; 

        return root->val == sub->val &&
            isIdentical(root->left, sub->left) &&
            isIdentical(root->right, sub->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;//empty root cannot contain non-empty subtree

        if (isIdentical(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) ||
            isSubtree(root->right, subRoot);
    }
};
