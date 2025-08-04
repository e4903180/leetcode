#include<iostream>
#include<vector>
#include<climits>
using namespace std;
const int EMPTY = INT_MAX;

class ArrayBinaryTree {
    private: 
        vector<int> tree;
        void ensureSize(int index){
            if (index >= (int)tree.size()){
                tree.resize(index+1, EMPTY);
            }
        }

    public: 
        ArrayBinaryTree(const vector<int> nodes): tree(nodes){};

        bool exist(int index){
            return index<(int)tree.size() && tree[index]!=EMPTY;
        }
        
        void addLeft(int parentIndex, int val){
            int leftIndex = parentIndex*2+1;
            ensureSize(leftIndex);
            tree[leftIndex] = val;
        }

        void addRight(int parentIndex, int val){
            int rightIndex = parentIndex*2+2;
            ensureSize(rightIndex);
            tree[rightIndex] = val;
        }

        void preorder(int index=0){
            if (!exist(index)) return;
            cout<<tree[index]<<" ";
            preorder(index*2+1);
            preorder(index*2+2);
        }

        void inorder(int index=0){
            if (!exist(index)) return;
            inorder(index*2+1);
            cout<<tree[index]<<" ";
            inorder(index*2+2);
        }

        void postorder(int index=0){
            if (!exist(index)) return;
            postorder(index*2+1);
            postorder(index*2+2);
            cout<<tree[index]<<" ";
        }

        void printArray(){
            cout<<"Tree(array): ";
            for (int val: tree){
                if (val!=EMPTY) cout<<val<<" ";
                else cout<<"NULL ";
            }
            cout<<endl;
        }
    };

int main(){
    ArrayBinaryTree tree({1});
    tree.addLeft(0, 2);
    tree.addRight(0, 3);
    tree.addLeft(1, 4);
    tree.addRight(1, 5);
    tree.addRight(2, 6);

    cout << "Preorder: ";
    tree.preorder();
    cout << endl;

    cout << "Inorder: ";
    tree.inorder();
    cout << endl;

    cout << "Postorder: ";
    tree.postorder();
    cout << endl;

    tree.printArray();

    return 0;
}