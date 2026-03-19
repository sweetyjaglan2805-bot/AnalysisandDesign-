#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
int partition(int arr[], int low, int high)
{
    int x = arr[low];
    int i = low;
    int j = high + 1;

    do {
        do { i++; } while (i <= high && arr[i] < x);
        do { j--; } while (arr[j] > x);

        if (i < j)
            swap(arr[i], arr[j]);
    } while (i <= j);

    arr[low] = arr[j];
    arr[j] = x;
    return j;
}
int quickSelect(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k - 1)
            return arr[pivotIndex];
        else if (pivotIndex > k - 1)
            return quickSelect(arr, low, pivotIndex - 1, k);
        else
            return quickSelect(arr, pivotIndex + 1, high, k);
    }
    return -1;
}
double measureExecutionTime(int original[], int n, int k, int &result)
{
    int temp[n];

    clock_t start = clock();

    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < n; j++)
            temp[j] = original[j];

        result = quickSelect(temp, 0, n - 1, k);
    }

    clock_t end = clock();

    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds*1000000000.0;
}

int main()
{
    srand(time(0));

    ofstream txt("kthsmallest_txt.txt");
    ofstream csv("kthsmallest_csv.txt");

    txt << left << setw(10) << "Size"
        << setw(10) << "k"
        << setw(20) << "kth Element"
        << setw(15) << "Time(sec)\n";

    csv << "Size,k,kth Element,Time(sec)\n";

    for (int n = 5; n <= 100; n += 5)
    {
        cout << "Array Size = " << n << "\n";
        int arr[n];
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 100 + 1;

        cout << "Array: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        int k = rand() % n + 1;
        cout << "Generated k = " << k << endl;
        int result;
        double timeTaken = measureExecutionTime(arr, n, k, result);

        cout << k << "th smallest element = " << result << endl;
        cout << "Execution Time = " << timeTaken << " seconds\n";
        txt << setw(10) << n
            << setw(10) << k
            << setw(20) << result
            << setw(15) << timeTaken << "\n";
        csv << n << "," << k << "," << result << "," << timeTaken << "\n";
    }

    txt.close();
    csv.close();

    cout << "\nResults saved to quickselect_results.txt and quickselect_results.csv\n";

    return 0;
}