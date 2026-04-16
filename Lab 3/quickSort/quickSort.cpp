#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;

int partition(int arr[], int low, int high)
{
    int x = arr[low];
    int i = low;
    int j = high + 1;
    while (true)
    {
        do {
            i++;
        } while (i <= high && arr[i] < x);
        do {
            j--;
        } while (arr[j] > x);
        if (i >= j)
            break;
        swap(arr[i], arr[j]);
    }
    arr[low] = arr[j];
    arr[j] = x;
    return j;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);
        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
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

    for(int i = 0; i < 1000; i++) {
        int temp[1000];
        for(int j = 0; j < n; j++)
            temp[j] = arr[j];   // copy original
        quicksort(temp, 0, n-1);
    }
    clock_t end = clock();

    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds * 1000000000.0;
}
int main()
{
    srand(time(0));
    ofstream txtFile("quick_txt.txt");
    ofstream csvFile("quick_csv.txt");
    txtFile << "Size\tExecution Time(ns)\n";
    csvFile << "N,Time\n";

    for(int n = 5; n <= 1000; n += 5)
    {
        int arr[1000];
        cout << "\nArray Size: " << n << endl;
         for(int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
        cout << "Generated Array:\n";
        printArray(arr, n);

        double time = measureTime(arr, n);

        quicksort(arr, 0, n-1);
        cout << "Sorted Array:\n";
        printArray(arr, n);
        cout << "Execution Time (ns): " << time << endl;
        txtFile << n << "\t" << time << "\n";
        csvFile << n << "," << time << "\n";
    }
    txtFile.close();
    csvFile.close();
    return 0;
}