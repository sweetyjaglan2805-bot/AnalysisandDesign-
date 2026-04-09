#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
#define MAX 10000
struct Edge {
    int u, v, cost;
};
Edge E[MAX];
Edge t[MAX];
int parent[MAX];
int Find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void Union(int i, int j) {
    parent[i] = j;
}
void heapify(Edge E[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && E[left].cost < E[smallest].cost)
        smallest = left;
    if (right < n && E[right].cost < E[smallest].cost)
        smallest = right;
    if (smallest != i) {
        swap(E[i], E[smallest]);
        heapify(E, n, smallest);
    }
}
void Heapify(Edge E[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(E, n, i);
}
Edge DeleteMin(Edge E[], int &n) {
    Edge minEdge = E[0];
    E[0] = E[n-1];
    n--;
    heapify(E, n, 0);
    return minEdge;
}
int Kruskal(int n, int e) {
    int i = 0;
    int mincost = 0;
    for (int j = 0; j < n; j++)
        parent[j] = j;
    Heapify(E, e);
    while ((i < n - 1) && (e > 0)) {
        Edge edge = DeleteMin(E, e);
        int j = Find(edge.u);
        int k = Find(edge.v);
        if (j != k) {
            t[i++] = edge;
            mincost += edge.cost;
            Union(j, k);
        }
    }
    if (i != n - 1)
        return -1;
    return mincost;
}
int generateGraph(int n) {
    int e = 0;
    for (int i = 0; i < n - 1; i++) {
        E[e++] = {i, i + 1, rand() % 10 + 1};
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            if (rand() % 2) {
                E[e++] = {i, j, rand() % 20 + 1};
            }
        }
    }
    return e;
}
double measureTime(int n, int e) {
    clock_t start = clock();
    
    for(int i = 0; i < 1000; i++) {
       Kruskal(n, e);
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC * 1e9;
}

int main() {
    srand(time(0));
    ofstream txtFile("kruskal_txt.txt");
    ofstream csvFile("kruskal_csv.txt");
    txtFile << "Vertex\tMinimunCost\tExecution Time(ns)\n";
    csvFile << "Vertex,Time\n";
    for (int i = 5; i <= 100; i += 1) {
        cout << "\nNo of vertices: " << i << endl;
        int e = generateGraph(i);
        int mincost;
        double timeTaken = measureTime(i, e);
        cout << "Minimum cost = " << mincost << endl;
        cout << "Execution Time = " << timeTaken << " ns\n";
        txtFile << i << "\t" << mincost<<"\t"<< timeTaken << endl;
        csvFile << i << "," << timeTaken << endl;
    }
    txtFile.close();
    csvFile.close();
    return 0;
}