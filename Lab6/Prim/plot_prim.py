import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("prim_csv.txt")

x = data["Vertex"]
y = data["Time"]

plt.plot(x, y, marker='o')
plt.xlabel("Number of vertex")
plt.ylabel("Execution Time (ns)")
plt.title("Prim's Algorithm Analysis")
plt.grid(True)
plt.savefig("prim_graph.png")
plt.show()