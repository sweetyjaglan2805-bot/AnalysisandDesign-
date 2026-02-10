# Horner’s Rule Performance Analysis using Recursion

## Aim
To evaluate a polynomial using Horner’s Rule implemented with recursion and to analyze the execution time for different polynomial degrees.

## Description
This program evaluates a polynomial of degree n using Horner’s Rule, which reduces the number of multiplications required.

The coefficients of the polynomial and the value of x are generated randomly.
The program automatically increases the degree of the polynomial and measures the execution time for each case.

To obtain measurable results, the Horner’s function is executed multiple times and the total execution time is recorded.

## Algorithm
1. Generate polynomial degree n in increasing order.
2. Generate random coefficients for the polynomial.
3. Generate a random value of x.
4. Use recursion to evaluate the polynomial using Horner’s Rule.
5. Measure execution time using clock().
6. Store results in:
   - Table format (`.txt`)
   - CSV format (`.txt`)
7. Plot a graph using Python.

## Time Complexity
The time complexity of Horner’s Rule is:

O(n)

This is because the polynomial is evaluated using a single recursive call for each coefficient.
## Files in this Folder

- `horner.cpp`  
  C++ program to evaluate polynomial using recursive Horner’s Rule and measure execution time.

- `horner_table.txt`  
  Table formatted output for report and analysis.

- `horner_csv.txt`  
  CSV formatted output used for graph plotting.

- `plot_horner.py`  
  Python script to generate performance graph using matplotlib.

- `horner_graph.png`  
  Graph showing Degree of Polynomial vs Execution Time.

## How to Run
1. Compile the C++ program.
2. Run the program to generate output files.
3. Run the Python script to generate the graph.

## Output
The output includes detailed console information showing:
Degree of polynomial
Generated value of x
Random coefficients
Horner form of the polynomial
Final evaluated result
Execution time
Additionally, a table file and a graph are generated.
The graph clearly demonstrates linear growth in execution time, confirming that Horner’s Rule has O(n) time complexity.