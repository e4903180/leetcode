# include <iostream>
# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (int num: nums) {
            freqs[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (auto& p : freqs) {
            int num = p.first;
            int count = p.second;
            min_heap.push({count, num});
            if ((int)min_heap.size() > k) {
                min_heap.pop();
            }
        }
        vector<int> res;
        while (!min_heap.empty()) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};
// Time: O(nlogk), Space:O(k)
// heap push, pop是logk，做n次
// 一般排序要nlogn，當n>>k時不優

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution sol;
    vector<int> ans = sol.topKFrequent(nums, k);

    cout << "Top " << k << " Frequent Elements: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}