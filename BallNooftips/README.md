# Ball Number of Tips Simulation

## Description
In this experiment, a random initial velocity is generated. After every tip, the velocity is multiplied by a constant reduction factor. This process continues until the velocity drops below 1 m/s.

The program:
- Calculates the number of tips using a loop
- Measures execution time in nanoseconds
- Stores results in both table and CSV formats
- Uses Python to plot a performance graph

## Algorithm
1. Generate a random initial velocity.
2. Set tips = 0.
3. While velocity ≥ 1:
   - Increment tips.
   - Multiply velocity by reduction factor.
4. Stop when velocity < 1.
5. Measure execution time.

## Time Complexity
The time complexity of the algorithm is:
O(k)
Where k is the number of tips required for the velocity to drop below 1.
This means execution time increases linearly with the number of iterations.

## Files

- `ball_tips.cpp`  
  C++ program for simulation and performance measurement.

- `ball_table.txt`  
  Table formatted output for easy human reading.

- `ball_csv.txt`  
  CSV formatted output used for plotting the graph.

- `plot_ball.py`  
  Python script using matplotlib to generate the graph.

- `ball_graph.png`  
  Graph showing Initial Velocity vs Execution Time.
## How to Run
1. Compile the C++ program.
2. Run the program to generate output files.
3. Run the Python script to generate the graph.

## Output
The output includes a table of results and a graph showing execution time versus input size(random velocity generated).

