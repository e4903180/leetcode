#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        vector<int> check(length+1, -1);
        for (int num: nums){
            check[num] = 1;
        }
        for (int i=0; i<=length; i++){
            if (check[i]==-1){
                return i;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 0, 3};
    int ans = sol.missingNumber(nums);
    cout << ans << endl;
}