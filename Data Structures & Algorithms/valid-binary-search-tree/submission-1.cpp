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
//complexity time O()
    bool inOrderHelper(TreeNode* root, int &prev) {
        if (!root) return true;
        //left subtree
        if (!inOrderHelper(root->left, prev)){
            return false;
        }

        //root
        if (prev >= root->val){ //because the prev node val cannot be more than the current one
            return false;
        }
        prev = root->val;

        //right subtree
        return inOrderHelper(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        int minVal = INT_MIN;
        return inOrderHelper(root, minVal);
    }
};
