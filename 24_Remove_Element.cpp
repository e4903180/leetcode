#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int slow_pointer = 1;
            for(int fast_pointer=1; fast_pointer<nums.size(); fast_pointer++){
                if(nums[fast_pointer] != nums[fast_pointer-1]){
                    nums[slow_pointer] = nums[fast_pointer];
                    slow_pointer++;
                }
            }
            return slow_pointer;
        }
    };

int main(){
    vector<int> nums = {1,1,2,2,3,4,5};
    Solution sol;
    cout << sol.removeDuplicates(nums) << endl;
    return 0;
}
