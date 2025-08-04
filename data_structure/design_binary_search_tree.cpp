#include<iostream>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

TreeNode* insert(TreeNode* root, int val){
    if (root == nullptr) return new TreeNode(val);

    if (val<root->val){
        root->left = insert(root->left, val);
    } else if (val>root->val){
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(TreeNode* root){
    if (root==nullptr) return;
    inorder(root->left);
    cout<<root->val<<endl;
    inorder(root->right);
}

bool search(TreeNode* root, int val){
    if (root==nullptr) return false;
    if (root->val == val) return true;
    if (val<root->val) return search(root->left, val);
    else return search(root->right, val);
}

TreeNode* findMin(TreeNode* root){
    while(root && root->left!=nullptr){
        root = root->left;
    }
    return root;
}

TreeNode* remove(TreeNode* root, int val){
    if (root==nullptr) return root;

    if (val<root->val){
        root->left = remove(root->left, val);
    } else if (val>root->val){
        root->right = remove(root->right, val);
    } else {
        if (root->left == nullptr){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else{
            TreeNode* temp = findMin(root);
            root->val = temp->val;
            root->right = remove(root->right, temp->val);
        }
    }
    return root;
}

void freeTree(TreeNode* root){
    if (root==nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}


int main() {
    TreeNode* root = nullptr;

    // 插入節點
    //      8
    //    /   \
    //   3     10
    //  / \      \
    // 1   6      14
    //    / \    /
    //   4   7  13

    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    // 搜尋
    cout << "Search 6: " << (search(root, 6) ? "Found" : "Not Found") << endl;
    cout << "Search 9: " << (search(root, 9) ? "Found" : "Not Found") << endl;

    // 刪除節點
    root = remove(root, 10);
    cout << "Inorder after deleting 10: ";
    inorder(root);
    cout << endl;

    // 釋放記憶體
    freeTree(root);

    return 0;
}