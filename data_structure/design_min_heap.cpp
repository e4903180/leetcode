#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest != index) {
                swap(heap[smallest], heap[index]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp((int)heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty." << endl;
            return -1;
        }
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }

    void printHeap() {
        cout << "MinHeap(array): ";
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }

    bool isEmpty() const {
        return heap.empty();
    }
};

int main() {
    MinHeap h;
    h.insert(10);
    h.insert(30);
    h.insert(20);
    h.insert(5);
    h.insert(40);

    h.printHeap();  // MinHeap(array): 5 10 20 30 40

    cout << "Extract min: " << h.extractMin() << endl; // 5
    h.printHeap();  // MinHeap(array): 10 30 20 40

    cout << "Extract min: " << h.extractMin() << endl; // 10
    h.printHeap();  // MinHeap(array): 20 30 40

    return 0;
}
