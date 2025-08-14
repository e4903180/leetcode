# include <iostream>
# include <vector>
# include <unordered_map>
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
    unordered_map<int, int> inorder_map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorder_map.clear();
        for (int i=0; i<(int)inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        return builtTreeHelper(preorder, 0, (int)preorder.size()-1, inorder, 0, (int)inorder.size()-1);
    }

    TreeNode* builtTreeHelper(vector<int>& preorder, int preorderStart, int preorderEnd, 
        vector<int>& inorder, int inorderStart, int inorderEnd){
        if (preorderStart>preorderEnd || inorderStart>inorderEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preorderStart]);
        int mid = inorder_map[preorder[preorderStart]];
        int leftTreeSize = mid - inorderStart;
        root->left = builtTreeHelper(preorder, preorderStart+1, preorderStart+leftTreeSize, inorder, inorderStart, mid-1);
        root->right = builtTreeHelper(preorder, preorderStart+leftTreeSize+1, preorderEnd, inorder, mid+1, inorderEnd);
        return root;
    }
};

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Constructed tree inorder traversal: ";
    printInorder(root);
    cout << endl;

    return 0;
}