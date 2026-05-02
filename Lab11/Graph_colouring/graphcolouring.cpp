#include <iostream>
using namespace std;
#define MAX 20
int n, m;
int G[MAX][MAX];
int x[MAX];
bool place(int k, int i){
    for (int j = 1; j <= n; j++){
        if (G[k][j] == 1 && x[j] == i)
            return false;
    }
    return true;
}
void mcoloring(int k){
    for (int i = 1; i <= m; i++){
        if (place(k, i)){
            x[k] = i;
            if (k == n){
                cout << "Solution:\n";
                for (int j = 1; j <= n; j++){
                    cout << "Vertex " << j << " -> Color " << x[j] << endl;
                }
                cout << endl;
            }
            else{
                mcoloring(k + 1);
            }
        }
    }
}
int main(){
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of colors: ";
    cin >> m;
    cout << "Enter adjacency matrix:\n";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> G[i][j];
        }
    }
    mcoloring(1);
    return 0;
}