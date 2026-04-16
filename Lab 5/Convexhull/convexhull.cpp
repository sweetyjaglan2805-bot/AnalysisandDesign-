#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

#define MAX 1000
float px[MAX], py[MAX];   
float hx[MAX], hy[MAX];   
int hullSize = 0;
float LineDistance(float Ax, float Ay, float Bx, float By, float Px, float Py){
    return abs((Bx - Ax)*(Ay - Py) - (Ax - Px)*(By - Ay));
}
int FindSide(float Ax, float Ay, float Bx, float By, float Px, float Py){
    float val = (Bx - Ax)*(Py - Ay) - (By - Ay)*(Px - Ax);
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

void InsertHull(float x, float y){
    for(int i = 0; i < hullSize; i++) {
        if(hx[i] == x && hy[i] == y)
            return;
    }
    hx[hullSize] = x;
    hy[hullSize] = y;
    hullSize++;
}

void ConvexHullRec(float Ax, float Ay, float Bx, float By, int side, int n){
    int index = -1;
    float maxDist = 0;
    for(int i = 0; i < n; i++){
        float temp = LineDistance(Ax, Ay, Bx, By, px[i], py[i]);
        if(FindSide(Ax, Ay, Bx, By, px[i], py[i]) == side && temp > maxDist){
            index = i;
            maxDist = temp;
        }
    }
    if(index == -1){
        InsertHull(Ax, Ay);
        InsertHull(Bx, By);
        return;
    }
    int side1 = FindSide(px[index], py[index], Ax, Ay, Bx, By);
    side1 = -side1;
    int side2 = FindSide(px[index], py[index], Bx, By, Ax, Ay);
    side2 = -side2;
    ConvexHullRec(px[index], py[index], Ax, Ay, side1, n);
    ConvexHullRec(px[index], py[index], Bx, By, side2, n);
}
void ConvexHull(int n){
    if(n < 3) return;
    int min = 0, max = 0;
    for(int i = 1; i < n; i++){
        if(px[i] < px[min])
            min = i;
        if(px[i] > px[max])
            max = i;
    }
    ConvexHullRec(px[min], py[min], px[max], py[max], 1, n);
    ConvexHullRec(px[min], py[min], px[max], py[max], -1, n);
}

void generatePoints(int n){
    for(int i = 0; i < n; i++){
        px[i] = rand() % 100;
        py[i] = rand() % 100;
    }
}

double measureTime(int n){
    clock_t start = clock();
    for(int i = 0; i < 1000; i++) {
        hullSize = 0;
        ConvexHull(n);
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC * 1e9;
}

void printHull(){
    cout << "\nConvex Hull Points:\n";
    for(int i = 0; i < hullSize; i++){
        cout << "(" << hx[i] << ", " << hy[i] << ")\n";
    }
}
int main(){
    srand(time(0));
    ofstream txtFile("convexhull_txt.txt");
    ofstream csvFile("convexhull_csv.txt");
    txtFile << "Points\tTime(ns)\n";
    csvFile << "Points,Time\n";
    for(int n = 10; n <= 500; n += 10){
        cout << "\nNumber of Points: " << n << endl;
        generatePoints(n);
        double timeTaken = measureTime(n);
        cout << "Execution Time = " << timeTaken << " ns\n";
        if(n == 10)        {
            hullSize = 0;
            ConvexHull(n);
            printHull();
        }
        txtFile << n << "\t" << timeTaken << endl;
        csvFile << n << "," << timeTaken << endl;
    }
    txtFile.close();
    csvFile.close();
    return 0;
}