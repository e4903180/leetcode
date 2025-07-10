#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t){
            return true;
        }
        return false;
    }
};

int main() {
    Solution sol;

    string s1 = "anagram";
    string s2 = "nagaram";
    string s3 = "rat";
    string s4 = "car";

    cout << boolalpha;
    cout << "anagram vs nagaram: " << sol.isAnagram(s1, s2) << endl; // true
    cout << "rat vs car: " << sol.isAnagram(s3, s4) << endl;         // false

    return 0;
}