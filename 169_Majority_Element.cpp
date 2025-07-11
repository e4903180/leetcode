#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> Count;
        int n = nums.size();
        for (int i=0; i<n; i++){
            Count[nums[i]]++;
        }
        n = n/2;
        for (auto x: Count){
            if (x.second>n){
                return x.first;
            }
        }
        return 0;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,2,3};
    int ans = sol.majorityElement(nums);
    cout << ans << endl;
}