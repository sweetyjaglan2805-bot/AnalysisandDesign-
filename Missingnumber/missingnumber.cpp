
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int MAX_SIZE = 10000;

int findMissing(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int lsb1 = arr[i] & 1;
        int lsb2 = arr[i + 1] & 1;

        if (lsb1 == lsb2)
        {
            if (n == 2)
                return arr[i] ^ arr[i + 1];
            else
                return arr[i] ^ 1;
        }
    }
    return -1;
}
void generateArray(int arr[], int &actualSize, int &missingValue, int totalSize)
{
    int start = rand() % 1000 + 1;
    int missingIndex = rand() % totalSize;

    actualSize = 0;

    for (int i = 0; i < totalSize; i++)
    {
        if (i != missingIndex)
            arr[actualSize++] = start + i;
        else
            missingValue = start + i;
    }
}
double measureTime(int arr[], int n, int &foundMissing)
{
    clock_t start = clock();
    for (int i = 0; i < 100000; i++)
        foundMissing = findMissing(arr, n);
    clock_t end = clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds*1000000000.0;
}

int main()
{
    srand(time(0));

    int arr[MAX_SIZE];

    ofstream txtfile("missingnumber_table.txt");
    ofstream csvfile("missing_csv.txt");

    txtfile << "ArraySize\tMissing\tTime\n";
    csvfile << "ArraySize,Missing,Time\n";

    for (int size = 10; size <= 500; size += 10)
    {
        int actualSize;
        int expectedMissing;

        generateArray(arr, actualSize, expectedMissing, size);
        cout << "Array size: " << actualSize << endl;
        cout << "Generated numbers:\n";

        for (int i = 0; i < actualSize; i++)
            cout << arr[i] << " ";
        cout << endl;
        double totalTime = 0;
        int foundMissing;
        for (int r = 0; r < 10; r++)
        {
            totalTime += measureTime(arr, actualSize, foundMissing);
        }

        double avgTime = totalTime / 10;
        // double timeTaken = measureTime(arr, actualSize, foundMissing);

        cout << "Missing number: " << foundMissing << endl;
        cout << "Execution time: " << avgTime << " ns"<<endl;
        txtfile << actualSize << "\t\t"<< foundMissing << "\t\t"<< avgTime << "\n";
        csvfile << actualSize << "," << foundMissing << ","<< avgTime << "\n";
    }
    txtfile.close();
    csvfile.close();
    cout << "\nResults saved in missingnumber.txt and missingnumber.csv\n";
    return 0;
}
