#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        string replaceNumber(string s){
            int count = 0;
            for (int i=0; i<s.size(); i++){
                if (s[i] >= '0' && s[i] <= '9'){
                    count++;
                };
            };
            
            int old_index=s.size()-1;
            s.resize(s.size()+count*5);
            int new_index=s.size()-1;
            while (old_index>=0){
                if (s[old_index] >= '0' && s[old_index] <= '9'){
                    s[new_index--] = 'r';
                    s[new_index--] = 'e';
                    s[new_index--] = 'b';
                    s[new_index--] = 'm';
                    s[new_index--] = 'u';
                    s[new_index--] = 'n';
                }else{
                    s[new_index] = s[old_index];
                    new_index--;
                }
                old_index--;
            }
            return s;
    };
};

int main() {
    string s("a1b2c3");
    Solution sol;
    s = sol.replaceNumber(s);
    for (char c : s) {
        cout << c;
    }
    cout << endl;
    return 0;
}
