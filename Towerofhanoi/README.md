# Tower of Hanoi
## Description
In this experiment, a random number of disks is generated. The Tower of Hanoi recursive algorithm is then executed to move all disks from the source rod to the destination rod using an auxiliary rod.

The program:
Generates a random number of disks
Solves the Tower of Hanoi problem using recursion
Measures execution time in nanoseconds
Stores results in both table and CSV formats
Uses Python to plot a performance graph

## Algorithm
1.Generate a random number of disks n.
2. Call the recursive function towerOfHanoi(n, source, destination, auxiliary).
3. If n == 1, move the disk directly.
4. Otherwise:
            Move n-1 disks from source to auxiliary.
            Move the nth disk from source to destination.
            Move n-1 disks from auxiliary to destination.
5. Measure execution time for the process.

## Time Complexity
The time complexity of the algorithm is:
O(2ⁿ)

This is because the number of moves required is:
2ⁿ − 1

## Files

towerofhanoi.cpp
C++ program for simulation and performance measurement.

towerofhanoi.txt
Table formatted output for easy human reading.

towerofhanoi.csv
CSV formatted output used for plotting the graph.

plot_hanoi.py
Python script using matplotlib to generate the graph.

towerofhanoi_graph.png
Graph showing Number of Disks vs Execution Time.
## How to Run
1. Compile the C++ program.
2. Run the program to generate output files.
3. Run the Python script to generate the graph.

## Output
The output includes a table of results and a graph showing execution time versus input size(random vnumber of disk generated).
