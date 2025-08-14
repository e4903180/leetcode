# include <iostream>
# include <vector>
using namespace std;


// class Solution {
// public:
//     bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int index) {
//         int m = board.size(), n = board[0].size();
//         if (i < 0 || j < 0 || i >= m || j >= n) return false;
//         if (board[i][j] != word[index]) return false;
//         if (index == (int)word.size() - 1) return true;

//         char temp = board[i][j];
//         board[i][j] = '#'; // 訪問標記

//         // 四個方向
//         static const int dx[4] = {1, -1, 0, 0};
//         static const int dy[4] = {0, 0, 1, -1};
//         bool ok = false;
//         for (int d = 0; d < 4 && !ok; ++d) {
//             ok = dfs(board, word, i + dx[d], j + dy[d], index + 1);
//         }

//         board[i][j] = temp;
//         return ok;
//     }

//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         vector<string> res;
//         if (board.empty() || board[0].empty() || words.empty()) return res;

//         int m = board.size(), n = board[0].size();
//         // 預先統計棋盤字母頻率（可做剪枝）
//         array<int, 26> boardCnt{}; boardCnt.fill(0);
//         for (auto& row : board) for (char c : row) boardCnt[c - 'a']++;

//         for (const string& w : words) {
//             // 剪枝1：長度超過可用格數
//             if ((int)w.size() > m * n) continue;

//             // 剪枝2：字母頻率不足
//             array<int, 26> need{}; need.fill(0);
//             bool feasible = true;
//             for (char c : w) {
//                 int k = c - 'a';
//                 if (++need[k] > boardCnt[k]) { feasible = false; break; }
//             }
//             if (!feasible) continue;

//             bool found = false;
//             for (int i = 0; i < m && !found; ++i) {
//                 for (int j = 0; j < n && !found; ++j) {   // 這裡也加 !found
//                     if (board[i][j] == w[0] && dfs(board, w, i, j, 0)) {
//                         res.push_back(w);
//                         found = true;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// }; 
// Time: O(W×m×n×3L−1), Space: O(L+W*L)
class Node{
public:
    vector<Node*> next; // 子節點指標（26個英文字母）
    string word;        // 當前節點對應的完整單字（若是終點）
    Node(): next(26, nullptr) {};
};

class Solution {
public:
    Node* buildTrie(vector<string>& words){
        Node* root = new Node();
        for (const string& w: words) {
            Node* curr = root;
            for (char c: w) {
                int k = c - 'a';
                if (!curr->next[k]) {           // 若子節點不存在，建立新節點
                    curr->next[k] = new Node();
                }
                curr = curr->next[k];           // 移到下一層
            }
            curr->word = w; // 標記單字終點
        }
        return root;
    }

    void dfs(int i, int j, Node* curr, vector<vector<char>>& board, vector<string>& res){
        int m = board.size();
        int n = board[0].size();
        char c = board[i][j];
        if (c == '#') return;                   // 已訪問過
        curr = curr->next[c - 'a'];
        if (!curr) return;                      // 該路徑不在字典中
        if (!curr->word.empty()) {               // 找到完整單字
            res.push_back(curr->word);
            curr->word.clear();                  // 避免重複加入
        }

        char temp = board[i][j];
        board[i][j] = '#';                       // 標記已訪問

        // 四方向搜尋
        if (i > 0) dfs(i - 1, j, curr, board, res);
        if (j > 0) dfs(i, j - 1, curr, board, res);
        if (i < m-1) dfs(i + 1, j, curr, board, res);
        if (j < n-1) dfs(i, j + 1, curr, board, res);

        board[i][j] = temp;                      // 回溯還原
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty()||board[0].empty()||words.empty()) return res;

        Node* root = buildTrie(words);           // 1. 建立 Trie

        int m = board.size();
        int n = board[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                // 2. 從棋盤每個可能的起點 DFS
                if (root->next[board[i][j] - 'a']) {
                    dfs(i, j, root, board, res);
                }
            }
        }
        return res;                              // 3. 回傳所有找到的單字
    }
};

// 假設 m=rows, n=cols, W=words, L=maxLen
// 時間: O(W*L + m*n*3^(L-1)) // 插入+DFS(剪枝)
// 空間: O(W*L + L)           // Trie + 遞迴棧
// Time: O(W*L + m*n*3^(L-1)), Space: O(W*L + L)

int main(){
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'}, {'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    // vector<vector<char>> board = {{'a'}, {'a'}};
    // vector<string> words = {"a"};

    Solution sol;
    vector<string> res = sol.findWords(board, words);
    for (string word: res) {
        cout <<  word << endl;
    }
}