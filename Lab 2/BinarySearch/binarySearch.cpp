#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int recursiveBinarySearch(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return recursiveBinarySearch(arr, mid + 1, high, key);
    else
        return recursiveBinarySearch(arr, low, mid - 1, key);
}

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

void generateCoefficients(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

double measureTime(int arr[], int n, int key)
{
    clock_t start = clock();
    for (int i = 0; i < 2000000; i++)
        recursiveBinarySearch(arr, 0, n - 1, key);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC * 1e9;
}

int main()
{
    const int MAX = 500;
    srand(time(NULL));
    ofstream txtFile("binary_table.txt");
    ofstream csvFile("binary_csv.txt");
    txtFile << "N\tTime (ns)\n";
    csvFile << "N,Time\n";

    for (int n = 10; n <= 500; n += 10)
    {
        int arr[MAX];

        cout << "Array Size: " << n << endl;

        generateCoefficients(arr, n);
        cout << "Generated (Unsorted) Array:\n";
        printArray(arr, n);

        insertionSort(arr, n);
        cout << "Sorted Array:\n";
        printArray(arr, n);

        int key = arr[rand() % n];
        cout << "Target Element: " << key << endl;

        double time = measureTime(arr, n, key);

        int index = recursiveBinarySearch(arr, 0, n - 1, key);
        cout << "Found at index: " << index << endl;
        cout << "Execution Time (ns): " << time << endl;

        txtFile << n << "\t" << time << "\n";
        csvFile << n << "," << time << "\n";
    }

    txtFile.close();
    csvFile.close();
    return 0;
}





