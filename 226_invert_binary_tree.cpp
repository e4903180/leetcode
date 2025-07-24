# include <iostream>
# include <queue>
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
        TreeNode* invertTree(TreeNode* root) {
            if (!root) return root;
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
            return root;
        }
    };


void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front(); q.pop();
        cout << cur->val << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    cout << endl;
}

int main() {
    //             4
    //           /   \
    //          2     7
    //         / \     \
    //        1   3     9
    //       /         /
    //      5         6
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(6);

    Solution s;
    cout << "Original Tree (Level Order): ";
    printLevelOrder(root);

    root = s.invertTree(root);

    cout << "Inverted Tree (Level Order): ";
    printLevelOrder(root);
}