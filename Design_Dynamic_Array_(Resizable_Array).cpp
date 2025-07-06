#include<iostream>
using namespace std;

class DynamicArray {

private:
    int* data;
    int size;
    int capacity;

public:

    DynamicArray(int capacity) {
        this->capacity=capacity;
        this->size=0;
        data = new int[capacity];
    }

    ~DynamicArray(){
        delete[] data;
    }

    int get(int i) {
        return data[i];
    }

    void set(int i, int n) {
        data[i] = n;
    }

    void pushback(int n) {
        if(size==capacity){
            resize();
        }
        data[size++] = n;
    }

    int popback() {
        return data[--size];
    }

    void resize() {
        capacity*=2;
        int* new_data = new int[capacity];
        for(int i=0;i<size;i++){
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};

// Main test function
int main() {
    cout << "=== Testing DynamicArray ===" << endl;

    DynamicArray arr(2);
    cout << "Initial size: " << arr.getSize() << ", capacity: " << arr.getCapacity() << endl;

    arr.pushback(10);
    arr.pushback(20);
    cout << "After pushing 2 elements -> size: " << arr.getSize() << ", capacity: " << arr.getCapacity() << endl;

    arr.pushback(30);  // should trigger resize
    cout << "After pushing 3rd element (resize) -> size: " << arr.getSize() << ", capacity: " << arr.getCapacity() << endl;

    cout << "Element at index 0: " << arr.get(0) << endl;
    cout << "Element at index 1: " << arr.get(1) << endl;
    cout << "Element at index 2: " << arr.get(2) << endl;

    arr.set(1, 99);
    cout << "After setting index 1 to 99: " << arr.get(1) << endl;

    int last = arr.popback();
    cout << "Popped last element: " << last << ", new size: " << arr.getSize() << endl;

    return 0;
}