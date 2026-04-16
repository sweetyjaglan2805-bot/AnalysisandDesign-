import pandas as pd
import matplotlib.pyplot as plt

# Read CSV file
data = pd.read_csv("permutation_csv.txt")

x = data["Size"]     # Input size (n)
y = data["Time"]     # Execution time

plt.figure()
plt.plot(x, y, marker='o')
plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (ns)")
plt.title("Permutation Algorithm Performance")

# Add time complexity text
plt.text(0.5*max(x), 0.8*max(y), "Time Complexity: O(n!)", fontsize=12)

plt.grid(True)
plt.savefig("permutation_graph.png")
plt.show()
