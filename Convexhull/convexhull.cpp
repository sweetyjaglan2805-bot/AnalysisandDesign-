#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

#define MAX 1000

struct Point
{
    float x, y;
};

Point points[MAX];
Point hull[MAX];
int hullSize = 0;
float LineDistance(Point A, Point B, Point P)
{
    return abs((B.x - A.x)*(A.y - P.y) -
               (A.x - P.x)*(B.y - A.y));
}

int FindSide(Point A, Point B, Point P)
{
    float val = (B.x - A.x)*(P.y - A.y) -
                (B.y - A.y)*(P.x - A.x);

    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

void InsertHull(Point p)
{
    for(int i = 0; i < hullSize; i++)
    {
        if(hull[i].x == p.x && hull[i].y == p.y)
            return;
    }
    hull[hullSize++] = p;
}

void QuickHullRec(Point A, Point B, int side, int n)
{
    int index = -1;
    float maxDist = 0;

    for(int i = 0; i < n; i++)
    {
        float temp = LineDistance(A, B, points[i]);

        if(FindSide(A, B, points[i]) == side && temp > maxDist)
        {
            index = i;
            maxDist = temp;
        }
    }
    if(index == -1)
    {
        InsertHull(A);
        InsertHull(B);
        return;
    }
    QuickHullRec(points[index], A,
        -FindSide(points[index], A, B), n);

    QuickHullRec(points[index], B,
        -FindSide(points[index], B, A), n);
}

void QuickHull(int n)
{
    if(n < 3) return;

    int min = 0, max = 0;

    for(int i = 1; i < n; i++)
    {
        if(points[i].x < points[min].x)
            min = i;

        if(points[i].x > points[max].x)
            max = i;
    }
    QuickHullRec(points[min], points[max], 1, n);
    QuickHullRec(points[min], points[max], -1, n);
}
void generatePoints(int n)
{
    for(int i = 0; i < n; i++)
    {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
}

double measureTime(int n)
{
    clock_t start = clock();
    hullSize = 0;
     for(int i = 0; i < 1000; i++) {
       QuickHull(n);
    }
    clock_t end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;
    return time * 1000000000.0; // ns
}

void printHull()
{
    cout << "\nConvex Hull Points:\n";
    for(int i = 0; i < hullSize; i++)
    {
        cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
    }
}
int main()
{
    srand(time(0));
    ofstream txtFile("convexhull_txt.txt");
    ofstream csvFile("convexhull_csv.txt");
    txtFile << "Points\tTime(ns)\n";
    csvFile << "Points,Time\n";
    for(int n = 10; n <= 500; n += 10)
    {
        cout << "\nNumber of Points: " << n << endl;
        generatePoints(n);
        double timeTaken = measureTime(n);
        cout << "Execution Time = " << timeTaken << " ns\n";
        if(n == 10)
        {
            hullSize = 0;
            QuickHull(n);
            printHull();
        }
        txtFile << n << "\t" << timeTaken << endl;
        csvFile << n << "," << timeTaken << endl;
    }
    txtFile.close();
    csvFile.close();
    return 0;
}


