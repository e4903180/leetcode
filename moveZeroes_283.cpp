#include <iostream>
#include <vector>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow_pointer = 0;
        for (int fast_pointer = 0; fast_pointer < nums.size(); fast_pointer++) {
            if (nums[fast_pointer] != 0) {
                nums[slow_pointer] = nums[fast_pointer];
                slow_pointer++;
            }
        }
        for (int i = slow_pointer; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution sol;
    sol.moveZeroes(nums);

    // 正確輸出 vector
    cout << "結果: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
