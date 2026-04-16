import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("convexhull_csv.txt")

x = data["Points"]
y = data["Time"]

plt.plot(x, y, marker='o')
plt.xlabel("Number of vertex")
plt.ylabel("Execution Time (ns)")
plt.title("ConvexHull's Algorithm Analysis")
# plt.text(0.2*max(x), 0.9*max(y), "Time Complexity: O(nlogn)", fontsize=12)
plt.grid(True)
plt.savefig("convexhull_graph.png")
plt.show()