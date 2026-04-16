import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("duplicate_csv.txt")
x = data["Size"]
y = data["Time"]

plt.plot(x, y, marker='o')
plt.xlabel("Number of elements")
plt.ylabel("Execution Time (ns)")
plt.title("First Duplicate Performance")
plt.text(0.6*max(x),0.9* max(y), "Time Complexity: O(n)", fontsize=12)
plt.grid(True)
plt.savefig("duplicate_graph.png")
plt.show()