# include <iostream>
# include <vector>
using namespace std;


// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<bool>> seen(m, vector<bool>(n, false));
//         for (int i=0; i<m; i++){
//             for (int j=0; j<n; j++){
//                 if (!seen[i][j] && matrix[i][j]==0){
//                     dfs(matrix, i, j, seen);
//                 }
//             }
//         }
//     }
//     void dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<bool>>& seen){
//         int m = matrix.size();
//         int n = matrix[0].size();
//         for (int i=0; i<m; i++){
//             if (!seen[i][y] && matrix[i][y]!=0){
//                 seen[i][y] = true;
//                 matrix[i][y] = 0;
//             }
//         }
//         for (int j=0; j<n; j++){
//             if (!seen[x][j] && matrix[x][j]!=0){
//                 seen[x][j] = true;
//                 matrix[x][j] = 0;
//             }
//         }
//     }
// }; 
// Time: O(m*n), Space: O(m*n)


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()||matrix[0].empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstColZero = false;
        bool firstrowZero = false;
        for (int i=0; i<m; i++) if (matrix[i][0]==0) firstColZero = true;
        for (int j=0; j<n; j++) if (matrix[0][j]==0) firstrowZero = true;

        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (matrix[i][j]==0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i=1; i<m; i++) {
            if (matrix[i][0]==0){
                for (int j=1; j<n; j++) {
                        matrix[i][j] = 0;
                }
            }
        }
        for (int j=1; j<n; j++) {
            if (matrix[0][j]==0){
                for (int i=1; i<m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstColZero) for (int i=0; i<m; i++) matrix[i][0] = 0;
        if (firstrowZero) for (int j=0; j<n; j++) matrix[0][j] = 0;
    }
};
// Time: O(m*n), Space: O(1))

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    sol.setZeroes(matrix);
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << matrix[i][j];
            }
            cout << endl;
        }
    }