# include <iostream>
# include <vector>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int prefix = 1, postfix = 1;
        for (int i=0; i<n; i++){
            res[i] *= prefix;
            prefix *= nums[i];
            res[n-i-1] *= postfix;
            postfix *= nums[n-i-1];
        }
        return res;
    }
};
// Time: O(n), Space: O(1)

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> res(n);
//         int prefix = 1, postfix = 1;
//         for (int i=0; i<n; i++){
//             res[i] = prefix;
//             prefix *= nums[i];
//         }
//         for (int j=n-1; j>=0; j--){
//             res[j] *= postfix;
//             postfix *= nums[j];
//         }
//         return res;
//     }
// };

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    vector<int> output = sol.productExceptSelf(nums);
    for (int i=0; i<(int)output.size(); i++) {
        cout << output[i] << " ";
    }
}