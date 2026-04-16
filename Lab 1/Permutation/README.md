# Permutation Generation Simulation

## Description
In this experiment, permutations of a given string are generated using a recursive backtracking algorithm. The input string size is increased systematically, and all possible permutations are produced.
The program:
   Generates permutations using recursion and swapping
   Measures execution time in nanoseconds
   Stores results in both table and CSV formats
   Uses Python to plot a performance graph

## Algorithm
1. Generate an input string of length n.
2. Fix the first character and recursively permute the remaining characters
3. Swap characters to explore all possible arrangements (backtracking).
4. Repeat until all permutations are generated.
5. Measure execution time.

## Time Complexity
The time complexity of the algorithm is:
O(n!)

Where n is the length of the input string.
This means execution time increases factorially with input size, making the algorithm extremely expensive even for small values of n.

## Files

`permutation.cpp`
C++ program for permutation generation and performance measurement.

`permutation_table.txt`
Table formatted output for easy human reading.

`permutation_csv.txt`
CSV formatted output used for plotting the graph.

`plot_permutation.py`
Python script using matplotlib to generate the graph.

`permutation_graph.png`
Graph showing Input Size vs Execution Time.
## How to Run
1. Compile the C++ program.
2. Run the program to generate output files.
3. Run the Python script to generate the graph.

## Output
The output includes a table of results and a graph showing execution time versus input size (length of the string). The graph clearly demonstrates factorial growth in execution time as the input size increases