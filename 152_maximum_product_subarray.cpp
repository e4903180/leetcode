#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for (int i=1; i<n; i++){
            if (nums[i]<0){
                swap(maxProd, minProd);
            }
            maxProd = max(maxProd*nums[i], nums[i]);
            minProd = min(minProd*nums[i], nums[i]);
            result = max(result, maxProd);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4, -1, 3, -3, 100};

    Solution sol;
    int ans = sol.maxProduct(nums);

    cout << "Maximum Product Subarray = " << ans << endl;

    return 0;
}