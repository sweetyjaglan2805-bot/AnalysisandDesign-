#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

double power(double x, int n) {
    if (n == 0)
        return 1.0;

    double half = power(x, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}
double measureTime(double x, int n, double &result) {
    clock_t start = clock();

    for (int i = 0; i < 100000; i++) {
        result = power(x, n);
    }

    clock_t end = clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds * 1000000000.0; // ns
}

int main() {
    srand(time(0));
    ofstream tableFile("power_table.txt");
    ofstream csvFile("power_csv.txt");  

    if (!tableFile || !csvFile) {
        cout << "Error creating files!" << endl;
        return 1;
    }
    tableFile << "Test\tBase(x)\tExponent(n)\tResult\tTime(ns)\n";
    tableFile << "-------------------------------------------------------------\n";
    csvFile << "Test,Base,Exponent,Result,Time\n";
    double x = 2.0;  
    int test = 1;
    for (int n = 1; n <= 500; n += 5) {

        double result;
        double timeTaken = measureTime(x, n, result);
        cout << "\nTest Case: " << test << endl;
        cout << "Base (x): " << x << endl;
        cout << "Exponent (n): " << n << endl;
        cout << "Result: " << result << endl;
        cout << "Execution Time: " << timeTaken << " ns" << endl;
        tableFile << test << "\t"
                  << x << "\t"
                  << n << "\t"
                  << result << "\t"
                  << timeTaken << "\n";
        csvFile << test << ","
                << x << ","
                << n << ","
                << result << ","
                << timeTaken << "\n";
        test++;
    }

    tableFile.close();
    csvFile.close();
    cout << "\nData saved in power_table.txt and power_csv.txt\n";
    return 0;
}