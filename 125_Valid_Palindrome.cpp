#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int length = s.size();
        int left = 0;
        int right = length-1;
        while(left<right){
            while (left<right && !isalnum(s[left])) left++;
            while (left<right && !isalnum(s[right])) right--;
            if (tolower(s[left])!=tolower(s[right])){
                return false;
            }
            left++;
            right--;
        };
        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << sol.isPalindrome("abba") << endl;  // true
    cout << sol.isPalindrome("racecar") << endl;  // true
    cout << sol.isPalindrome("hello") << endl;  // false
}
