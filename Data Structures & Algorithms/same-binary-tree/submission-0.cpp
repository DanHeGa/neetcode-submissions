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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> quP;
        queue<TreeNode*> quQ;
        quP.push(p);
        quQ.push(q);

        while(!quP.empty() && !quQ.empty()){
            cout << "quP size-> " <<quP.size() << endl; //remember it is also counting null values from the leaves.
            int qSize = quP.size(); //size of that tree level
            for(int i = 0; i < qSize; i++) {
                TreeNode* node1 = quP.front();
                quP.pop();
                TreeNode* node2 = quQ.front();
                quQ.pop();

                if (!node1 && !node2) continue;
                if (!node1 || !node2 || node1->val != node2->val){
                    return false;
                }
                quP.push(node1->left);
                quP.push(node1->right);
                quQ.push(node2->left);
                quQ.push(node2->right);
            }
        }

        return true;
    }
};
