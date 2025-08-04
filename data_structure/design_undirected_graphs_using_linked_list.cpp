# include <iostream>
# include <vector>
# include <queue>
using namespace std;


class GraphList{
    private:
        int V;
        vector<vector<int>> adj;

    public:
        GraphList(int V){
            this->V = V;
            adj.resize(V);
        }

        void addEdge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void printGraph(){
            for (int i=0; i<V; i++){
                cout << i <<"->";
                for (int j: adj[i]){
                    cout << j << " ";
                }
                cout << endl;
            }
        }

        void DFS(int start){
            vector<bool> visited(V, false);
            cout << "DFS start from " << start<< ": ";
            DFSUtility(start, visited);
            cout << endl;
        }

        void DFSUtility(int v, vector<bool>& visited){
            visited[v] = true;
            cout << v << " ";

            for (int u: adj[v]){
                if (!visited[u]){
                    DFSUtility(u, visited);
                }
            }
        }

        void BFS(int start){
            vector<bool> visited(V, false);
            queue<int> q;
            visited[start] = true;
            q.push(start);
            cout << "BFS start from " << start << ": ";
            while (!q.empty()){
                int u = q.front();
                q.pop();
                cout << u << " "; 
                for (int v: adj[u]){
                    if (!visited[v]){
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            cout << endl;
        }
};

int main(){
    //     0
    //   / | \
    //  1--2--3
    //   \
    //    4
    //   /
    //  5
    GraphList g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.printGraph();
    // 0->1 2 
    // 1->0 2 3 4
    // 2->0 1 3
    // 3->1 2
    // 4->1 5
    // 5->4
    g.DFS(4);
    // DFS Start from 4: 4 1 0 2 3 5
    g.BFS(4);
    // BFS start from 4: 4 1 5 0 2 3
}