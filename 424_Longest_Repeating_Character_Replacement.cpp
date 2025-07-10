#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0;
        int right = 0;
        int maxCount = 0;
        int maxLength = 0;
        for (right=0; right<static_cast<int>(s.size()); right++){
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);

            while ((right-left+1)-maxCount>k){
                count[s[left] - 'A']--;
                left++;
            }
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};

int main() {
    Solution sol;
    cout << sol.characterReplacement("ABAB", 2) << endl;
    return 0;
}

