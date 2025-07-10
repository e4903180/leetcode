#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int min_price = INT_MAX;
            int max_profit = 0;
            for (int price: prices){
                if (price<min_price){
                    min_price = price;
                }
                int profit = price - min_price;
                if (profit>max_profit){
                    max_profit = profit;
                }
            }
            return max_profit;
        }
    };

int main(){
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    int ans = sol.maxProfit(prices);
    cout << ans << endl;
}