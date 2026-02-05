// #include <iostream>
// #include <fstream>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// // Recursive Tower of Hanoi
// void towerOfHanoi(int n, char source, char destination, char auxiliary)
// {
//     if (n == 1)
//     {
//         cout << "Move disk 1 from " << source << " to " << destination << endl;
//         return;
//     }
//     towerOfHanoi(n - 1, source, auxiliary, destination);
//     cout << "Move disk " << n << " from " << source << " to " << destination << endl;
//     towerOfHanoi(n - 1, auxiliary, destination, source);
// }

// // Measure execution time
// double measureTime(int n)
// {
//     clock_t start = clock();
//     towerOfHanoi(n, 'A', 'B', 'C');  // print moves to console
//     clock_t end = clock();

//     double seconds = double(end - start) / CLOCKS_PER_SEC;
//     return seconds * 1000000000.0; // nanoseconds
// }

// int main()
// {
//     const int TESTS = 10;
//     srand(time(NULL));

//     ofstream file("towerofhanoi.txt");
//     if (!file) {
//         cout << "Error creating towerofhanoi.txt file!" << endl;
//         return 1;
//     }

//     file << "Test No\tNumber of Disks\tExecution Time (ns)\n";
//     file << "----------------------------------------------\n";

//     for (int i = 1; i <= TESTS; i++)
//     {
//         int n = rand() % 10 + 1;  // 1 to 10 disks

//         cout << "\n----------------------------------------\n";
//         cout << "Test Case: " << i << endl;
//         cout << "Number of Disks: " << n << endl;
//         cout << "Moves: \n";

//         double timeTaken = measureTime(n);

//         cout << "\nExecution Time: " << fixed << timeTaken << " ns\n";
//         cout << "----------------------------------------\n";

//         // File output (summary only)
//         file << i << "\t\t" << n << "\t\t" << fixed << timeTaken << "\n";
//     }

//     file.close();

//     cout << "\nResults saved in towerofhanoi.txt\n";
//     return 0;
// }
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
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
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
    const int TESTS = 10;
    srand(time(NULL));

    ofstream file("tower_table.txt");
    ofstream csvFile("tower_csv.txt");   // CSV added

    if (!file || !csvFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    file << "Test No\tNumber of Disks\tExecution Time (ns)\n";
    file << "----------------------------------------------\n";

    csvFile << "Test,Disks,Time_ns\n";   // CSV header

    for (int i = 1; i <= TESTS; i++)
    {
        int n = rand() % 10 + 1;  // 1 to 10 disks

        cout << "\n----------------------------------------\n";
        cout << "Test Case: " << i << endl;
        cout << "Number of Disks: " << n << endl;
        cout << "Moves: \n";

        double timeTaken = measureTime(n);

        cout << "\nExecution Time: " << fixed << timeTaken << " ns\n";
        cout << "----------------------------------------\n";

        // TXT output
        file << i << "\t\t" << n << "\t\t" << fixed << timeTaken << "\n";

        // CSV output (new)
        csvFile << i << "," << n << "," << timeTaken << "\n";
    }

    file.close();
    csvFile.close();

    cout << "\nResults saved in towerofhanoi.txt and towerofhanoi.csv\n";
    return 0;
}

