import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("truth_csv.txt")
data = data.sort_values(by="Input")
x = data["Input"]
y = data["Time"]

plt.plot(x, y, marker='o')
plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (ns)")
plt.title("Truth Table Generation Performance")
plt.grid(True)
plt.savefig("truth_graph.png")
plt.show()
