# include <iostream>
# include <vector>
# include <queue>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 用 pair<int, ListNode*>
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if (lists.empty()) return nullptr;
//         ListNode res(0);
//         ListNode* tail = &res;

//         priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> min_heap;
//         for (auto node: lists){
//             if (node) min_heap.push({node->val, node});
//         }

//         while (!min_heap.empty()){
//             ListNode* node = min_heap.top().second;
//             tail->next = node;
//             tail = tail->next;
//             min_heap.pop();

//             if (node->next){
//                 min_heap.push({node->next->val, node->next});
//             }
//         }
//         tail->next = nullptr;
//         return res.next;
//     }
// };
// Time: O(nlogk), Space: O(k)


// 直接比較 ListNode*
struct cmp {
    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val > b->val; // 小的優先（小頂堆）
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode res(0);
        ListNode* tail = &res;

        priority_queue<ListNode*, vector<ListNode*>, cmp> min_heap;
        for (auto node: lists){
            if (node) min_heap.push(node);
        }

        while (!min_heap.empty()){
            ListNode* node = min_heap.top();
            min_heap.pop();
            
            tail->next = node;
            tail = tail->next;

            if (node->next){
                min_heap.push(node->next);
            }
        }
        tail->next = nullptr;
        return res.next;
    }
};
// Time: O(nlogk), Space: O(k)

int main() {
    ListNode* a = new ListNode(3, nullptr);
    a->next = new ListNode(5, nullptr);
    ListNode* b = new ListNode(2, nullptr);
    b->next = new ListNode(6, nullptr);
    ListNode* c = new ListNode(1, nullptr);
    c->next = new ListNode(7, nullptr);

    vector<ListNode*> lists = {a, b, c};
    Solution sol;
    ListNode* res = sol.mergeKLists(lists);
    while (res){
        cout << res->val << endl;
        res = res->next;
    }
}