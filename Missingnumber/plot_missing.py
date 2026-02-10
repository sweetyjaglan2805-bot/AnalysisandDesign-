import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("missing_csv.txt")

x = data["ArraySize"]
y = data["Time"]

plt.plot(x, y, marker='o')
plt.xlabel("Array Size")
plt.ylabel("Execution Time (seconds)")
plt.title("Missing Number Algorithm Performance")

plt.text(0.6 * max(x), 0.9 * max(y), "Time Complexity: O(n)", fontsize=12)

plt.grid(True)
plt.savefig("missingnumber_graph.png")
plt.show()
