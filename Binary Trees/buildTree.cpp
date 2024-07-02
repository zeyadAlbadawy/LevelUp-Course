#include <iostream>
#include <queue>
using namespace std;

// Create The Binary Tree in PreOrder Traversal
class node {

    public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = NULL;
        right = nullptr;
    }
};

node* buildTree() {
    int data;
    cin >> data;
    if(data == -1) return NULL;
    node* newNode = new node(data);
    newNode->left = buildTree();
    newNode->right = buildTree();
    return newNode;
}

void levelOrderTraversal(node *root) {
    queue<node*> qu;
    qu.push(root);
    qu.push(NULL);
    node *tempNode = nullptr;
    while(!qu.empty()) {
        tempNode = qu.front();
        if(!qu.front()) {
            cout << endl;
            qu.pop();
            if(!qu.empty())
              qu.push(NULL);
        } else {
            qu.pop();
            cout << tempNode->data << " ";
            if(tempNode->left)
              qu.push(tempNode->left);
            if(tempNode->right)
              qu.push(tempNode->right); 
        }
    }
    return;
}


node *levelOrderBuild() {
    queue<node *> qu;
    int data;
    cin >> data;
    node *root = new node (data);
    node *currentNode = NULL;
    qu.push(root);
    while(qu.empty()) {
        currentNode = qu.front();
        int leftChild, RightChild;
        cin >> leftChild >> RightChild;
        if(leftChild != -1) {
            currentNode->left = new node(leftChild);
            qu.push(currentNode->left);
        }

        if(RightChild != -1) {
            currentNode->right = new node(RightChild);
            qu.push(currentNode->right);
        }
        qu.pop();
    }
    return root;
}


// Replace With Sum Problems ->> 
int replaceWithSum(node *root) {
    // Base Case 
    if(!root) 
      return 0;
    if(!root->left && !root->right) 
      return root->data;

    // Recursive Case
    int temp = root->data;
    int leftSum = replaceWithSum(root->left);
    int rightSum = replaceWithSum(root->right);
    root->data = leftSum + rightSum;
    return root->data + temp;
}



// Maximum Subset Tree Problems ->>
pair<int, int> maxSubsetTree(node *root) {
    pair<int, int> p, leftSubTree, rightSubTree;
    if(!root) {
        p.first = 0; // first ->> inc
        p.second = 0; // second -->> exec
        return p;
    }
    leftSubTree = maxSubsetTree(root->left);
    rightSubTree = maxSubsetTree(root->right);
    p.first = root->data + leftSubTree.second + rightSubTree.second;
    p.second = max(leftSubTree.first, leftSubTree.second ) + max(rightSubTree.first, leftSubTree.first);
    return p;
}



// Print Nodes At Distant k Problem


void printAtLevelK(node *root, int k) {
    if(!root)
      return;
    if(k == 0) {
        cout << root->data;
        return;
    }

    printAtLevelK(root->right, k-1);
    printAtLevelK(root->left, k-1);
    return;
}
int printNodesAtDistantK(node *root, node *target, int k) {
    // Base Case
    if(!root) 
       return -1;
    
    // If we reach target node
    if(root == target){
        printAtLevelK(target, k);
        return 0;
    }

    // We Aren't on the target Node, We need To check the left first
    int DL = printNodesAtDistantK(root->left, target, k);
    if(DL != -1) {
        // Print The Current Node We reach the root
        if(DL + 1 == k)
          cout << root->data << endl; 
        
        // Other We will make rec Call on the right Part
        else
        printAtLevelK(root->right, k - DL -2);
        return 1 + DL;
    }

        // We Aren't on the target Node, We need To check the Right then
        int DR = printNodesAtDistantK(root->right, target, k);
        if(DR != -1) {
            // We Reach The Root So we Will Print it
            if(DR + 1 == k)
              cout << root->data << endl;
            else {
                printAtLevelK(root->left, k-DR-2);
            }
            return DR + 1;
        }

}
 int main(){ 
    node *root = levelOrderBuild();
    levelOrderTraversal(root);
}