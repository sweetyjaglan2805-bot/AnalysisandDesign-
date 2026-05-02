#include<iostream>
using namespace std;
#define MAX 20
int G[MAX][MAX];   
int x[MAX];        
int n;             
bool place(int k, int v){
    if (G[x[k-1]][v] == 0) // check graph is connected 
        return false;
    for (int j = 1; j < k; j++){
        if (x[j] == v)
            return false;
    }
    if (k == n && G[v][x[1]] == 0)
        return false;
    return true;
}
void hamiltonian(int k){
    for (int v = 2; v <= n; v++){   
        if (place(k, v)){
            x[k] = v;
            if (k == n){
                cout << "Solution: ";
                for (int i = 1; i <= n; i++)
                    cout << x[i] << " ";
                cout << x[1] << endl; 
            }
            else{
                hamiltonian(k + 1);
            }
        }
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> G[i][j];
        }
    }
    x[1] = 1;   
    hamiltonian(2);
    return 0;
}