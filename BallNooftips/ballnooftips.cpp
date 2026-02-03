#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const double REDUCTION_FACTOR = 0.575;

// Generate initial velocity
double generateVelocity() {
    return rand();   // random velocity
}

// Calculate number of tips
int calculateTips(double velocity) {
    int tips = 0;
    while (velocity >= 1.0) {
        tips++;
        velocity *= REDUCTION_FACTOR;
    }
    return tips;
}

// Measure execution time
double measureTime(double velocity, int &tips) {
    clock_t start = clock();
 for (int i = 0; i < 100000; i++) {
         tips = calculateTips(velocity);
    }
    // tips = calculateTips(velocity);

    clock_t end = clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds * 1000000000.0; // nanoseconds
}

int main() {
    const int TESTS = 10;
    srand(time(NULL));

    ofstream tableFile("ball_table.txt");
    ofstream csvFile("ball_csv.txt");
    if (!tableFile || !csvFile) {
        cout << "Error creating files!" << endl;
        return 1;
    }
    tableFile << "Test\tInitialVelocity\tTips\tExecutionTime(ns)\n";
    tableFile << "-------------------------------------------------\n";
    csvFile << "Test,Velocity,Tips,Time\n";
    for (int i = 1; i <= TESTS; i++) {
        double initialVelocity = generateVelocity();
        int tips;
        double timeTaken = measureTime(initialVelocity, tips);

        // Console output
        cout << "\n----------------------------------------\n";
        cout << "Test Case: " << i << endl;
        cout << "Initial Velocity: " << initialVelocity << " m/s" << endl;
        cout << "Total Number of Tips: " << tips << endl;
        cout << "Execution Time: " << fixed << timeTaken << " ns\n";
        cout << "----------------------------------------\n";

        // File output
        tableFile << i << "\t\t"
             << fixed << initialVelocity << "\t\t\t"
             << tips << "\t\t"
             << timeTaken << "\n";
        csvFile << i << ","
                << initialVelocity << ","
                << tips << ","
                << timeTaken << "\n";
    }

    tableFile.close();
    csvFile.close();

    cout << "\nResults saved in ballnooftips.txt\n";
    return 0;
}
