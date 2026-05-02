#include <iostream>
using namespace std;
#define MAX 1000
#define MAXN 100
struct PW {
    int p, w;
};
PW S[MAXN + 1][MAX];   
int size[MAXN + 1];    
int p[MAXN + 1], w[MAXN + 1];
int x[MAXN + 1]; 
void mergeSets(int i, int W){
    int idx = 0;
    for (int j = 0; j < size[i - 1]; j++) {
        S[i][idx++] = S[i - 1][j];
    }
    for (int j = 0; j < size[i - 1]; j++){
        int newp = S[i - 1][j].p + p[i];
        int neww = S[i - 1][j].w + w[i];
        if (neww <= W){
            S[i][idx].p = newp;
            S[i][idx].w = neww;
            idx++;
        }
    }
    size[i] = idx;
}
bool exists(int i, int pp, int ww){
    for (int j = 0; j < size[i]; j++){
        if (S[i][j].p == pp && S[i][j].w == ww)
            return true;
    }
    return false;
}
void TraceBack(int n, int pp, int ww){
    if (n == 0)
        return;
    if (!exists(n - 1, pp, ww)){
        x[n] = 1;
        TraceBack(n - 1, pp - p[n], ww - w[n]);
    }
    else{
        x[n] = 0;
        TraceBack(n - 1, pp, ww);
    }
}
int main(){
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity: ";
    cin >> W;
    for (int i = 1; i <= n; i++){
        cout << "Enter profit and weight of item " << i << ": ";
        cin >> p[i] >> w[i];
    }
    S[0][0].p = 0;
    S[0][0].w = 0;
    size[0] = 1;
    for (int i = 1; i <= n; i++){
        mergeSets(i, W);
    }
    int maxProfit = 0, bestW = 0;
    for (int j = 0; j < size[n]; j++){
        if (S[n][j].p > maxProfit){
            maxProfit = S[n][j].p;
            bestW = S[n][j].w;
        }
    }
    cout << "\nMaximum Profit: " << maxProfit << endl;
    TraceBack(n, maxProfit, bestW);
    cout << "Selected items:\n";
    for (int i = 1; i <= n; i++){
        if (x[i] == 1)
            cout << "Item " << i << " ";
    }
    return 0;
}