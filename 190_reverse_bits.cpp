# include <iostream>
using namespace std;


class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for (int i=0; i<32; i++) {
            res <<= 1;
            res |= (n & 1);
            n >>= 1;
        }
        return res;
    }
};

int main(){
    int n = 43261596;
    Solution sol;
    int result = sol.reverseBits(n);
    cout << result << endl;
}