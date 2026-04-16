#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;
void generateGraph(int n, int adj[100][100]) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                adj[i][j] = 0;
            else if(j > i && rand() % 2)  
                adj[i][j] = rand() % 9 + 1; 
            else
                adj[i][j] = 0;
        }
    }
}
int calculateStages(int n, int adj[100][100], int stage[100]) {
    for(int i = 1; i <= n; i++)
        stage[i] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(adj[i][j] != 0) {
                if(stage[j] < stage[i] + 1)
                    stage[j] = stage[i] + 1;
            }
        }
    }
    int k = 0;
    for(int i = 1; i <= n; i++)
        if(stage[i] > k)
            k = stage[i];
    return k;
}
//forward approach
void multistageforward(int n, int adj[100][100], int cost[100], int p[100]) {
    for(int i = 1; i <= n; i++) {
        cost[i] = INT_MAX;
        p[i] = -1;
    }
    cost[n] = 0;
    for(int i = n-1; i >= 1; i--) {
        for(int j = i+1; j <= n; j++) {
            if(adj[i][j] != 0 && cost[j] != INT_MAX) {
                if(cost[i] > adj[i][j] + cost[j]) {
                    cost[i] = adj[i][j] + cost[j];
                    p[i] = j;
                }
            }
        }
    }
}
//backward Approacch
void multistagebackward(int n, int adj[100][100], int cost[100], int p[100]) {
    for(int i = 1; i <= n; i++) {
        cost[i] = INT_MAX;
        p[i] = -1;
    }
    cost[1] = 0; 
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(adj[i][j] != 0 && cost[i] != INT_MAX) {
                if(cost[j] > cost[i] + adj[i][j]) {
                    cost[j] = cost[i] + adj[i][j];
                    p[j] = i;  // reverse parent direction
                }
            }
        }
    }
}
double measureTime(int n, int adj[100][100], int cost[100], int p[100]) {
    clock_t start = clock();
    for(int i = 0; i < 10000; i++) {
        multistageforward(n, adj, cost, p);
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC * 1e9;
}
int main() {
    srand(time(0));
    const int MAX = 100;
    ofstream txtFile("multistage_table.txt");
    ofstream csvFile("multistage_csv.txt");
    txtFile << "N\tStages\tDistance\tTime(ns)\n";
    csvFile << "N,Time\n";
    for(int n = 5; n <= 30; n += 1) {
        int adj[100][100], stage[100], cost[100], p[100];
        cout << "Graph with " << n << " vertices: "<<endl;
        generateGraph(n, adj);
        cout << "Adjacency Matrix:\n";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
        // Calculate stages
        int k = calculateStages(n, adj, stage);
        cout << "No of Stages: "<<k<<endl;
        for(int s = 1; s <= k; s++) {
            cout << "Stage " << s << ": ";
            for(int i = 1; i <= n; i++) {
                if(stage[i] == s)
                    cout << i << " ";
            }
            cout << endl;
        }
        double time_ns = measureTime(n, adj, cost, p);
        multistageforward(n, adj, cost, p);
         int d[100]; // path 
        d[1] = 1;
        d[k] = n;
        for(int j = 2; j < k; j++) {
            d[j] = p[d[j-1]];
        }
        cout << "\nShortest Distance: " << cost[1] << endl;
        cout << "Path: ";
        for(int i = 1; i <= k; i++) {
            cout << d[i];
            if(i != k) cout << " -> ";
        }
        cout << endl;
        cout << "Execution Time(ns): " << time_ns << endl;
        txtFile << n << "\t" << k << "\t" << cost[1] << "\t" << time_ns << "\n";
        csvFile << n << "," << time_ns << "\n";
    }
    txtFile.close();
    csvFile.close();
    return 0;
}