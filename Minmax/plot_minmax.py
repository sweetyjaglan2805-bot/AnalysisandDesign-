import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("minmax_csv.txt")

x = data["N"]
y = data["Time"]

# Plot graph
plt.plot(x, y, marker='o')
plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (ns)")
plt.title("Min-Max Performance")
plt.text(0.2*max(x), 0.9*max(y), "Time Complexity: O(n)", fontsize=12)
plt.grid(True)

plt.savefig("minmax_graph.png")
plt.show()