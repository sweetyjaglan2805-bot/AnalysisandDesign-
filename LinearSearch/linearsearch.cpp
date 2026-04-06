#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int MAXSIZE = 500;
const int TRIALS = 1000;  

void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;   // 0-99
    }
}
int recursiveLinearSearch(int arr[], int n, int index, int target) {
    if (index == n)
        return -1;
    if (arr[index] == target)
        return index;
    return recursiveLinearSearch(arr, n, index + 1, target);
}

double measureTime(int arr[], int n, int target, int &index) {
    clock_t start = clock();
     for (int i = 0; i < 1000; i++) {
        index = recursiveLinearSearch(arr, n, 0, target);
     }
    clock_t end = clock();

    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds * 1000000000.0;
}

int main() {
    srand(time(0));
    int arr[MAXSIZE];
    ofstream file("linearsearch_table.txt");
    ofstream csvFile("linearsearch_csv.txt");

    file << "Size,Case,Time\n";
    csvFile << "Size,Case,Time\n";
    for (int size = 5; size <= 500; size += 5) {

        generateArray(arr, size);
        int index;
        int worstTarget = arr[size - 1];
        double worstTime = 0;

        for (int i = 0; i < TRIALS; i++) {
            worstTime += measureTime(arr, size, worstTarget, index);
        }
        worstTime /= TRIALS;
        double avgTime = 0;

        for (int i = 0; i < TRIALS; i++) {
            int randomIndex = rand() % size;
            int avgTarget = arr[randomIndex];
            avgTime += measureTime(arr, size, avgTarget, index);
        }
        avgTime /= TRIALS;
        cout << "\n----------------------------------------\n";
        cout << "Array Size: " << size << endl;
        cout << "Array Elements: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
        cout << "Worst Case Target: " << worstTarget << endl;
        cout << "Worst Time: " << worstTime << " ns\n";
        cout << "Average Time: " << avgTime << " ns\n";
        cout << "----------------------------------------\n";
        file << left
                  << setw(10) << size
                  << setw(15) << "Worst"
                  << setw(15) << (size - 1)
                  << setw(20) << worstTime << endl;

        file << left
                  << setw(10) << size
                  << setw(15) << "Average"
                  << setw(15) << "Varies"
                  << setw(20) << avgTime << endl;
        csvFile << size << ",Worst," << worstTime << "\n";
        csvFile << size << ",Average," << avgTime << "\n";
    }

    file.close();
    csvFile.close();

    cout << "\nResults saved in linearsearch_table.txt and linearsearch_csv.txt\n";
    return 0;
}

