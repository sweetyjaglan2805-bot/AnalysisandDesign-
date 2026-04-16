import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("dijkstra_csv.txt")

x = data["Vertices"]
y = data["Time"]

plt.plot(x, y, marker='o')
plt.xlabel("Number of vertex")
plt.ylabel("Execution Time (ns)")
plt.title("Dijkestra's Algorithm Analysis")
plt.grid(True)
plt.savefig("Dijkestra_graph.png")
plt.show()