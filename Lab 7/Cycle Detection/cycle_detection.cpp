#include <iostream>
using namespace std;
const int MAX = 100;
int parent[MAX]; 
void printCycle(int start, int end){
    cout << "Cycle: ";
    int temp = start;
    cout << end << " ";
    while (temp != end) {
        cout << temp << " ";
        temp = parent[temp]; }
    cout << end << endl;
}
bool dfs(int v, int n, int adj[MAX][MAX], bool visited[], bool path[]){
    visited[v] = true;
    path[v] = true;
    for (int i = 1; i <= n; i++){
        if (adj[v][i] != 0){
            if (!visited[i]){
                parent[i] = v; 
                if (dfs(i, n, adj, visited, path))
                    return true;
            }
            else if (path[i]) {
                printCycle(v, i);
                return true;
            }
        }
    }
    path[v] = false;
    return false;
}
bool detectCycle(int n, int adj[MAX][MAX]){
    bool visited[MAX] = {false};
    bool path[MAX] = {false};
    for (int i = 1; i <= n; i++){
        parent[i] = -1; }
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            if (dfs(i, n, adj, visited, path)){
                return true;}
        }
    }
    return false;
}
int main(){
    int n;
    int adj[MAX][MAX];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter adjacency matrix:\n";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> adj[i][j]; }
        }
    if (!detectCycle(n, adj)){
        cout << "No cycle in the graph\n"; }
    return 0;
}