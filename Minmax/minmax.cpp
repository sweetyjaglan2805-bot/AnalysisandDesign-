#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
#define MAX 1000
void findminmax(int arr[], int low, int high, int &min, int &max)
{
    if(low == high){
        min = max = arr[low];
    }
    else if(low == high - 1){
        if(arr[low] < arr[high]){
            min = arr[low];
            max = arr[high];
        }
        else{
            min = arr[high];
            max = arr[low];
        }
    }
    else{
        int mid = (low + high) / 2;

        int min1, max1;

        findminmax(arr, low, mid, min, max);
        findminmax(arr, mid + 1, high, min1, max1);

        if(max < max1)
            max = max1;

        if(min > min1)
            min = min1;
    }
}
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
double measureTime(int arr[], int n)
{
    clock_t start = clock();
    for(int i = 0; i < 10000; i++) {
        int min, max;
        findminmax(arr, 0, n-1, min, max);
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC * 1e9;
}
int main()
{
    srand(time(0));
    ofstream txtFile("minmax_txt.txt");
    ofstream csvFile("minmax_csv.txt");
    txtFile << "Size\tExecution Time(ns)\n";
    csvFile << "N,Time\n";
    for(int n = 5; n <= 1000; n += 5)
    {
        int arr[MAX];
        cout << "\nArray Size: " << n << endl;
      for(int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
        cout << "Generated Array:\n";
        printArray(arr, n);
        double time = measureTime(arr, n);
        int min, max;
        findminmax(arr, 0, n-1, min, max);
        cout << "Minimum: " << min << endl;
        cout << "Maximum: " << max << endl;
        cout << "Execution Time (ns): " << time << endl;
        txtFile << n << "\t" << time << "\n";
        csvFile << n << "," << time << "\n";
    }
    txtFile.close();
    csvFile.close();
    return 0;
}