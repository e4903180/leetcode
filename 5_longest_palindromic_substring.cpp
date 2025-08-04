# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;


// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();

//         auto expand = [&](int left, int right){
//             while(left>=0 && right<n && s[left]==s[right]){
//                 left--;
//                 right++;
//             }
//             return right-left-1;
//         };
//         int maxLen = 1;
//         int start = 0;
//         for (int i=0; i<n; i++){
//             int len1 = expand(i, i);
//             int len2 = expand(i, i+1);
//             int len = max(len1, len2);
//             if (len>maxLen){
//                 maxLen = len;
//                 start = i-(len-1)/2;
//             }
//         }
//         return s.substr(start, maxLen);
//     }
// };


// dp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> cache(n, vector<bool>(n, false));

        for (int i=0; i<n; i++){
            cache[i][i] = true;
        }
        int maxLen = 1;
        int start = 0;
        for (int len=2; len<=n; ++len){
            for (int i=0; i<=n-len; ++i){
                int j = i + len - 1;

                if (s[i]==s[j]){
                    if (len==2||cache[i+1][j-1]){
                        cache[i][j] = true;
                        if (len>maxLen){
                            maxLen = len;
                            start = i;
                        }
                    }
                }
            }
        }
        return s.substr(start, maxLen);

    }
};

int main() {
    Solution sol;
    string s = "babad";

    string result = sol.longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}