// #include <iostream>
// #include <fstream>
// #include <cstdlib>
// #include <ctime>
// #include <iomanip>
// using namespace std;
// void generateArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         arr[i] = rand();
//     }
// }
// // Recursive sum
// int recursiveSum(int arr[], int n) {
//     if (n == 0)
//         return 0;
//     return arr[n - 1] + recursiveSum(arr, n - 1);
// }
// // Measure execution time
// double measureTime(int arr[], int n, int &sum) {
//     clock_t start = clock();
//        for (int i = 0; i < 100000; i++) {
//        sum = recursiveSum(arr, n);
//     }
//     clock_t end = clock();
//     double seconds = double(end - start) / CLOCKS_PER_SEC;
//     return seconds * 1000000000.0; // nanoseconds
// }

// int main() {
//     const int TESTS = 10;
//     srand(time(0));

//     int arr[10000];

//     ofstream tablefile("sum_table.txt");
//     ofstream csvFile("sum_csv.txt");
//     if (!tablefile || !csvFile) {
//         cout << "Error creating sum.txt file!" << endl;
//         return 1;
//     }
//     tablefile << "Test No\tArray Size\tSum\tExecution Time (ns)\n";
//     tablefile << "-----------------------------------------------\n";
//     csvFile << "Test,ArraySize,Sum,Time\n";
//     for (int i = 1; i <= TESTS; i++) {
//         int n = rand() % 10000 + 1;
//         generateArray(arr, n);

//         cout << "\n------------------------------------\n";
//         cout << "Test Case: " << i << endl;
//         cout << "Array Size: " << n << endl;
//         cout << "Array Elements: ";

//         for (int j = 0; j < n; j++) {
//             cout << arr[j] << " ";
//         }

//         int sum;
//         double timeTaken = measureTime(arr, n, sum);

//         cout << "\nSum of Elements: " << sum;
//         cout << "\nExecution Time: " << fixed << timeTaken << " ns\n";
//         cout << "------------------------------------\n";
//         csvFile << i << "," << n << "," << sum << "," <<fixed<< timeTaken << "\n";
//         tablefile << i << "\t\t"
//              << n << "\t\t"
//              << sum << "\t"
//              << fixed << timeTaken << "\n";
//     }
//     tablefile.close();
//     csvFile.close();
//     cout << "\nResults saved in sum.txt\n";
//     return 0;
// }
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXSIZE = 150;

// Generate array (same style as before)
void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() / 100;   // same style as your first code
    }
}

// Recursive sum
int recursiveSum(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

// Iterative sum
int iterativeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

// Measure recursive time
double measureRecursiveTime(int arr[], int n, int &sum) {
    clock_t start = clock();
    for (int i = 0; i < 100000; i++) {
        sum = recursiveSum(arr, n);
    }
    clock_t end = clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds * 1000000000.0;
}

// Measure iterative time
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

        // File output
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
