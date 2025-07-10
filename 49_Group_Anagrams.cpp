#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapping;
        for (string str: strs){
            string key = str;
            sort(key.begin(), key.end());
            mapping[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& entry: mapping){
            result.push_back(entry.second);
        }
        return result;
    }
};



int main() {
    Solution solution;
    
    // Test input
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    // Group anagrams
    vector<vector<string>> grouped = solution.groupAnagrams(strs);

    // Print result
    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : grouped) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}