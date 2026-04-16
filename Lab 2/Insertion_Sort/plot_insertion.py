import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("insertion_csv.txt")

data = data.sort_values("N")

x = data["N"]
best = data["Best"]
avg = data["Average"]

plt.plot(x, best, label="Best Case")
plt.plot(x, avg, label="Average Case")

plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (ns)")
plt.title("Insertion Sort Performance")
plt.legend()
plt.grid(True)
plt.savefig("insertion_sort_graph.png")
plt.show()
