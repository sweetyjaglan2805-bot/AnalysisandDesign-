#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

void printCombinations(int pos, int n, string current) {
    if (pos == n) {
        cout << current << endl;
        return;
    }
    printCombinations(pos + 1, n, current + 'T');
    printCombinations(pos + 1, n, current + 'F');
}

void generateForTiming(int pos, int n) {
    if (pos == n)
        return;
    generateForTiming(pos + 1, n);
    generateForTiming(pos + 1, n);
}

// Average timing for smooth graph
double measureExecutionTime(int n, int runs = 5) {
    double total = 0;
    for (int i = 0; i < runs; i++) {
        clock_t start = clock();
        generateForTiming(0, n);
        clock_t end = clock();
        total += double(end - start) / CLOCKS_PER_SEC;
    }
    return (total / runs) * 1e9; // ns
}

int main() {
    ofstream tablefile("truth_table.txt");
    ofstream csvFile("truth_csv.txt");

    if (!tablefile || !csvFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    tablefile << "Test No\tInput (n)\tCombinations (2^n)\tExecution Time (ns)\n";
    tablefile << "-------------------------------------------------------------\n";
    csvFile << "Test,Input,Combinations,Time\n";

    // ASCENDING INPUTS (smooth graph)
    for (int test = 1; test <= 25; test++) {
        int n = test;   // no randomness

        cout << "----------------------------------\n";
        cout << "Test Case " << test << endl;
        cout << "Input (n): " << n << endl;

        if (n <= 5)  // printing small only
            printCombinations(0, n, "");

        double execTime = measureExecutionTime(n);

        long long combinations = 1LL << n;

        cout << "Execution Time: " << execTime << " ns\n";

        tablefile << test << "\t\t"
                  << n << "\t\t"
                  << combinations << "\t\t\t"
                  << fixed << execTime << "\n";

        csvFile << test << ","
                << n << ","
                << combinations << ","
                << execTime << "\n";
    }

    tablefile.close();
    csvFile.close();
    cout << "\nExecution time table saved in truth_table.txt\n";
    return 0;
}


