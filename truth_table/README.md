# Truth Table Generation using Recursion

## Aim
To generate all possible truth table combinations for a given number of boolean variables using recursion and to analyze the execution time.

## Description
This program generates all possible combinations of `T` (True) and `F` (False) for `n` variables.  
Since each variable can take two values, the total number of combinations is `2^n`.

The program also measures the execution time required to generate these combinations and analyzes how the time grows with respect to input size.

## Algorithm
1. Generate a random input value `n`.
2. Use recursion to generate all combinations of length `n`.
3. For timing, use a dummy recursive function to simulate the same number of recursive calls.
4. Count total combinations using `2^n`.
5. Measure execution time in nanoseconds.
6. Store results in:
   - Table format (`.txt`)
   - CSV format (`.txt`)
7. Plot a graph using Python.

## Time Complexity
The time complexity of this algorithm is:

O(2ⁿ)

This is because the number of recursive calls doubles with every increase in `n`.

## Files in this Folder

- `truth_table.cpp`  
  C++ program to generate truth table and measure execution time.

- `truth_table.txt`  
  Table formatted output for easy understanding.

- `truth_csv.txt`  
  CSV formatted output used for graph plotting.

- `plot_truth.py`  
  Python script to generate performance graph using matplotlib.

- `truth_graph.png`  
  Graph showing Input Size (n) vs Execution Time.

## How to Run

### Step 1: Compile and run C++ program
```bash
g++ truth_table.cpp -o truth
./truth
