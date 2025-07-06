#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        int degree = 0;
        for (int n: nums){
                degree = log10(n)+1;
            if (degree %2 == 0){
                count++;
            }
        }        
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {12,345,2,6,7896};
    int ans = sol.findNumbers(nums);
    cout << ans << endl;
}