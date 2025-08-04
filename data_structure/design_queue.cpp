#include <iostream>
using namespace std;

class Queue {
private:
    int* data;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int capacity) {
        // TODO: 初始化 data、front、rear、size、capacity
        this->capacity=capacity;
        front = 0;
        rear = 0;
        size = 0;
        data = new int[capacity];
    }

    ~Queue() {
        // TODO: 釋放 data 記憶體
        delete[] data;
    }

    void enqueue(int val) {
        // TODO: 將元素加入佇列尾端
        if(size==capacity){
            cout<<"Error Queue is full."<<endl;
            return;
        }
        data[rear] = val;
        rear = (rear+1)%capacity;
        size++;
    }

    void dequeue() {
        // TODO: 移除佇列前端元素
        if(isEmpty()){
            cout<<"Error Queue is empty."<<endl;
            return;
        }
        front = (front+1)%capacity;
        size--;
    }

    int peek() {
        // TODO: 回傳佇列前端的元素
        if(isEmpty()){
            cout<<"Error"<<endl;
            return -1;
        }
        return data[front];
    }

    bool isEmpty() {
        // TODO: 回傳佇列是否為空
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }

    int getSize() {
        // TODO: 回傳佇列大小
        return size;
    }
};

int main() {
    Queue q(5);  // Create a queue with capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;  // Output: 10
    q.dequeue();

    cout << "New front: " << q.peek() << endl;      // Output: 20
    cout << "Queue size: " << q.getSize() << endl;      // Output: 2

    return 0;
}

