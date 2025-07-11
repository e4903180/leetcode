#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        cout << "intervals" << endl;
        for (vector<int> i: intervals){
            for (int j: i){
                cout << j << endl;
            }
        }
        vector<vector<int>> output;
        int length = intervals.size();
        for (auto interval: intervals){
            if (output.empty()|| output.back()[1]<interval[0]){
                output.push_back(interval);
            }
            else{
                output.back()[1] = max(output.back()[1], interval[1]);
            }
        }
        cout << "output" << endl;
        for (vector<int> i: output){
            for (int j: i){
                cout << j << endl;
            }
        }
        return output;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {12, 16}};
    vector<vector<int>> ans = sol.merge(intervals);
    cout << "ans" << endl;
    for (vector<int> i: ans){
        for (int j: i){
            cout << j << endl;
        }
    }
}