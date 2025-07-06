#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int length = nums.size();
        for (int i=0; i<length; i++){
            int left = 0;
            int right = 0;
            for (int j=0; j<i; j++){
                left+=nums[j];
                cout << "j: " << j << endl;
                cout << "nums[j]: " << nums[j] << endl;
                cout << "left: " << left << endl;
            }
            for (int k=i+1; k<length; k++){
                right+=nums[k];
                cout << "k: " << k << endl;
                cout << "nums[k]: " << nums[k] << endl;
                cout << "right: " << right << endl;
            }
            if (left == right){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,7,3,6,5,6};
    int ans = sol.pivotIndex(nums);
    cout << ans << endl;
}