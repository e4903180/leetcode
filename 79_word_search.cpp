# include <iostream>
# include <vector>
using namespace std;


class Solution {
public:
    bool dfs(int x, int y, int index, vector<vector<char>>& board, string word) {
            int m = board.size();
            int n = board[0].size();
            if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[index]) return false;
            if (index==(int)word.size()-1) return true;
            char temp = board[x][y];
            board[x][y] = '#';
            index++;
            bool found = (dfs(x+1, y, index, board, word) || dfs(x-1, y, index, board, word) || dfs(x, y+1, index, board, word) || dfs(x, y-1, index, board, word));
            index--;
            board[x][y] = temp;
            return found;
        };
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()||board[0].empty()) return false;
        int m = board.size();
        int n = board[0].size();

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (dfs(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};
// Time: O(n*m*4^L), Space: O(L)

int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    Solution sol;
    cout << sol.exist(board, "ABCCED") << endl;
}