// # include <iostream>
// # include <vector>
// # include <unordered_map>
// # include <queue>
// using namespace std;


// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> nextCourse(numCourses);
//         vector<int> indegree(numCourses, 0);

//         for (auto& prerequisite : prerequisites) {
//             nextCourse[prerequisite[1]].push_back(prerequisite[0]);
//             indegree[prerequisite[0]]++;
//         }

//         queue<int> q;
//         for (int i = 0; i < numCourses; i++) {
//             if (indegree[i] == 0) q.push(i);
//         }

//         int course = 0;
//         while (!q.empty()) {
//             int curr = q.front();
//             q.pop();
//             course++;

//             for (int next : nextCourse[curr]) {
//                 indegree[next]--;
//                 if (indegree[next] == 0) {
//                     q.push(next);
//                 }
//             }
//         }
//         return course == numCourses;
//     }
// };


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nextCorse(numCourses);
        vector<int> indegree(numCourses, 0);
        int course=0;
        queue<int> q;

        cout << "processing: " << prerequisites[0][0] << endl;
        // if (numCourses == 0) return true;

        for (vector<int> prerequisite: prerequisites){
            cout << prerequisite[0] << prerequisite[1] <<endl;
            nextCorse[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        for (int i=0; i<numCourses; i++){
            if (indegree[i]==0) q.push(i);
        }
        
        while (!q.empty()){
            cout << q.front() <<endl;
            int curr = q.front();
            q.pop();
            course++;
            for (int next: nextCorse[curr]){
                indegree[next]--;
                if (indegree[next]==0){
                    q.push(next);
                }
            }
        }
        if (course == numCourses) return true;
        return false;
    }
};


class Solution {
public:
    bool dfs(int prerequisite, unordered_map<int, bool>& visited){
        cout << "prerequisite: " << prerequisite << " " << "visited: " << visited[prerequisite] << " ";
        if (visited[prerequisite]==true){
            return false;
        }
        visited[prerequisite] = true;
        dfs(prerequisite, visited);
        return true;
    } 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size()==0) return true;

        for (int i=0; i<prerequisites.size(); i++){
            unordered_map<int, bool> visited;
            visited.clear();
            bool result = dfs(prerequisites[i][1], visited);
            if (result == false) return false;
        }
        return true;
    }
};

// int main(){
//     int numCourse = 4;
//     vector<vector<int>> prerequisites={{1,2},{2,3},{3,4},{4,1}};
//     Solution sol;
//     bool result = sol.canFinish(numCourse, prerequisites);
//     if (result){
//         cout << "result: true" << endl;
//     }
//     cout << "result: false" << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]); // b -> a
            indegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            for (int next : graph[course]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }

        return count == numCourses;
    }
};


int main() {
    int numCourse = 4;
    vector<vector<int>> prerequisites = {{1,2}, {2,3}, {3,4}, {4,1}}; // 形成環
    Solution sol;
    bool result = sol.canFinish(numCourse, prerequisites);
    cout << "result: " << result << endl;  // 輸出 0（false）
    return 0;
}
