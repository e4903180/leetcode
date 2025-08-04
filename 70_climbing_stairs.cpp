# include <iostream>
# include <vector>
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main(){
    int n = 5;
    Solution sol;
    int ways = sol.climbStairs(n);
    cout << ways << endl;
}