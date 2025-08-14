# include <iostream>
using namespace std;


class Solution {
public:
    int getSum(int a, int b) {
        int a_LSB = 0;
        int b_LSB = 0;
        int carry = 0;
        int remainder = 0;
        int res = 0;
        const int BITS = sizeof(int) * 8;
        for (int i=0; i<BITS; i++) {
            a_LSB = (a >> i) & 1;
            b_LSB = (b >> i) & 1;
            remainder = a_LSB ^ b_LSB ^ carry;
            int next_carry = (a_LSB & b_LSB) | ((a_LSB ^ b_LSB) & carry);
            res |= (remainder << i);
            carry = next_carry;
        }
        return res;
    }
};

int main() {
    int a = 7;
    int b = 7;
    Solution sol;
    cout << sol.getSum(a, b) << endl;
}