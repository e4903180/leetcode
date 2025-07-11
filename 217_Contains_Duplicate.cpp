#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int num: nums){
            if (seen[num]>=1){
                return true;
            }
            seen[num]++;
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    bool ans = sol.containsDuplicate(nums);
    cout << ans << endl;
}