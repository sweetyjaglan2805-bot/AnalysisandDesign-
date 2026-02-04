#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
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
double measureExecutionTime(int n) {
    clock_t start = clock();
     for (int i = 0; i < 100000; i++) {
       generateForTiming(0, n);
    }
    clock_t end = clock();
 double seconds = double(end - start) / CLOCKS_PER_SEC;
      return seconds* 1000000000.0;
}

int main() {
    srand(time(0));

    ofstream tablefile("truth_table.txt");
    ofstream csvFile("truth_csv.txt");
    if (!tablefile  || !csvFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    tablefile << "Test No\tInput (n)\tCombinations (2^n)\tExecution Time (ns)\n";
    tablefile << "-------------------------------------------------------------\n";
    csvFile << "Test,Input,Combinations,Time\n";

    for (int test = 1; test <= 10; test++) {
        int n = rand() % 10;
        cout << "----------------------------------\n";
        cout << "Test Case " << test << endl;
        cout << "Generated Input (n): " << n << endl;
        cout << "Truth Table Combinations:\n";
        printCombinations(0, n, "");
        double execTime = measureExecutionTime(n);
        int combinations = 1;
        for (int i = 0; i < n; i++)
            combinations *= 2;
    cout << "\nExecution Time: " <<fixed<< execTime << " nanoseconds\n";
       
        tablefile << test << "\t\t"
             << n << "\t\t"
             << combinations << "\t\t\t"
             <<fixed<< execTime << "\n";
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
