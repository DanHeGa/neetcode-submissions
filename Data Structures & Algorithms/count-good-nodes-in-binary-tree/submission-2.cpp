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
    int maxVal = INT_MIN;

    int goodNodesHelper(TreeNode* root, int maxSoFar) {
        if (!root) return 0;
        
        int res = 0;
        if (root->val >= maxSoFar){
            maxSoFar = root->val;
            res = 1;
        }

        int leftGoods = goodNodesHelper(root->left, maxSoFar);
        int rightGoods = goodNodesHelper(root->right, maxSoFar);

        return res + leftGoods + rightGoods;
    }
    int goodNodes(TreeNode* root) {
       return goodNodesHelper(root, INT_MIN);
    }
};
