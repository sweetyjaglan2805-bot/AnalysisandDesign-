#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Recursive Tower of Hanoi
void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    if (n == 1)
    {
        // cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    // cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Measure execution time
double measureTime(int n)
{
    clock_t start = clock();
    towerOfHanoi(n, 'A', 'B', 'C');  // print moves to console
    clock_t end = clock();

    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds * 1000000000.0; // nanoseconds
}

int main()
{
    ofstream file("tower_table.txt");
    ofstream csvFile("tower_csv.txt");   // CSV added

    if (!file || !csvFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    file << "Number of Disks\tExecution Time (ns)\n";
    csvFile << "Disks,Time_ns\n";   

    for (int size = 3; size <= 30; size += 1)
    {
        int n = size; 
        cout << "Number of Disks: " << n << endl;
        // cout << "Moves: \n";

        double timeTaken = measureTime(n);

        cout << "Execution Time: " << fixed << timeTaken << " ns\n"<<endl;

        // TXT output
        file << n << "\t\t" << fixed << timeTaken << "\n";

        // CSV output (new)
        csvFile << n << "," << timeTaken << "\n";
    }

    file.close();
    csvFile.close();

    cout << "\nResults saved in towerofhanoi.txt and towerofhanoi.csv\n";
    return 0;
}

