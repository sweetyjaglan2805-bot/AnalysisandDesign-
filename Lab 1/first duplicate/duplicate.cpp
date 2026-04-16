#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int MAX = 10000;

int firstDuplicate(int arr[], int n)
{
    int visited[MAX] = {0}; 
    for (int i = 0; i < n; i++)
    {
        if (visited[arr[i]] == 1)
            return arr[i];

        visited[arr[i]] = 1;
    }
    return -1;
}

double measureTime(int arr[], int n, int &result)
{
    clock_t start = clock();
    for (int i = 0; i < 100000; i++){
        result = firstDuplicate(arr, n); }
    clock_t end = clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds * 1000000000.0; 
}

void generateArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100 + 1; 
}
int main()
{
    int arr[MAX];
    int result;
    double time_taken;
    srand(time(0));
    ofstream txtfile("duplicate_table.txt");
    ofstream csvfile("duplicate_csv.txt");
    txtfile << "Size\tResult\tTime\n";
    csvfile << "Size,Time\n";
    for (int n = 10; n <= 500; n += 5)
    {
        generateArray(arr, n);
        time_taken = measureTime(arr, n, result);
        cout << "Array Size: " << n << endl;
        cout << "Array: ";
         for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
        cout << endl;
        if (result == -1)
            cout << "No duplicate found\n";
        else
            cout << "First Duplicate: " << result << endl;

        cout << "Execution Time: " << time_taken << " ns\n";
        txtfile << n << "\t" << result << "\t" << time_taken << endl;
        csvfile << n << "," << time_taken << endl;
    }
    txtfile.close();
    csvfile.close();
    return 0;
}