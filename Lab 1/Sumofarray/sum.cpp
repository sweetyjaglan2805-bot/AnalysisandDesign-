
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAXSIZE = 150;
void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() / 100;
    }
}
int recursiveSum(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}
int iterativeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}
double measureRecursiveTime(int arr[], int n, int &sum) {
    clock_t start = clock();
    for (int i = 0; i < 100000; i++) {
        sum = recursiveSum(arr, n);
    }
    clock_t end = clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds * 1000000000.0;
}
double measureIterativeTime(int arr[], int n, int &sum) {
    clock_t start = clock();
    for (int i = 0; i < 100000; i++) {
        sum = iterativeSum(arr, n);
    }
    clock_t end = clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds * 1000000000.0;
}
int main() {
    srand(time(0));
    int arr[MAXSIZE];
    ofstream tablefile("sum_table.txt");
    ofstream csvFile("sum_csv.txt");
    if (!tablefile || !csvFile) {
        cout << "Error creating files!" << endl;
        return 1;
    }
    tablefile << "ArraySize\tRecursiveSum\tRecursiveTime(ns)\tIterativeSum\tIterativeTime(ns)\n";
    csvFile << "Size,RecSum,RecTime,IterSum,IterTime\n";
    for (int size = 5; size <= 100; size += 5) {
        generateArray(arr, size);
        int recSum, iterSum;
        double recTime = measureRecursiveTime(arr, size, recSum);
        double iterTime = measureIterativeTime(arr, size, iterSum);
        cout << "Array Size: " << size << endl;
        cout << "\nElements in array:\n";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Recursive Sum: " << recSum << endl;
        cout << "Recursive Time: " << recTime << " ns\n";
        cout << "Iterative Sum: " << iterSum << endl;
        cout << "Iterative Time: " << iterTime << " ns\n";
        tablefile << size << "\t\t"
                  << recSum << "\t\t"
                  << recTime << "\t\t"
                  << iterSum << "\t\t"
                  << iterTime << "\n";
        csvFile << size << ","
                << recSum << ","
                << recTime << ","
                << iterSum << ","
                << iterTime << "\n";
    }
    tablefile.close();
    csvFile.close();
    cout << "\nResults saved in sum_table.txt and sum_csv.txt\n";
    return 0;
}
