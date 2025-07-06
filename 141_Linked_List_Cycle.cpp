#include<iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Test case 1: No cycle
    ListNode* node1 = new ListNode(3);
    node1->next = new ListNode(2);
    node1->next->next = new ListNode(0);
    node1->next->next->next = new ListNode(-4);
    cout << "Test case 1 (No cycle): " << (sol.hasCycle(node1) ? "Cycle detected" : "No cycle") << endl;

    // Test case 2: Cycle, linked back to second node
    ListNode* node2 = new ListNode(1);
    node2->next = new ListNode(2);
    node2->next->next = new ListNode(3);
    node2->next->next->next = new ListNode(4);
    node2->next->next->next->next = node2->next; // Creates a cycle
    cout << "Test case 2 (Cycle): " << (sol.hasCycle(node2) ? "Cycle detected" : "No cycle") << endl;

    // Test case 3: Single node, no cycle
    ListNode* node3 = new ListNode(10);
    cout << "Test case 3 (Single node, no cycle): " << (sol.hasCycle(node3) ? "Cycle detected" : "No cycle") << endl;

    // Test case 4: Single node, cycle to itself
    ListNode* node4 = new ListNode(99);
    node4->next = node4; // Self-cycle
    cout << "Test case 4 (Single node, cycle): " << (sol.hasCycle(node4) ? "Cycle detected" : "No cycle") << endl;

    // Clean up memory (only delete nodes in acyclic lists, otherwise risk infinite loop)
    delete node1->next->next->next;
    delete node1->next->next;
    delete node1->next;
    delete node1;
    delete node3;
    // For node2 and node4, which have cycles, deleting nodes directly may cause crashes

    return 0;
}
