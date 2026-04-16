#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
#define MAX 1000
#define INF INT_MAX
struct Node {
    int vertex;
    int dist;
};

int cost[MAX][MAX];
int dist[MAX];
int visited[MAX];
int parent[MAX];

Node heap[MAX];
int heapSize = 0;
void insertHeap(int v, int d) {
    heapSize++;
    heap[heapSize].vertex = v;
    heap[heapSize].dist = d;
    int i = heapSize;
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(heap[i], heap[i/2]);
        i /= 2;
    }
}
Node deleteMin() {
    Node minNode = heap[1];
    heap[1] = heap[heapSize];
    heapSize--;
    int i = 1;
    while (2 * i <= heapSize) {
        int child = 2 * i;
        if (child + 1 <= heapSize && heap[child + 1].dist < heap[child].dist)
            child++;
        if (heap[i].dist > heap[child].dist) {
            swap(heap[i], heap[child]);
            i = child;
        } else break;
    }
    return minNode;
}
bool isEmpty()
{
    return heapSize == 0;
}
void printPath(int v) {
    int path[MAX];
    int k = 0;

    while (v != -1) {
        path[k++] = v;
        v = parent[v];
    }

    for (int i = k - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0)
            cout << " -> ";
    }
}
int Dijkstra(int n, int source)
{
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    heapSize = 0;
    dist[source] = 0;
    insertHeap(source, 0);
    while (!isEmpty())
    {
         Node temp = deleteMin();
        int u = temp.vertex;

        if (visited[u]) continue;
        visited[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (cost[u][v] != INF && !visited[v])
            {
                if (dist[v] > dist[u] + cost[u][v])
                {
                    dist[v] = dist[u] + cost[u][v];
                    parent[v] = u;   
                    insertHeap(v, dist[v]);
                }
            }
        }
    }
    int total = 0;
    for (int i = 0; i < n; i++)
        if (dist[i] != INF)
            total += dist[i];
    return total;
}
void generateGraph(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }
    for (int i = 0; i < n - 1; i++){
        int w = rand() % 10 + 1;
        cost[i][i + 1] = w;
        cost[i + 1][i] = w;
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 2; j < n; j++){
            if (rand() % 2){
                int w = rand() % 20 + 1;
                cost[i][j] = w;
                cost[j][i] = w;
            }
        }
    }
}
double measureTime(int n)
{
    clock_t start = clock();
    for(int i = 0; i < 1000; i++) {
       Dijkstra(n, 0);
    }
    // Dijkstra(n, 0);
    clock_t end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;
    return time * 1000000000.0; 
}
int main()
{
    srand(time(0));
    ofstream txtFile("dijkestra_txt.txt");
    ofstream csvFile("dijkestra_csv.txt");
    txtFile << "Vertices\tDistance\tTime(ns)\n";
    csvFile << "Vertices,Time\n";
    for (int n = 10; n <= 400; n += 10)
    {
        cout << "\nVertices: " << n << endl;
        generateGraph(n);
        int result = Dijkstra(n, 0);
        double timeTaken = measureTime(n);
        cout << "Total Distance = " << result << endl;
        cout << "Time = " << timeTaken << " ns\n";
        if (n == 10)
        {
            cout << "\nPaths from source 0:\n";
            for (int i = 0; i < n; i++)
            {
                if (dist[i] == INF)
                {
                    cout << "0 -> " << i << " : No path\n";
                }
                else
                {
                    cout << "0 -> " << i << " : ";
                    printPath(i);
                    cout << "(Cost = " << dist[i] << ")\n";
                }
            }
        }
        txtFile << n << "\t" << result<< "\t" <<timeTaken << endl;
        csvFile << n << "," << timeTaken << endl;
    }
    txtFile.close();
    csvFile.close();
    return 0;
}