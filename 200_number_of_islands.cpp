# include <iostream>
# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<char>>& grid, int h, int w){
        if (h<0||h>=grid.size()||w<0||w>=grid[0].size()||grid[h][w]=='0') return;
        grid[h][w]='0';
        dfs(grid, h+1, w);
        dfs(grid, h-1, w);
        dfs(grid, h, w+1);
        dfs(grid, h, w-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        int wide = grid[0].size();
        int count=0;
        for (int h=0; h<height; h++){
            for (int w=0; w<wide; w++){
                if (grid[h][w]=='1'){
                    dfs(grid, h, w);
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    vector<vector<char>> grid = {
        {'1', '0', '0', '0', '1'},
        {'1', '1', '0', '0', '0'},
        {'1', '0', '0', '1', '0'},
        {'0', '0', '1', '1', '0'},
        {'0', '0', '0', '0', '1'}
    };
    Solution sol;
    cout << sol.numIslands(grid) << endl;
    return 0;
}