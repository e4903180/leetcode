# include <iostream>
# include <vector>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int old_color){
        if (sr<0||sr>=image.size()||sc<0||sc>=image[0].size()||image[sr][sc] != old_color) return;
        image[sr][sc] = color;
        dfs(image, sr+1, sc, color, old_color);
        dfs(image, sr-1, sc, color, old_color);
        dfs(image, sr, sc+1, color, old_color);
        dfs(image, sr, sc-1, color, old_color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};

int main(){
    // vector<vector<int>> image = {{1, 1, 1, 0}, {1, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 1}};
    vector<vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
    Solution sol;
    image = sol.floodFill(image, 0, 1, 2);
    for (int i=0; i<image.size(); i++){
        for (int j=0; j<image[i].size(); j++){
            cout << image[i][j];
        }
        cout << endl;
    }
    return 0; 
}