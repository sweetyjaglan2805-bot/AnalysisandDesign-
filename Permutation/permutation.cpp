// // Permutation generation
// #include <iostream>
// #include <fstream>
// #include <cstdlib>
// #include <ctime>
// #include <cstring>
// using namespace std;

// void generateRandomString(char str[], int len) {
//     for (int i = 0; i < len; i++)
//         str[i] = '0' + rand() % 10;
//     str[len] = '\0';
// }

// // Print permutations to console
// void permutePrint(char str[], int l, int r) {
//     if (l == r) {
//         cout << str << " ";
//         return;
//     }

//     for (int i = l; i <= r; i++) {
//         swap(str[l], str[i]);
//         permutePrint(str, l + 1, r);
//         swap(str[l], str[i]);
//     }
// }

// // Same permutation logic, without printing (for timing)
// void permuteForTiming(char str[], int l, int r) {
//     if (l == r)
//         return;

//     for (int i = l; i <= r; i++) {
//         swap(str[l], str[i]);
//         permuteForTiming(str, l + 1, r);
//         swap(str[l], str[i]);
//     }
// }

// // Measure execution time
// double measureTime(char str[], int len) {
//     clock_t start = clock();
//  for (int i = 0; i < 100000; i++) {
//         permuteForTiming(str, 0, len - 1);
//     }
//     clock_t end = clock();

//     double seconds = double(end - start) / CLOCKS_PER_SEC;
//     return seconds * 1000000000.0;
// }

// int main() {
//     srand(time(NULL));

//     ofstream file("permutation.txt");
//     if (!file) {
//         cout << "Error creating permutation.txt file!" << endl;
//         return 1;
//     }

//     file << "Test No\tInput String\tLength\tExecution Time (ns)\n";
//     file << "------------------------------------------------------\n";

//     char str[10];

//     for (int i = 1; i <= 10; i++) {
//         int len = rand() % 6 + 1;  // limit length to avoid huge output

//         generateRandomString(str, len);

//         cout << "----------------------------------------\n";
//         cout << "Test Case: " << i << endl;
//         cout << "Generated Input: " << str << endl;
//         cout << "Permutations: ";

//         // Print permutations to console
//         permutePrint(str, 0, len - 1);

//         double timeTaken = measureTime(str, len);

//         cout << "\nExecution Time: " << fixed << timeTaken << " ns\n";
//         cout << "----------------------------------------\n";

//         // Write to file (no permutations, only summary)
//         file << i << "\t\t"
//              << str << "\t\t"
//              << len << "\t\t"
//              << fixed << timeTaken << "\n";
//     }

//     file.close();

//     cout << "\nResults saved in permutation.txt\n";
//     return 0;
// }
// Permutation generation (systematic input)
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;

void generateString(char str[], int len) {
    for (int i = 0; i < len; i++)
        str[i] = 'A' + i;   // ABCD...
    str[len] = '\0';
}

// Print permutations
void permutePrint(char str[], int l, int r) {
    if (l == r) {
        cout << str << " ";
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(str[l], str[i]);
        permutePrint(str, l + 1, r);
        swap(str[l], str[i]);
    }
}

// For timing only (no printing)
void permuteForTiming(char str[], int l, int r) {
    if (l == r)
        return;
    for (int i = l; i <= r; i++) {
        swap(str[l], str[i]);
        permuteForTiming(str, l + 1, r);
        swap(str[l], str[i]);
    }
}

// Measure execution time
double measureTime(char str[], int len) {
    clock_t start = clock();
    for (int i = 0; i < 1000; i++) {   // reduced loop (n! is huge)
        permuteForTiming(str, 0, len - 1);
    }
    clock_t end = clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds * 1000000000.0;
}

int main() {

    ofstream file("permutation_table.txt");
    ofstream csvFile("permutation_csv.txt");

    if (!file || !csvFile) {
        cout << "Error creating files!" << endl;
        return 1;
    }

    file << "InputSize\tInputString\tExecution Time (ns)\n";
    file << "-----------------------------------------------\n";
    csvFile << "Size,String,Time\n";

    char str[10];

    // SAME STYLE: increasing input
    for (int size = 1; size <= 8; size++) {

        generateString(str, size);

        cout << "\n----------------------------------------\n";
        cout << "Input Size: " << size << endl;
        cout << "Generated Input: " << str << endl;
        cout << "Permutations:\n";

        permutePrint(str, 0, size - 1);
        cout << endl;

        double timeTaken = measureTime(str, size);

        cout << "Execution Time: " << timeTaken << " ns\n";
        cout << "----------------------------------------\n";

        // File output
        file << size << "\t\t"
             << str << "\t\t"
             << timeTaken << "\n";

        csvFile << size << ","
                << str << ","
                << timeTaken << "\n";
    }

    file.close();
    csvFile.close();

    cout << "\nResults saved in permutation_table.txt and permutation_csv.txt\n";
    return 0;
}

