#include <iostream>
using namespace std;


class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while (num >0){
            if (num%2 == 1){
                num-=1;
            }
            else{
                num/=2;
            }
            count+=1;
        }
        return count;
    }
};

int main(){
    Solution sol;
    int num = 14;
    int steps = sol.numberOfSteps(num);
    cout << steps << endl;
    return 0;
}