#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Copy array
void copyArray(int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

// Measure time
double measureTime(int arr[], int n)
{
    clock_t start = clock();
    insertionSort(arr, n);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC * 1e9;
}

int main()
{
    const int TESTS = 10;
    const int MAX = 5000;

    int n_values[TESTS];
    double best_time[TESTS];
    double avg_time[TESTS];

    srand(time(NULL));

    ofstream txtFile("insertion_table.txt");
    ofstream csvFile("insertion_csv.txt");

    txtFile << "N\tBest Case (ns)\tAverage Case (ns)\n";
    csvFile << "N,Best,Average\n";

    for (int i = 0; i < TESTS; i++)
    {
        int n = (i + 1) * 500;   // increasing input size
        n_values[i] = n;

        int arr[MAX];
        int temp[MAX];

        // Generate random array (average case)
        for (int j = 0; j < n; j++)
            arr[j] = rand() % 10000;

        // Average case
        copyArray(arr, temp, n);
        avg_time[i] = measureTime(temp, n);

        // Best case (already sorted)
        insertionSort(arr, n);
        copyArray(arr, temp, n);
        best_time[i] = measureTime(temp, n);

        // Print to console
        cout << n << "\t" << best_time[i] << "\t" << avg_time[i] << endl;

        // Save to files
        txtFile << n << "\t" << best_time[i] << "\t" << avg_time[i] << "\n";
        csvFile << n << "," << best_time[i] << "," << avg_time[i] << "\n";
    }

    txtFile.close();
    csvFile.close();

    cout << "\nData saved to insertion_table.txt and insertion_sort.csv\n";
    return 0;
}
