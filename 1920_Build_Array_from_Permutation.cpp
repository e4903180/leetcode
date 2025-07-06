#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int length = nums.size();
        vector<int> ans;
        for (int i=0; i<length; i++){
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0, 2, 1, 5, 3, 4};
    vector<int> ans = sol.buildArray(nums);
    for (int n : ans) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}