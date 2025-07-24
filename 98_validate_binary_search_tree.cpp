#include<iostream>
#include <climits>  // for LONG_MIN and LONG_MAX
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool compete(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return compete(root->left, minVal, root->val) &&
               compete(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return compete(root, LONG_MIN, LONG_MAX);
    }
};




int main() {
    // Construct the following BST:
    //        5
    //       / \
    //      3   7
    //     / \   \
    //    2   4   8

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    Solution sol;
    if (sol.isValidBST(root)) {
        cout << "This is a valid Binary Search Tree." << endl;
    } else {
        cout << "This is NOT a valid Binary Search Tree." << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}