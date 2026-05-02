#include <iostream>
#include <climits>
using namespace std;
const int MAX = 50;
double infi = 1e9;
double ans = infi;
bool visited[MAX];
void tsp(int city, int count, double sum, int n, double cost[][MAX]) {
    if (count == n) {
        if (cost[city][0] != infi)
            ans = min(ans, sum + cost[city][0]);
        return;
    }
    for (int next = 0; next < n; next++) {
        if (!visited[next] && cost[city][next] != infi) {
            visited[next] = true;
            tsp(next, count + 1, sum + cost[city][next], n, cost);
            visited[next] = false;
        }
    }
}
void travelsalesperson(int n, double cost[][MAX]) {
    for (int i = 0; i < n; i++)
        visited[i] = false;
    visited[0] = true;  
    tsp(0, 1, 0, n, cost);
    cout << "Minimum Cost: " << ans << endl;
}
int main() {
    int n, e, u, v;
    double cost1, cost2;
    cout << "Enter number of Vertices: ";
    cin >> n;
    cout << "Enter number of Edges: ";
    cin >> e;
    double cost[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = infi;
        }
    }
    for (int i = 0; i < e; i++) {
        cout << "Enter u v cost1 cost2: ";
        cin >> u >> v >> cost1 >> cost2;
        cost[u][v] = cost1;
        cost[v][u] = cost2;
    }
    travelsalesperson(n, cost);
}
