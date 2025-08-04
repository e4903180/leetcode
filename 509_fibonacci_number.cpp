# include <iostream>
# include <vector>
using namespace std;


class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> f(n+1);
        f[0] = 0;
        f[1] = 1;
        for (int i=2; i<=n; i++){
            f[i] = f[i-1] + f[i-2]; 
        }
        return f[n];
    }
};

int main(){
    int n = 4;
    Solution sol;
    int ans = sol.fib(n);
    cout << ans << endl;
}