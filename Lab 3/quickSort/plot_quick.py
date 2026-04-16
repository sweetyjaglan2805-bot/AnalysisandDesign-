import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("quick_csv.txt")

x = data["N"]
y = data["Time"]

plt.plot(x, y, marker='o')
plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (ns)")
plt.title("Quicksort Performance Analysis")
plt.text(0.2*max(x), 0.9*max(y), "Time Complexity: O(nlogn)", fontsize=12)
plt.grid(True)

plt.savefig("quick_graph.png")
plt.show()