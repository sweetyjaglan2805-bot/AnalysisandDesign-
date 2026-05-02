#include <iostream>
#include <cmath>
using namespace std;
#define MAX 20
int x[MAX];
int n;
bool place(int k, int i){
    for (int j = 1; j < k; j++){
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}
void printMatrix(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (x[i] == j){
                cout << "1 ";}
            else 
                cout << "0 ";    }
        cout << endl;
    }
    cout << endl;
}
void NQ(int k){
    for (int i = 1; i <= n; i++){
        if (place(k, i)){
            x[k] = i;
            if (k == n){
                cout << "Solution:\n";
                printMatrix();
            }
            else{
                NQ(k + 1);     }
        }
    }
}
int main(){
    cout << "Enter number of queens: ";
    cin >> n;
    NQ(1);
    return 0;
}