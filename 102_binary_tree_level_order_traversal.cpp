#include<iostream>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i=0; i<levelSize; i++){
                TreeNode* Node = q.front();
                q.pop();
                currentLevel.push_back(Node->val);
                if (Node->left) q.push(Node->left);
                if (Node->right) q.push(Node->right);
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};


int main() {
    // Build a simple tree:
    //      1
    //     / \
    //    2   3
    //   /   / \
    //  4   5   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    Solution sol;
    vector<vector<int>> levels = sol.levelOrder(root);

    // Print the level order traversal
    for (int i = 0; i < (int)levels.size(); ++i) {
        cout << "Level " << i + 1 << ": ";
        for (int val : levels[i]) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up the allocated nodes
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}