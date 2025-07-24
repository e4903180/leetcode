# include <iostream>
# include <stack>
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

// Solution1: recursive
// class Solution {
// public:
//     int inorder(TreeNode* root, int& count, int k) {
//         if (!root) return -1;
//         int left = inorder(root->left, count, k);
//         if (left!=-1) return left;
//         count++;

//         if (count==k) return root->val;
//         return inorder(root->right, count, k);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         int count = 0;
//         return inorder(root, count, k);
//     }
// };
// Solution2: Stack
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr||!st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            k--;
            if (k==0) return curr->val;
            curr = curr->right;
        } 
        return -1;
    }
};

int main() {
    /*
            5
           / \
          3   6
         / \
        2   4
       /
      1
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    int k = 3; // 找第3小的元素

    Solution sol;
    int result = sol.kthSmallest(root, k);

    cout << "The " << k << "th smallest element is: " << result << endl;

    // 記憶體釋放（示範，實務請用智能指標或手動刪除所有節點）
    return 0;
}