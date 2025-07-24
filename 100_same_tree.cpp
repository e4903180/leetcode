#include<iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val!=q->val) return false;

        return(isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

int main() {
    /*
        Tree 1:
               1
              / \
             2   3
            /
           1
    */
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->left = new TreeNode(1);

    /*
        Tree 2:
               1
              / \
             2   3
            /
           1
    */
    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(3);
    t2->left->left = new TreeNode(1);
    
    Solution sol;
    if (sol.isSameTree(t1, t2)) {
        cout << "The same." << endl;
    } else {
        cout << "Not the same." << endl;
    }

    return 0;
}