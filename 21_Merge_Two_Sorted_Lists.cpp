/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include<iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode ans;
//         ListNode* tail = &ans;
//         while (list1 && list2){
//             if (list1->val<list2->val){
//                 tail->next = new ListNode(list1->val);
//                 list1 = list1->next;
//             }
//             else{
//                 tail->next = new ListNode(list2->val);
//                 list2 = list2->next;
//             }
//             tail = tail->next;
//         }
//         if (list1){
//             tail->next = list1;
//         }
//         else{
//             tail->next = list2;
//         }
//         return ans.next;
//     }
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode ans;
        ListNode* tail = &ans;
        while (list1 && list2){
            if (list1->val<list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1){
            tail->next = list1;
        }
        else{
            tail->next = list2;
        }
        return ans.next;
    }
};

// 印出整條 linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// 建立一條 linked list，給定一個整數陣列
ListNode* createList(const initializer_list<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

int main() {
    // 建立兩條排序好的 linked list
    ListNode* list1 = createList({1, 4, 5});
    ListNode* list2 = createList({2, 4, 6});

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // 合併兩條 linked list
    Solution sol;  // 建立 Solution 類別物件
    ListNode* merged = sol.mergeTwoLists(list1, list2);  // 正確呼叫方法

    cout << "Merged List: ";
    printList(merged);

    return 0;
}