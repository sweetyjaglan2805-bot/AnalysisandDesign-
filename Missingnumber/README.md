# Missing Number Algorithm

## Aim
To find the missing number from a sequence of consecutive integers using a linear-time algorithm and to analyze its execution time.

## Description
This program generates a sequence of consecutive integers with exactly one number missing.
The missing number is detected using a bitwise-based linear algorithm.

To obtain reliable performance results, the algorithm is executed multiple times for the same input size, and the average execution time is computed. This helps reduce noise caused by system and hardware variations.

The execution time is measured in nanoseconds and stored in both:

Table format (.txt)

CSV format (.txt) for plotting using Python (matplotlib)

## Algorithm
1. Input
      An integer n representing the size of the array.
      An array of size n-1 containing consecutive integers with one missing value.
2. Output
      The missing number.
      Average execution time in nanoseconds.
3. Steps
 1. nitialize a static array of maximum size.
 2. For increasing values of n:
       Generate a sequence of consecutive numbers with one missing element.
 3. Apply the missing number algorithm:
          Traverse the array once.
          Compare the least significant bits of adjacent elements.
          Detect the missing value using bitwise XOR.
 4. Repeat the algorithm multiple times (RUNS).
 5. Compute the average execution time.
 6. Display results on the console.
7. Store results in:
   Table format text file.
   CSV file for graph plotting

## Time Complexity
The algorithm scans the array only once:

T(n)=c⋅n

Therefore, the time complexity is:
O(n)

## Files in this Folder

- `missingnumber.cpp`  
  C++ program implementing the missing number algorithm with average timing.

- `missingnumber_table.txt`  
  Table formatted output for easy understanding.

- `missing_csv.txt`  
  CSV formatted output used for graph plotting.

- `plot_missing.py`  
  Python script to generate performance graph using matplotlib.

- `missingnumber_graph.png`  
  Graph showing Array Size (n) vs Execution Time.

## How to Run
1. Compile the C++ program.
2. Run the program to generate output files.
3. Run the Python script to generate the graph.

## Output
The program prints: Array size, Generated numbers, Missing number, Average execution time.
And generates: A table file, A CSV file, A performance graph