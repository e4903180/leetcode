# include <iostream>
using namespace std;


class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        for (int i=0; i<32; i++) {
            if (n & (1 << i)) {
                count++;
            }
        }
        return count;
    }
};

int main(){
    int n = 11;
    Solution sol;
    int result = sol.hammingWeight(n);
    cout << result << endl;
}