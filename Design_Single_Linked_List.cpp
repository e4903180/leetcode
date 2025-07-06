#include <iostream>
using namespace std;

// Node structure: each node contains data and a pointer to the next node
struct Node {
    int data;     // stored data (integer)
    Node* next;   // pointer to the next node
};

// Linked list class
class LinkedList {
private:
    Node* head;   // pointer to the head of the list

public:
    // Constructor: initialize head as null pointer
    LinkedList() { head = nullptr; }

    // Append a new node at the end
    void append(int value) {
        // Create a new node with data = value, next = nullptr
        Node* newNode = new Node{value, nullptr};

        // If the list is empty, point head to the new node
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Otherwise, traverse from head to the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Point the last node's next to the new node
        temp->next = newNode;
    }

    // Print the entire list content
    void print() {
        // Start from the head and output each node's data
        Node* temp = head;
        cout << "head|";
        while (temp != nullptr) {
            cout << temp->data << "|";
            temp = temp->next;
        }
        // Print NULL at the end of the list
        cout << "NULL" << endl;
    }

    // Remove the node with data value equal to 'value'
    void remove(int value) {
        // If the list is empty, do nothing
        if (head == nullptr) {
            return;
        }
        // If the first node contains the target value
        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        // Traverse the list to find the node before the one to delete
        Node* curr = head;
        while (curr->next != nullptr) {
            if (curr->next->data == value) {
                // Found the node to delete
                // Skip over the node to delete
                Node* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
                return;
            }
            else {
                curr = curr->next;
            }
        }
        // If not found (reached the end), do nothing
    }

    // Destructor: release all allocated memory in the list
    ~LinkedList() {
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

// Main function: test the LinkedList class
int main() {
    LinkedList list;
    // Append five nodes
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    // Print current list: 10 -> 20 -> 30 -> ...
    list.print();
    // Remove node with value 30
    list.remove(30);
    // Print list after removal: 10 -> 20 -> 40 -> 50 -> NULL
    list.print();
    return 0;
}
