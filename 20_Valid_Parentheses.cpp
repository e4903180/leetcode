#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> container;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char c:s){
            if (mapping.find(c) == mapping.end()){
                container.push(c);
            }
            else if (!container.empty() && mapping[c]==container.top()){
                container.pop();
            }
            else{
                return false;
            }
        }
        return container.empty();
    }
};


int main() {
    Solution solution;

    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";
    string test6 = "(";
    string test7 = "";

    cout << boolalpha;  // Print "true"/"false" instead of 1/0
    cout << "Test 1: " << solution.isValid(test1) << endl;  // true
    cout << "Test 2: " << solution.isValid(test2) << endl;  // true
    cout << "Test 3: " << solution.isValid(test3) << endl;  // false
    cout << "Test 4: " << solution.isValid(test4) << endl;  // false
    cout << "Test 5: " << solution.isValid(test5) << endl;  // true
    cout << "Test 6: " << solution.isValid(test6) << endl;  // false
    cout << "Test 7: " << solution.isValid(test7) << endl;  // true

    return 0;
}