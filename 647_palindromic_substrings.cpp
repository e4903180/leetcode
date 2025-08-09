# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;


class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> cache(n, vector<bool>(n, false));
        int count=0;
        for (int i=0; i<n; i++){
            cache[i][i] = true;
            count++;
        }

        for (int len=2; len<=n; ++len){
            for (int i=0; i<=n-len; i++){
                int j = i + len - 1;
                if (s[i] == s[j]){
                    if (len==2||cache[i+1][j-1]){
                        cache[i][j] = true;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};


int main() {
    Solution sol;

    string test1 = "abc";  // 3: "a", "b", "c"
    string test2 = "aaa";  // 6: "a", "a", "a", "aa", "aa", "aaa"

    cout << "Test 1 result: " << sol.countSubstrings(test1) << endl;
    cout << "Test 2 result: " << sol.countSubstrings(test2) << endl;

    return 0;
}