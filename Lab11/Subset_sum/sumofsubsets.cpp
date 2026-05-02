#include <iostream>
using namespace std;
#define MAX 50
int w[MAX];     
int x[MAX];     
int n, target;       
void sumofsub(int s, int k, int sum){
    x[k] = 1; 
    if (s + w[k] == target){
        cout << "Solution: ";
        for (int i = 1; i <= k; i++){
            if (x[i] == 1)
                cout << w[i] << " ";
        }
        cout << endl;
    }
    else if (s + w[k] + w[k + 1] <= target){
        sumofsub(s + w[k], k + 1, sum - w[k]);
    }
    if ((s + sum - w[k] >= target) && (s + w[k + 1] <= target)){
        x[k] = 0;
        sumofsub(s, k + 1, sum - w[k]);
    }
}
int main(){
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements (weights in increasing order): ";
    for (int i = 1; i <= n; i++){
        cin >> w[i];}
    cout << "Enter target sum: ";
    cin >> target;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += w[i];  }
    sumofsub(0, 1, sum);
    return 0;
}