#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;

void generateString(char str[], int len) {
    for (int i = 0; i < len; i++)
        str[i] = 'A' + i;  
    str[len] = '\0';
}
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
void permuteForTiming(char str[], int l, int r) {
    if (l == r)
        return;
    for (int i = l; i <= r; i++) {
        swap(str[l], str[i]);
        permuteForTiming(str, l + 1, r);
        swap(str[l], str[i]);
    }
}
double measureTime(char str[], int len) {
    clock_t start = clock();
    for (int i = 0; i < 1000; i++) {  
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

