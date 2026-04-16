#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define MAX 1000
int temp[MAX];
void merge(int arr[], int low, int mid, int high)
{
    int h = low;
    int j = mid + 1;
    int i = low;

    while (h <= mid && j <= high)
    {
        if (arr[h] <= arr[j])
            temp[i++] = arr[h++];
        else
            temp[i++] = arr[j++];
    }

    while (h <= mid)
        temp[i++] = arr[h++];

    while (j <= high)
        temp[i++] = arr[j++];

    for (int k = low; k <= high; k++)
        arr[k] = temp[k];
}
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
        int tempArr[MAX];
        for(int j = 0; j < n; j++)
            tempArr[j] = arr[j];   
        mergeSort(tempArr, 0, n-1);
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC * 1e9;
}

int main()
{
    srand(time(0));
    ofstream txtFile("merge_txt.txt");
    ofstream csvFile("merge_csv.txt");
    txtFile << "Size\tExecution Time(ns)\n";
    csvFile << "N,Time\n";
    for (int n = 5; n <= 1000; n += 5)
    {
        int arr[MAX];
        cout << "\nArray Size: " << n << endl;
       for(int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
        cout << "Generated Array:\n";
        printArray(arr, n);
        double time = measureTime(arr, n);
        mergeSort(arr, 0, n-1);
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
