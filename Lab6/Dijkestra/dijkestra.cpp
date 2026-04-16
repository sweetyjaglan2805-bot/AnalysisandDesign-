#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
#define MAX 1000
#define INF INT_MAX
int cost[MAX][MAX];
int dist[MAX];
int visited[MAX];
int parent[MAX];
int heapNode[MAX];
int heapDist[MAX];
int heapSize = 0;
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void swapHeap(int i, int j)
{
    swap(heapNode[i], heapNode[j]);
    swap(heapDist[i], heapDist[j]);
}
void insertHeap(int node, int d)
{
    heapSize++;
    heapNode[heapSize] = node;
    heapDist[heapSize] = d;
    int i = heapSize;
    while (i > 1 && heapDist[i] < heapDist[i / 2])
    {
        swapHeap(i, i / 2);
        i /= 2;
    }
}
int deleteMin()
{
    int node = heapNode[1];
    heapNode[1] = heapNode[heapSize];
    heapDist[1] = heapDist[heapSize];
    heapSize--;
    int i = 1;
    while (2 * i <= heapSize)
    {
        int child = 2 * i;
        if (child + 1 <= heapSize && heapDist[child + 1] < heapDist[child])
            child++;
        if (heapDist[i] > heapDist[child])
        {
            swapHeap(i, child);
            i = child;
        }
        else
            break;
    }
    return node;
}
bool isEmpty()
{
    return heapSize == 0;
}
void printPath(int v)
{
    if (v == -1) return;
    printPath(parent[v]);
    cout << v << " ";
}
int Dijkstra(int n, int source)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    heapSize = 0;
    dist[source] = 0;
    insertHeap(source, 0);
    while (!isEmpty())
    {
        int u = deleteMin();
        if (visited[u]) continue;
        visited[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (cost[u][v] != INF && !visited[v])
            {
                if (dist[v] > dist[u] + cost[u][v])
                {
                    dist[v] = dist[u] + cost[u][v];
                    parent[v] = u;   // 🔥 track path
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        int w = rand() % 10 + 1;
        cost[i][i + 1] = w;
        cost[i + 1][i] = w;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            if (rand() % 2)
            {
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
    for (int n = 10; n <= 500; n += 10)
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