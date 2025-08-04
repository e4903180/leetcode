#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int len = end - start;
        if (len==1) return nums[start];
        vector<int> dp(len);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);
        for (int i=2; i<len; i++){
            dp[i] = max(dp[i-2] + nums[start+i], dp[i-1]);
        }
        return dp[len-1];
    }

    int rob(vector<int>& nums){
        int n = nums.size();
        if (n==1) return nums[0];
        if (n==2) return max(nums[0], nums[1]);

        return max(robLinear(nums, 0, n-1), robLinear(nums, 1, n));
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    cout << sol.rob(nums) << endl;
}