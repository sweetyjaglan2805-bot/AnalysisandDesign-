#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}
// Recursive sum
int recursiveSum(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}
// Measure execution time
double measureTime(int arr[], int n, int &sum) {
    clock_t start = clock();
       for (int i = 0; i < 100000; i++) {
       sum = recursiveSum(arr, n);
    }
    clock_t end = clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds * 1000000000.0; // nanoseconds
}

int main() {
    const int TESTS = 10;
    srand(time(0));

    int arr[10000];

    ofstream tablefile("sum_table.txt");
    ofstream csvFile("sum_csv.txt");
    if (!tablefile || !csvFile) {
        cout << "Error creating sum.txt file!" << endl;
        return 1;
    }
    tablefile << "Test No\tArray Size\tSum\tExecution Time (ns)\n";
    tablefile << "-----------------------------------------------\n";
    csvFile << "Test,ArraySize,Sum,Time\n";
    for (int i = 1; i <= TESTS; i++) {
        int n = rand() % 10000 + 1;
        generateArray(arr, n);

        cout << "\n------------------------------------\n";
        cout << "Test Case: " << i << endl;
        cout << "Array Size: " << n << endl;
        cout << "Array Elements: ";

        for (int j = 0; j < n; j++) {
            cout << arr[j] << " ";
        }

        int sum;
        double timeTaken = measureTime(arr, n, sum);

        cout << "\nSum of Elements: " << sum;
        cout << "\nExecution Time: " << fixed << timeTaken << " ns\n";
        cout << "------------------------------------\n";
        csvFile << i << "," << n << "," << sum << "," <<fixed<< timeTaken << "\n";
        tablefile << i << "\t\t"
             << n << "\t\t"
             << sum << "\t"
             << fixed << timeTaken << "\n";
    }
    tablefile.close();
    csvFile.close();
    cout << "\nResults saved in sum.txt\n";
    return 0;
}
