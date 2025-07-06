#include <iostream>
using namespace std;


struct Node{
    int val;
    Node* next;
};

int main(){
    Node* node1 = new Node{10, nullptr};
    Node* node2 = new Node{20, nullptr};
    Node* node3 = new Node{30, nullptr};

    node1->next = node2;
    node2->next = node3;

    Node* p = node1;
    cout<<"Head->";
    while(p!=nullptr){
        cout<<p->val<<"->";
        p = p->next;
    }
    cout<<"NULL"<<endl;
}
