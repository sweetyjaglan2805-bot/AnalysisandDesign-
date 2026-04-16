import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("binary_csv.txt")
data = data.sort_values("N")

x = data["N"]
time = data["Time"]

plt.plot(x, time, marker='o', label="Binary Search Time")

plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (ns)")
plt.title("Binary Search Performance")
plt.legend()
plt.grid(True)

plt.text(x.max()*0.6, max(time)*0.8, "Time Complexity: O(log n)", fontsize=12)

plt.savefig("binary_search_graph.png")
plt.show()

