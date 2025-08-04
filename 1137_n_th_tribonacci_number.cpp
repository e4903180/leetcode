# include <iostream>
# include <vector>
using namespace std;


class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        vector<int> f(n+2);
        f[0] = 0;
        f[1] = 1;
        f[2] = 1;
        for (int i=3; i<=n; i++){
            f[i] = f[i-1] + f[i-2] + f[i-3]; 
        }
        return f[n];
    }
};

int main(){
    int n = 25;
    Solution sol;
    int ans = sol.tribonacci(n);
    cout << ans << endl;
}