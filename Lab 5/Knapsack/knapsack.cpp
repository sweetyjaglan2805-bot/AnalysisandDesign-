#include<iostream>
#include<iomanip>
#include<fstream>
#include<ctime>
using namespace std;
int partitionWeight(float arr[][3], int low, int high){
    float pivot = arr[high][0];
    int i = low - 1;

    for(int j=low; j<high; j++){
        if(arr[j][0] < pivot){
            i++;
            for(int k=0;k<3;k++)
                swap(arr[i][k], arr[j][k]);
        }
    }
    for(int k=0;k<3;k++)
        swap(arr[i+1][k], arr[high][k]);
    return i+1;
}

void quickSortWeight(float arr[][3], int low, int high){
    if(low < high){
        int pi = partitionWeight(arr, low, high);
        quickSortWeight(arr, low, pi-1);
        quickSortWeight(arr, pi+1, high);
    }
}
int partitionProfit(float arr[][3], int low, int high){
    float pivot = arr[high][1];
    int i = low - 1;

    for(int j=low; j<high; j++){
        if(arr[j][1] > pivot){
            i++;
            for(int k=0;k<3;k++)
                swap(arr[i][k], arr[j][k]);
        }
    }
    for(int k=0;k<3;k++)
        swap(arr[i+1][k], arr[high][k]);
    return i+1;
}

void quickSortProfit(float arr[][3], int low, int high){
    if(low < high){
        int pi = partitionProfit(arr, low, high);
        quickSortProfit(arr, low, pi-1);
        quickSortProfit(arr, pi+1, high);
    }
}
int partitionRatio(float arr[][3], int low, int high){
    float pivot = arr[high][2];
    int i = low - 1;

    for(int j=low; j<high; j++){
        if(arr[j][2] > pivot){
            i++;
            for(int k=0;k<3;k++)
                swap(arr[i][k], arr[j][k]);
        }
    }
    for(int k=0;k<3;k++)
        swap(arr[i+1][k], arr[high][k]);
    return i+1;
}

void quickSortRatio(float arr[][3], int low, int high){
    if(low < high){
        int pi = partitionRatio(arr, low, high);
        quickSortRatio(arr, low, pi-1);
        quickSortRatio(arr, pi+1, high);
    }
}
float knapsack(float arr[][3], int n, float capacity){
    float totalProfit = 0;

    for(int i=0;i<n;i++){
        if(capacity >= arr[i][0]){
            totalProfit += arr[i][1];
            capacity -= arr[i][0];
        }
        else{
            totalProfit += arr[i][1]*(capacity/arr[i][0]);
            break;
        }
    }
    return totalProfit;
}
double measureWeightTime(float arr[][3], int n, float capacity){
    clock_t start = clock();
    float profit;

    for(int i=0;i<10000;i++){
        quickSortWeight(arr,0,n-1);
        profit = knapsack(arr,n,capacity);
    }

    clock_t end = clock();
    return double(end-start)/CLOCKS_PER_SEC;
}

double measureProfitTime(float arr[][3], int n, float capacity){
    clock_t start = clock();
    float profit;

    for(int i=0;i<10000;i++){
        quickSortProfit(arr,0,n-1);
        profit = knapsack(arr,n,capacity);
    }

    clock_t end = clock();
    return double(end-start)/CLOCKS_PER_SEC;
}

double measureRatioTime(float arr[][3], int n, float capacity){
    clock_t start = clock();
    float profit;

    for(int i=0;i<10000;i++){
        quickSortRatio(arr,0,n-1);
        profit = knapsack(arr,n,capacity);
    }

    clock_t end = clock();
    return double(end-start)/CLOCKS_PER_SEC;
}
void printArray(float arr[][3], int n){
    cout<<"Weight\tProfit\tRatio\n";
    for(int i=0;i<n;i++)
        cout<<arr[i][0]<<"\t"
            <<arr[i][1]<<"\t"
            <<fixed<<setprecision(2)<<arr[i][2]<<endl;
}
int main(){

    srand(time(0));

    ofstream txt("knap_txt.txt");
    ofstream csv("knap_csv.txt");

    txt<<left<<setw(8)<<"Size"
       <<setw(12)<<"Method"
       <<setw(15)<<"Time(sec)\n";

    csv<<"Size,Method,Time(sec)\n";

    for(int n=5; n<=50; n+=5){
        cout<<"SIZE = "<<n<<endl;
        float capacity = rand()%100 + 50;
        cout<<"Generated Capacity = "<<capacity<<"\n\n";
        float original[n][3];

        for(int i=0;i<n;i++){
            original[i][0] = rand()%100 + 1;
            original[i][1] = rand()%100 + 1;
            original[i][2] = original[i][1]/original[i][0];
        }

        printArray(original,n);

        float arrWeight[n][3];
        float arrProfit[n][3];
        float arrRatio[n][3];

        for(int i=0;i<n;i++)
            for(int j=0;j<3;j++){
                arrWeight[i][j]=original[i][j];
                arrProfit[i][j]=original[i][j];
                arrRatio[i][j]=original[i][j];
            }

        double tw = measureWeightTime(arrWeight,n,capacity);
        double tp = measureProfitTime(arrProfit,n,capacity);
        double tr = measureRatioTime(arrRatio,n,capacity);

        cout<<"\nExecution Time (seconds):\n";
        cout<<"Weight : "<<tw<<"\n";
        cout<<"Profit : "<<tp<<"\n";
        cout<<"Ratio  : "<<tr<<"\n";

        txt<<setw(8)<<n<<setw(12)<<"Weight"<<setw(15)<<tw<<"\n";
        txt<<setw(8)<<n<<setw(12)<<"Profit"<<setw(15)<<tp<<"\n";
        txt<<setw(8)<<n<<setw(12)<<"Ratio"<<setw(15)<<tr<<"\n";

        csv<<n<<",Weight,"<<tw<<"\n";
        csv<<n<<",Profit,"<<tp<<"\n";
        csv<<n<<",Ratio,"<<tr<<"\n";
    }
    txt.close();
    csv.close();
    cout<<"\nResults saved to results.txt and results.csv\n";
}
