# Sum of Array Simulation

## Description
In this experiment, the sum of elements of an array is calculated using both recursive and iterative approaches. The input size (array length) is increased systematically, and the execution time of both methods is measured and compared.

The program:
Generates an array of random integers
Calculates sum using recursion and iteration
Measures execution time in nanoseconds
Stores results in both table and CSV formats
Uses Python to plot a performance comparison graph

## Algorithm
1. Generate an array of size n.
2. Calculate sum using recursive method.
3. Calculate sum using iterative method.
4. Measure execution time for both methods.
5. Repeat for increasing input sizes.

## Time Complexity
The time complexity of both algorithms is:
O(n)

Where n is the number of elements in the array.
This means execution time increases linearly with input size for both recursive and iterative approaches.

## Files

`sum.cpp`
C++ program for permutation generation and performance measurement.

`sum_table.txt`
Table formatted output for easy human reading.

`sum_csv.txt`
CSV formatted output used for plotting the graph.

`plot_sum.py`
Python script using matplotlib to generate the graph.

`sum_graph.png`
Graph showing Input Size vs Execution Time.

## How to Run
1. Compile the C++ program.
2. Run the program to generate output files.
3. Run the Python script to generate the graph.

## Output
The output includes a table of results and a graph showing execution time versus array size for both recursive and iterative methods. The graph clearly shows linear growth, confirming the O(n) time complexity for both approaches, with the iterative method being slightly faster in practice due to lower overhead.
