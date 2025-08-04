# include <iostream>
# include <vector>
# include <algorithm>
# include <unordered_set>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : num_set) {
            if (!num_set.count(num - 1)) {
                int curr = num;
                int len = 1;
                while (num_set.count(curr + 1)) {
                    curr++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = sol.longestConsecutive(nums);
    cout << "Longest consecutive sequence length: " << result << endl;
    return 0;
}