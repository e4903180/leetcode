#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum;
        int length = nums.size();
        sum.push_back(nums[0]);
        for(int i=1; i<length; i++){
            sum.push_back(sum[i-1]+nums[i]);
        }
        return sum;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> sum = sol.runningSum(nums);
    for (int n : sum) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}