#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<climits>
using namespace std;
const int MAX = 50;
double infi = (5.0/0.0);
double A[MAX][MAX];
void printmatrix(int n, double cost[][MAX]){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << cost[i][j] << "\t";
        }
        cout << endl;
    }
}
void shortestpath(int n, double cost[][MAX]){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            A[i][j] = cost[i][j];
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(A[i][j] > A[i][k] + A[k][j]){
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }
}
double measureTime(int n, double cost[][MAX]) {
    clock_t start = clock();

    for(int i = 0; i < 1000; i++){
        shortestpath(n, cost);
    }
    clock_t end = clock();
    double time_ns = ((double)(end - start) / CLOCKS_PER_SEC) * 1e9;
    return time_ns;
}
int main(){
    srand(time(0));
    ofstream txtFile("Allpairshortest_table.txt");
    ofstream csvFile("Allpairshortest_csv.txt");
    txtFile << "N\tTime(ns)\n";
    csvFile << "N,Time\n";
    for(int n = 5; n <= 50; n += 2){
        double cost[MAX][MAX];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j)
                    cost[i][j] = 0;
                else
                    cost[i][j] = infi;
            }
        }
        int e = n + rand() % (n * 2);
        for(int i = 1; i <= e; i++){
            int u = rand() % n + 1;
            int v = rand() % n + 1;
            int wt = rand() % 20 + 1;
            if(u != v){
                cost[u][v] = wt;
            }
        }
        cout << "\nVertices: " << n << endl;
        cout << "Adjacency Matrix:\n";
        printmatrix(n, cost);
        double time = measureTime(n, cost);
        shortestpath(n, cost);
        cout << "\nShortest Path Matrix:\n";
        printmatrix(n, A);
        cout << "Execution Time (ns): " << time << endl;
        txtFile << n << "\t" << time << "\n";
        csvFile << n << "," << time << "\n";
    }

    txtFile.close();
    csvFile.close();

    return 0;
}
