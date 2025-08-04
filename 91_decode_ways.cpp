# include <iostream>
# include <vector>
using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s.empty() || s[0] == '0') return 0;
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i=2; i<=n; i++){
            if (s[i-1]!='0'){
                dp[i] += dp[i-1];  
            }
            int twoDigit = stoi(s.substr(i-2, 2));
            if (twoDigit >= 10 && twoDigit <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    string s = "226";
    cout << "Number of ways to decode \"" << s << "\": " 
         << sol.numDecodings(s) << endl;
    return 0;
}