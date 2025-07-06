#include <iostream>
using namespace std;

class Stack {
private:
    int* data;
    int capacity;
    int size;

public:
    // 建構子：初始化容量與記憶體空間
    Stack(int capacity) {
        // TODO: 初始化 data, size, capacity
        this->capacity=capacity;
        this->size=0;
        data = new int[capacity];
    }

    // 解構子：釋放記憶體
    ~Stack() {
        // TODO: 刪除 data
        delete[] data;
    }

    // 推入元素
    void push(int val) {
        // TODO: 如果沒滿，把 val 放入 data 並更新 size
        if(size>=capacity){
            cout<<"Error stack is full."<<endl;
            return;
        }
        data[size++]=val;
    }

    // 彈出頂端元素
    void pop() {
        // TODO: 如果不是空的，把 size 減 1
        if(size==0){
            cout<<"Error stack is empty."<<endl;
            return;
        }
        size--;
    }

    // 查看頂端元素
    int top() {
        // TODO: 如果不是空的，回傳頂端元素
        if(size==0){
            cout<<"Error stack is empty."<<endl;
            return -1;
        }
        return data[size-1];
    }

    // 是否為空
    bool isEmpty() {
        // TODO: 回傳 size 是否為 0
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }

    // 堆疊大小
    int getSize() {
        // TODO: 回傳 size
        return size;
    }
};

// 測試
int main() {
    Stack s(10);

    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Stack size: " << s.getSize() << endl;    // 3
    cout << "Top of stack: " << s.top() << endl;      // 30

    s.pop();
    cout << "Top after pop: " << s.top() << endl;     // 20
    cout << "Is stack empty: " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
