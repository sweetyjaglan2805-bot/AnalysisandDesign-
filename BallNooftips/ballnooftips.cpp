#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const double REDUCTION_FACTOR = 0.575;
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
    tips = calculateTips(velocity);
    clock_t end = clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds * 1000000000.0; // nanoseconds
}

int main() {
    ofstream tableFile("ball_table.txt");
    ofstream csvFile("ball_csv.txt");
    if (!tableFile || !csvFile) {
        cout << "Error creating files!" << endl;
        return 1;
    }

    tableFile << "InitialVelocity\tTips\tExecutionTime(ns)\n";
    csvFile << "InitialVelocity,Tips,Time\n";
    for (int size = 5; size <= 500; size += 10) {
        double velocity = size;
        int tips;
        double timeTaken = measureTime(velocity, tips);

        // Console output
        cout << "Velocity: " << size << endl;
        // cout << "Initial Velocity Used: " << generateVelocity() << " m/s" << endl;
        cout << "Total Number of Tips: " << tips << endl;
        cout << "Execution Time: " << fixed << timeTaken << " ns\n"<<endl;

        // File output
        tableFile << velocity << "\t\t\t"
                  << tips << "\t\t"
                  << timeTaken << "\n";

        csvFile << velocity << ","
                << tips << ","
                << timeTaken << "\n";
    }

    tableFile.close();
    csvFile.close();

    cout << "\nResults saved in ball_table.txt and ball_csv.txt\n";
    return 0;
}
