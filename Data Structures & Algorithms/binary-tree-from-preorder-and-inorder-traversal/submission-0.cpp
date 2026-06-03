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
    int getEleIdx(vector<int>& inorder, int ele, int left, int right) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == ele) {
                return i;
            }
        }

        return -1;
    }

    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder, 
    int& pre_idx, int left, int right) {
        cout << "----------------------------------" << endl;
        cout << "left: " << left << ", right: " << right << endl;
        if (left > right) {
            return nullptr;
        }

        int root_val = preorder[pre_idx];
        cout << "Root value: " << root_val << " with preidx = " << pre_idx << endl;
        TreeNode* root = new TreeNode(root_val);
        pre_idx++;

        int in_idx = getEleIdx(inorder, root_val, left, right);
        cout << "Inorder idx = " << in_idx << endl;

        root->left = buildHelper(preorder, inorder, pre_idx, left, in_idx - 1);
        root->right = buildHelper(preorder, inorder, pre_idx, in_idx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int pre_index = 0;
        TreeNode* root = buildHelper(preorder, inorder, pre_index, 0, n - 1);
        return root;
    }
};
