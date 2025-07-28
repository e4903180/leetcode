#include <bits/stdc++.h>
#include <windows.h> // 用 Sleep() 取代 usleep()
using namespace std;

void printGrid(const vector<string>& grid, int step) {
    cout << "\nStep " << step << ":\n";
    for (auto& row : grid) {
        cout << row << "\n";
    }
    cout << string(grid[0].size(), '-') << "\n";
    // Sleep(500); // 0.5 秒
}

bool simulateFireEscape(vector<string> grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> fire_time(m, vector<int>(n, INT_MAX));
    queue<tuple<int,int,int>> fire_q;

    pair<int,int> start, exit;
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 'F') {
                fire_q.push(make_tuple(r, c, 0));
                fire_time[r][c] = 0;
            }
            if (grid[r][c] == 'U') start = make_pair(r, c);
            if (grid[r][c] == 'E') exit = make_pair(r, c);
        }
    }

    vector<pair<int,int>> dirs;
    dirs.push_back(make_pair(1,0));
    dirs.push_back(make_pair(-1,0));
    dirs.push_back(make_pair(0,1));
    dirs.push_back(make_pair(0,-1));

    // BFS for fire spread
    while (!fire_q.empty()) {
        int r, c, t;
        tie(r, c, t) = fire_q.front(); fire_q.pop();

        for (size_t i = 0; i < dirs.size(); i++) {
            int dr = dirs[i].first, dc = dirs[i].second;
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                grid[nr][nc] != '#' && fire_time[nr][nc] == INT_MAX) {
                fire_time[nr][nc] = t + 1;
                fire_q.push(make_tuple(nr, nc, t + 1));
            }
        }
    }

    // Player BFS with simulation
    queue<tuple<int,int,int>> player_q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    player_q.push(make_tuple(start.first, start.second, 0));
    visited[start.first][start.second] = true;

    int step = 0;
    printGrid(grid, step);

    while (!player_q.empty()) {
        int size = player_q.size();
        vector<pair<int,int>> next_positions;

        while (size--) {
            int r, c, t;
            tie(r, c, t) = player_q.front(); player_q.pop();

            if (make_pair(r, c) == exit) {
                cout << "Player escaped successfully!\n";
                return true;
            }

            for (size_t i = 0; i < dirs.size(); i++) {
                int dr = dirs[i].first, dc = dirs[i].second;
                int nr = r + dr, nc = c + dc, nt = t + 1;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] != '#') {
                    if (nt < fire_time[nr][nc]) {
                        visited[nr][nc] = true;
                        next_positions.push_back(make_pair(nr, nc));
                        player_q.push(make_tuple(nr, nc, nt));
                    }
                }
            }
        }

        step++;

        if (next_positions.empty()) {
            cout << "Player cannot escape!\n";
            return false;
        }

        // 更新地圖：火焰
        vector<string> current = grid;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (fire_time[r][c] <= step) current[r][c] = 'F';
            }
        }
        // 玩家
        for (size_t i = 0; i < next_positions.size(); i++) {
            int r = next_positions[i].first, c = next_positions[i].second;
            if (current[r][c] == '.') current[r][c] = 'U';
        }

        printGrid(current, step);
    }

    cout << "Player cannot escape!\n";
    return false;
}

int main() {
    vector<string> grid;
    grid.push_back("#######");
    grid.push_back("#U....#");
    grid.push_back("#.###E#");
    grid.push_back("#F....#");
    grid.push_back("#######");

    simulateFireEscape(grid);
    return 0;
}
