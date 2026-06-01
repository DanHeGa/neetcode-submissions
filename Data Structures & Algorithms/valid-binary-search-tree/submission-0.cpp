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
    //Solution with left and right limits.
    /*
    We know in a BST, left values should be less than root->val and more than -infinity.
        -inf < node->val < parent->val;
    while right values should be more than the root->val and less than infinity
        parent->val < node->val < inf;
    */
    bool helper(TreeNode* root, int left, int right) {
        if (!root) return true;

        if (!(root->val > left && root->val < right)) {
            return false;
        }

        bool leftValid = helper(root->left, left, root->val);
        bool rightValid = helper(root->right, root->val, right);

        return leftValid && rightValid;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }
};
