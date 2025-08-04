# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

//  DP
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         vector<int> dp(nums.size());
//         int maxSum = nums[0];
//         dp[0] = nums[0];
//         for (int i=1; i<nums.size(); i++){
//             dp[i] = max(nums[i], dp[i-1]+nums[i]);
//             maxSum = max(maxSum, dp[i]);
//         }
//         return maxSum;
//     }
// };


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i=1; i<nums.size(); i++){
            currentSum = max(nums[i], currentSum+nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};


int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    int maxSum = sol.maxSubArray(nums);
    cout << maxSum << endl;
}