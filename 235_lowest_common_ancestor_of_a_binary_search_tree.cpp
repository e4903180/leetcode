# include <iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val>p->val && root->val>q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (root->val<p->val && root->val<q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else return root;
    }
};


int main() {
    /*
            15
           /  \
         10    20
        / \    / \
       8  12  17  25
      / \    / \    \
     6  9  16  18    30
    */

    TreeNode* root = new TreeNode(15);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(12);
    root->left->left->left = new TreeNode(6);
    root->left->left->right = new TreeNode(9);

    root->right->left = new TreeNode(17);
    root->right->right = new TreeNode(25);
    root->right->left->left = new TreeNode(16);
    root->right->left->right = new TreeNode(18);
    root->right->right->right = new TreeNode(30);

    TreeNode* p = root->right->left->left;  // 節點 16
    TreeNode* q = root->right->right->right; // 節點 30

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca) {
        cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    return 0;
}