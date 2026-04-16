#include<iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;
const int MAX = 50;
int s[MAX][MAX];
void printparenthesis(int s[][MAX], int i, int j){
     if(i == j){
        cout << "A" << i << " ";
    }
    else{
        cout << "(";
        printparenthesis(s, i, s[i][j]);
        printparenthesis(s, s[i][j] + 1, j);
        cout << ")";
    }
}
void printminscaler(int n, int m[][MAX]){
    cout << "\nScaler Multiplication matrix\n";
    for(int i = n; i >= 1; i--){   
        for(int j = 1; j <= n; j++){ 
            if(i == j){
                cout << "0\t";
            }
            else if(i > j){
                cout << m[j][i] << "\t";
            }
            else{
                cout << "-\t";
            }
        }
        cout << endl;
    }
}
void printsplit(int n, int s[][MAX]){
    cout << "\nSplit around vertex \n";
    for(int i = n; i > 1; i--){   
        for(int j = 1; j <= n-1; j++){ 
            if(i == j){
                cout << "-\t";
            }
            else if(i > j){
                cout << s[j][i] << "\t";
            }
            else{
                cout << "-\t";
            }
        }
        cout << endl;
    }
}
int matrixchain(int n, int p[]){
    int m[MAX][MAX];
    // int s[MAX][MAX];
    for(int i=1; i<=n; i++){
        m[i][i] = 0;
    }
    for(int l=2; l<=n; l++){
        for( int i=1; i<=(n-l+1); i++){
           int j = i+l-1;
           m[i][j] = INT_MAX ;
           
           for( int k=i; k<=j-1; k++){
            int q;
            q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
            if( q < m[i][j]){
                m[i][j] = q;
                s[i][j] = k;
                }
            }
        // cout<<"m = "<<m[i][j]<<"  ";
        // cout<<"s = "<<s[i][j]<<endl;
        }
    }
    // printminscaler(n,m);
    // printsplit(n,s);
    // cout << "\nOptimal Parenthesis: ";
    // printparenthesis(s, 1, n);
    // cout << endl;
    return m[1][n];
 }
 double measureTime(int n, int p[], int &result) {
    clock_t start = clock();
    for(int i = 0; i < 100000; i++) {
        result = matrixchain(n, p);
    }
    clock_t end = clock();
    double seconds = (end - start) / CLOCKS_PER_SEC * 1e9;
    return seconds;
}
int main(){
    srand(time(0));
    ofstream txtFile("matrixchain_table.txt");
    ofstream csvFile("matrixchain_csv.txt");
    txtFile << "N\tMinCost\tTime(ns)\n";
    csvFile << "N,Time\n";
    for(int n = 5; n <= 50; n += 2){
        int p[MAX];
        for(int i = 0; i < MAX; i++){
    for(int j = 0; j < MAX; j++){
        s[i][j] = 0;
    }
}
        cout << "\nNumber of Matrices: " << n << endl;

        cout << "Order of matrices: ";
        for(int i = 0; i <= n; i++){
            p[i] = rand() % 50 + 1;
            cout << p[i] << " ";
        }
        cout << endl;
        int minCost = 0;
        double time = measureTime(n, p, minCost);
        // minCost = matrixchain(n, p);
        cout << "Minimum number of scaler multiplication: " << minCost << endl;
        cout << "Execution Time(ns): " << time << endl;
        cout << "Optimal Parenthesis: ";
        printparenthesis(s, 1, n);
        cout << endl;
        txtFile << n << "\t" << minCost << "\t" << time << "\n";
        csvFile << n << "," << time << "\n";
    }
    txtFile.close();
    csvFile.close();
    return 0;
}