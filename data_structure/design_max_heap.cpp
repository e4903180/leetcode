#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class MaxHeap{
    private:
        vector<int> heap;
        void heapifyUp(int index){
            while (index>0){
                int parentIndex = (index-1)/2;
                if (heap[index]>heap[parentIndex]){
                    swap(heap[index], heap[parentIndex]);
                    index = parentIndex;
                }
                else{
                    break;
                }
            }
        }
        void heapifyDown(int index){
            int size = heap.size();
            while (index<size)
            {
                int left = index*2+1;
                int right = index*2+2;
                int largest = index;
                if (left<size && heap[left]>heap[largest]){
                    largest = left;
                }
                if (right<size && heap[right]>heap[largest]){
                    largest = right;
                }
                if (largest!=index){
                    swap(heap[largest], heap[index]);
                    index = largest;
                }
                else{
                    break;
                }
            }
            

        }
    public:
        void insert(int val){
            heap.push_back(val);
            heapifyUp((int)heap.size()-1);
        }
        int extractMax(){
            if (heap.empty()){
                cout<<"Heap is empty."<<endl;
                return -1;
            }
            int maxVal = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
            return maxVal;
        } 
        void printHeap(){
            cout<<"MaxHeap(array): ";
            for (int val: heap){
                cout<<val<<" ";
            }
            cout<<endl;
        }
        bool isEmpty() const {
            return heap.empty();
        }
};

int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(30);
    h.insert(20);
    h.insert(5);
    h.insert(40);

    h.printHeap();  // Max Heap: 40 30 20 5 10

    cout << "Extract max: " << h.extractMax() << endl; // 40
    h.printHeap();  // Max Heap: 30 10 20 5

    cout << "Extract max: " << h.extractMax() << endl; // 30
    h.printHeap();  // Max Heap: 20 10 5

    return 0;
}
