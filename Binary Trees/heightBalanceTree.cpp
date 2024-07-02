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
    int heightCalc(TreeNode *root) {
        if(!root)
           return 0;
        int leftHeight = heightCalc(root->left);
        int rightHeight = heightCalc(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int leftHeight = heightCalc(root->left);
        int rightHeight = heightCalc(root->right);
        if(abs(leftHeight - rightHeight) > 1) 
          return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};