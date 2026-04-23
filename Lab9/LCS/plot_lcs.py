import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("LCS_csv.txt")
x = data["Length"]
y = data["Time"]

plt.plot(x, y, marker='o')
plt.xlabel("Length of String")
plt.ylabel("Execution Time (ns)")
plt.title("Longest Commom Sequence Performance")

plt.grid(True)
plt.savefig("LCS_graph.png")
plt.show()