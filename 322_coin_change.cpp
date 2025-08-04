#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount==0) return 0;
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i=1; i<=amount; i++){
            for (int c: coins){
                if ((i-c)>=0){
                    dp[i] = min(dp[i], dp[i-c]+1);
                }
            }
        }
        if (dp[amount]>amount) return -1;
        return dp[amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = sol.coinChange(coins, amount);
    if (result == -1) {
        cout << "Cannot make amount " << amount << " with given coins." << endl;
    } else {
        cout << "Minimum coins needed: " << result << endl;
    }
    return 0;
}
