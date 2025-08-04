#include <iostream>
using namespace std;

// Node structure: each node contains data and a pointer to the next node
struct Node {
    int data;     // stored data (integer)
    Node* next;   // pointer to the next node
    Node* prev;   // pointer to the previous node
};

// Linked list class
class DBLinkedList {
private:
    Node* head;   // pointer to the head of the list
    Node* tail;   // pointer to the tail of the list

public:
    // Constructor: initialize head as null pointer
    DBLinkedList() { head = nullptr; tail = nullptr; }

    // Append a new node at the end
    void append(int value) {
        // Create a new node with data = value, next = nullptr, prev = nullptr
        Node* newNode = new Node{value, nullptr, nullptr};

        // If the list is empty, point head and tail to the new node
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;      // Link the current tail's next to the new node
        newNode->prev = tail;      // Link the new node's previous to the current tail
        tail = newNode;            // Update the tail pointer to the new node
    }

    // Print the entire list content
    void print() {
        // Start from the head and output each node's data
        Node* temp = head;
        cout << "Head|";
        while (temp != nullptr) {
            cout << temp->data << "|";
            temp = temp->next;
        }
        // Print Tail at the end of the list
        cout << "Tail" << endl;
    }

    void revrsePrint() {
        // Start from the tail and output each node's data
        Node* temp = tail;
        cout << "Tail|";
        while (temp != nullptr) {
            cout << temp->data << "|";
            temp = temp->prev;
        }
        cout << "Head" << endl;
    }

    // Remove the node with data value equal to 'value'
    void remove(int value) {
        if (head == nullptr){
            return;
        }

        Node* curr = head;
        while (curr != nullptr && curr->data != value){
            curr = curr->next;
        }

        if (curr == nullptr){
            return;
        }

        if (curr == head && curr == tail){
            delete curr;
            head = tail = nullptr;
            return;
        } 
        if (curr == head){
            head = head->next;
            head->prev = nullptr;
            delete curr;
            return;
        }
        if (curr == tail){
            tail = tail->prev;
            tail->next = nullptr;
            delete curr;
            return;
        }
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        delete curr;
    }

    // Destructor: release all allocated memory in the list
    ~DBLinkedList() {
        Node* curr = head;
        // Keep track of the next node
        while (curr != nullptr) {
            // Save the next node
            Node* toDelete = curr;
            curr = curr->next;
            // Delete current node
            delete toDelete;
        }
    }
};

int main() {
    DBLinkedList list;

    // Append five nodes
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    // Print the list from head to tail
    cout << "List (forward): ";
    list.print();  // Expected: Head|10|20|30|40|50|NULL

    // Print the list in reverse (from tail to head)
    cout << "List (backward): ";
    list.revrsePrint();  // Expected: Tail|50|40|30|20|10|Head

    // Remove a middle node
    cout << "Remove 30" << endl;
    list.remove(30);
    list.print();  // Expected: Head|10|20|40|50|NULL

    // Remove head node
    cout << "Remove 10" << endl;
    list.remove(10);
    list.print();  // Expected: Head|20|40|50|NULL

    // Remove tail node
    cout << "Remove 50" << endl;
    list.remove(50);
    list.print();  // Expected: Head|20|40|NULL

    // Remove a value not in the list
    cout << "Remove 999 (not in list)" << endl;
    list.remove(999);
    list.print();  // Expected: Head|20|40|NULL (no change)

    // Remove remaining nodes
    cout << "Remove 20" << endl;
    list.remove(20);
    cout << "Remove 40" << endl;
    list.remove(40);
    list.print();  // Expected: Head|NULL (empty list)

    return 0;
}
