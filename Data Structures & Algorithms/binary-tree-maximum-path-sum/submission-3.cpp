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
    int helper(TreeNode* root, int& maxSum) {
        if (!root) return 0;

        int leftSum = helper(root->left, maxSum);
        int rightSum = helper(root->right, maxSum);

        int sum = max(leftSum, 0) + root->val + max(rightSum, 0);
        if (sum > maxSum) {
            maxSum = sum;
            cout << "left: " << leftSum << ", right: " << rightSum << ", root: " << root->val << endl;
            cout << "maxSum: " << maxSum << endl;
            cout << "----------------------------------" << endl;
        }

        return root->val + max(max(leftSum, rightSum), 0);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int sum = helper(root, maxSum);
        return maxSum;
    }
};
