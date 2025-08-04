# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapping;
        int length = nums.size();
        for (int i = 0; i < length; i++){
            mapping[nums[i]] = i;
        }
        
        for (int i=0; i<length; i++){
            int complement = target - nums[i];
            if (mapping.count(complement) && mapping[complement]!=i){
                return {i, mapping[complement]};
            }
        }
        return {};
    }
};