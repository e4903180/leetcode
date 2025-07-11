#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int remove_Element(vector<int>& nums, int val) {
            int slow_pointer = 0;
            for(int fast_pointer = 0; fast_pointer<nums.size(); fast_pointer++){
                if(nums[fast_pointer] != val){
                    nums[slow_pointer] = nums[fast_pointer];
                    slow_pointer++;
                }
            }
            return slow_pointer;
        };
    };

int main(){
    vector<int> nums = {3,2,2,3};
    int val = 2;
    Solution sol;
    cout << sol.remove_Element(nums, val) << endl;
    return 0;
}
