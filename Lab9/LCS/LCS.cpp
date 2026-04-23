#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
const int MAX = 100;
int c[MAX][MAX];
char p[MAX][MAX];

string generateString(int len){
    string s = "";
    for(int i = 0; i < len; i++){
        char ch = 'a' + rand() % 26; // random lowercase
        s += ch;
    }
    return s;
}
void LCS(string X, string Y, int m, int n){
    for(int i = 0; i <= m; i++){
        c[i][0] = 0; }
    for(int j = 0; j <= n; j++){
        c[0][j] = 0; }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(X[i-1] == Y[j-1]){
                c[i][j] = 1 + c[i-1][j-1];
                p[i][j] = 'd';
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                p[i][j] = 'u';
            }
            else{
                c[i][j] = c[i][j-1];
                p[i][j] = 'l';
            }
        }
    }
}
void printLCS(string X, int i, int j){
    if(i == 0 || j == 0)
        return;
    if(p[i][j] == 'd'){
        printLCS(X, i-1, j-1);
        cout << X[i-1];
    }
    else if(p[i][j] == 'u'){
        printLCS(X, i-1, j);
    }
    else{
        printLCS(X, i, j-1);
    }
}
double measureTime(string X, string Y, int m, int n){
    clock_t start = clock();
    for(int i = 0; i < 1000; i++){  
        LCS(X, Y, m, n);
    }
    clock_t end = clock();
    return ((double)(end - start) / CLOCKS_PER_SEC) * 1e9;
}
int main(){
    srand(time(0));
    ofstream txtFile("LCS_table.txt");
    ofstream csvFile("LCS_csv.txt");
    txtFile << "Length\tTime(ns)\n";
    csvFile << "Length,Time\n";

    for(int len = 5; len <= 80; len += 2){
        int len1 = len;
        int len2 = rand() % len + 1;   
        string X = generateString(len1);
        string Y = generateString(len2);
        int m = X.length();
        int n = Y.length();
        double time = measureTime(X, Y, m, n);
        cout << "\nLength: " << len << endl;
        cout << "String X: " << X << endl;
        cout << "String Y: " << Y << endl;
        LCS(X, Y, m, n);
        cout << "LCS Length: " << c[m][n] << endl;
        cout << "LCS: ";
        printLCS(X, m, n);   
        cout << endl;
        cout << "Execution Time (ns): " << time << endl;
        txtFile << len << "\t" << time << "\n";
        csvFile << len << "," << time << "\n";
    }
    txtFile.close();
    csvFile.close();
    return 0;
}