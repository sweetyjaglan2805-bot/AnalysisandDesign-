#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
#define MAX 100
#define INF INT_MAX
int prim(int cost[MAX][MAX], int n) {
    int t[MAX][2], near[MAX];
    int mincost = 0;
    int i, j, k, l;
    int min = INF;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }
    t[0][0] = k;
    t[0][1] = l;
    mincost = cost[k][l];
    for (i = 0; i < n; i++) {
        if (cost[i][l] < cost[i][k])
            near[i] = l;
        else
            near[i] = k;
    }
    near[k] = near[l] = -1;
    for (i = 1; i < n - 1; i++) {
        min = INF;

        for (j = 0; j < n; j++) {
            if (near[j] != -1 && cost[j][near[j]] < min) {
                min = cost[j][near[j]];
                k = j;
            }
        }
        t[i][0] = k;
        t[i][1] = near[k];
        mincost += cost[k][near[k]];
        near[k] = -1;
        for (j = 0; j < n; j++) {
            if (near[j] != -1 && cost[j][near[j]] > cost[j][k]) {
                near[j] = k;
            }
        }
    }
    // cout << "Edges in MST:\n";
    // for (i = 0; i < n - 1; i++) {
    //     cout << t[i][0] << " - " << t[i][1] << endl;
    // }
    return mincost;
}
void generateGraph(int adj[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = INF;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int weight = rand() % 10 + 1; 
        adj[i][i + 1] = weight;
        adj[i + 1][i] = weight;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            if (rand() % 2) { 
                int weight = rand() % 20 + 1;
                adj[i][j] = weight;
                adj[j][i] = weight;
            }
        }
    }
}
double measureTime(int adj[MAX][MAX], int n)
{
    clock_t start = clock();

    for(int i = 0; i < 1000; i++) {
       prim(adj, n);
    }
    // prim(adj, n);
    clock_t end = clock();

    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds * 1000000000.0;
}
int main() {
    int n;
    int adj[MAX][MAX];
     srand(time(0));
    ofstream txtFile("prim_txt.txt");
    ofstream csvFile("prim_csv.txt");
    txtFile << "Vertex\tExecution Time(ns)\n";
    csvFile << "Vertex,Time\n";
   for (int i = 5; i<= 100; i=i+2){
    cout<<"\nNo of vertices: "<<i<<endl;  
    generateGraph(adj, i); 
    int mincost = prim(adj, i);
    double timeTaken = measureTime(adj, i);
    cout << "Minimum cost of MST = " << mincost << endl;
    cout << "Execution Time = " << timeTaken << " ns\n";
     txtFile << i << "\t" << mincost << "\t" <<timeTaken<< endl;
        csvFile << i << "," << timeTaken<<endl;
   }
    txtFile.close();
    csvFile.close();
    return 0;
}