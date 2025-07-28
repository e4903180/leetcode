# include <iostream>
# include <vector>
using namespace std;


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_in(n);
        vector<int> trust_out(n);
        for (int i=0; i<trust.size(); i++){
            trust_out[trust[i][0] - 1]++;
            trust_in[trust[i][1] - 1]++;
        }
        for (int i=0; i<n; i++){
            if (trust_in[i]==n-1 && trust_out[i]==0){
                return i + 1;
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    Solution sol;
    int judge = sol.findJudge(3, trust);
    cout << judge <<endl;
}