# include <iostream>
# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


// BFS
// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if (!node) return nullptr;
//         unordered_map<Node*, Node*> visited;
//         queue<Node*> q;
//         Node* cloneNode = new Node(node->val);
//         visited[node] = cloneNode;
//         q.push(node);

//         while(!q.empty()){
//             Node* curr = q.front();
//             q.pop();
//             for (auto neighbor: curr->neighbors){
//                 if (visited.find(neighbor)==visited.end()){
//                     visited[neighbor] = new Node(neighbor->val);
//                     q.push(neighbor);
//                 }
//                 visited[curr]->neighbors.push_back(visited[neighbor]);
//             }
//         }
//         return cloneNode;
//     }
// };

// 輔助函式：印出圖 (BFS)
void printGraphBFS(Node* node) {
    if (!node) return;
    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << "Node " << curr->val << " -> ";
        for (auto neighbor : curr->neighbors) {
            cout << neighbor->val << " ";
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        cout << endl;
    }
}

// DFS
class Solution {
private:
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (visited.find(node)!=visited.end()){
            return visited[node];
        }
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        for (auto neighbor: node->neighbors){
            visited[node]->neighbors.push_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};

// 輔助函式：印出圖 (DFS)
void printGraphDFSUtility(Node* node, unordered_map<Node*, bool>& visited) {
    if (!node) return;

    visited[node] = true;
    cout << "Node " << node->val << " -> ";
    for (auto neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    for (auto neighbor : node->neighbors) {
        if (!visited[neighbor]) {
            printGraphDFSUtility(neighbor, visited);
        }
    }
}

void printGraphDFS(Node* node) {
    unordered_map<Node*, bool> visited;
    printGraphDFSUtility(node, visited);
}

int main() {
    // 建立原圖：四個節點 1-2-3-4（形成正方形）
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    cout << "Original graph:" << endl;
    printGraphBFS(node1);

    // 複製圖
    Solution sol;
    Node* clonedGraph = sol.cloneGraph(node1);

    cout << "\nCloned graph:" << endl;
    printGraphBFS(clonedGraph);

    return 0;
}
