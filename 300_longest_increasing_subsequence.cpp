#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (nums[j]<nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main(){
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << sol.lengthOfLIS(nums) << endl;
}