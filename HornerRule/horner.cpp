// #include <iostream>
// #include <fstream>
// #include <ctime>
// #include <cstdlib>

// using namespace std;

// // Recursive Horner's Rule
// double hornerRecursive(double a[], int n, double x)
// {
//     if (n == 0)
//         return a[0];
//     return hornerRecursive(a, n - 1, x) * x + a[n];
// }

// // Time measurement function
// double measureTime(double a[], int n, double x, double &result)
// {
//     clock_t start = clock();
//     for(int i=0; i<=100000 ;i++){
//     result = hornerRecursive(a, n, x);}
//     clock_t end = clock();
//     double seconds = (end - start) / CLOCKS_PER_SEC;
//     return seconds * 1000000000.0;
// }

// // Generate random coefficients
// void generateCoefficients(double a[], int n)
// {
//     for (int i = 0; i <= n; i++)
//         a[i] = rand() % 10;
// }

// // Generate random x
// double generateRandomX()
// {
//     return (rand() % 100) / 10.0;
// }

// // Print polynomial in Horner form
// void printHornerForm(double a[], int n)
// {
//     cout << "Horner Form: ";
//     cout << "(";
//     for (int i = 0; i < n; i++)
//         cout << a[i] << " * x + ";
//     cout << a[n] << ")" << endl;
// }

// int main()
// {
//     const int MAX = 1000;
//     double coeff[MAX];
//     double x;
//     double result, time_taken;

//     srand(time(0));

//     ofstream txt("horner_output.txt");
//     ofstream csv("horner_output.csv");

//     txt << "Degree\tX\tResult\t\tTime\n";
//     csv << "Degree,X,Result,Time\n";

//     // Automated experiment
//     for (int n = 10; n <= 500; n += 10)
//     {
//         generateCoefficients(coeff, n);
//         x = generateRandomX();
//         time_taken = measureTime(coeff, n, x, result);

//         // -------- Console Output (Detailed) --------
//         cout << "\n--------------------------------------\n";
//         cout << "Degree of Polynomial: " << n << endl;
//         cout << "Generated x: " << x << endl;

//         cout << "Generated Coefficients: ";
//         for (int i = 0; i <= n; i++)
//             cout << coeff[i] << " ";
//         cout << endl;

//         printHornerForm(coeff, n);

//         cout << "Polynomial Value: " << result << endl;
//         cout << "Execution Time: " << time_taken << " seconds" << endl;
//         cout << "--------------------------------------\n";

//         // -------- File Output (Structured) --------
//         txt << n << "\t" << x << "\t" << result << "\t\t" << time_taken << endl;
//         csv << n << "," << x << "," << result << "," << time_taken << endl;
//     }

//     txt.close();
//     csv.close();

//     return 0;
// }
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Recursive Horner's Rule
double hornerRecursive(double a[], int n, double x)
{
    if (n == 0)
        return a[0];
    return hornerRecursive(a, n - 1, x) * x + a[n];
}

// Time measurement function (repeated)
double measureTime(double a[], int n, double x, double &result)
{
    clock_t start = clock();

    for (int i = 0; i < 10000; i++)
        result = hornerRecursive(a, n, x);

    clock_t end = clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;
    return seconds*1000000000.0;
}

// Generate random coefficients
void generateCoefficients(double a[], int n)
{
    for (int i = 0; i <= n; i++)
        a[i] = rand() % 10;
}

// // Generate random x
// double generateRandomX()
// {
//     return (rand() % 100) / 10.0;
// }

// Print polynomial in Horner form
void printHornerForm(double a[], int n)
{
    cout << "Horner Form: ";
    cout << "(";
    for (int i = 0; i < n; i++)
        cout << a[i] << " * x + ";
    cout << a[n] << ")" << endl;
}

int main()
{
    const int MAX = 1000;
    double coeff[MAX];
    double x;
    double result, time_taken;

    srand(time(0));

    ofstream txtfile("horner_table.txt");
    ofstream csvfile("horner_csv.txt");

    txtfile << "Degree\tX\tResult\t\tTime\n";
    csvfile << "Degree,X,Result,Time\n";

    // Automated experiment
    for (int n = 10; n <= 500; n += 10)
    {
        generateCoefficients(coeff, n);
        x = (rand() % 100) / 10.0;
        time_taken = measureTime(coeff, n, x, result);

        // -------- Console Output (Human Readable) --------
        cout << "\n--------------------------------------\n";
        cout << "Degree of Polynomial: " << n << endl;
        cout << "Generated x: " << x << endl;

        cout << "Generated Coefficients: ";
        for (int i = 0; i <= n; i++)
            cout << coeff[i] << " ";
        cout << endl;
        printHornerForm(coeff, n);
        cout << "Polynomial Value: " << result << endl;
        cout << "Execution Time"<< time_taken << "ns" << endl;

        txtfile << n << "\t" << x << "\t" << result << "\t\t" << time_taken << endl;
        csvfile << n << "," << x << "," << result << "," << time_taken << endl;
    }

    txtfile.close();
    csvfile.close();

    return 0;
}

