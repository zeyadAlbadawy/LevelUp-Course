

class Solution {
public:

    pair<int, int> treeDiameterCalc(TreeNode *root) {
        pair<int, int> p, leftTree, rightTree;
        if(!root) {
            p.first = 0; // First -->> height
            p.second = 0; // Second -->> Diameter
            return p;
        }
         
        leftTree = treeDiameterCalc(root->left);
        rightTree = treeDiameterCalc(root->right);
        p.first = max(leftTree.first, rightTree.first) + 1;
        int D1 =  leftTree.first + rightTree.first; // Diameter Passing Throught The Root = (LeftHeight + 1) + (right Height + 1) - 2 For Edges 
        int D2 =  leftTree.second; // LeftTree Diameter
        int D3 = rightTree.second; // RightTree Diameter
        p.second = max(D1, max(D2, D3));
        return p;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return treeDiameterCalc(root).second;
    }
};

