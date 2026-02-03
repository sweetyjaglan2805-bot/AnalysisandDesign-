import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("sum_csv.txt")

x = data["ArraySize"]   # input size
y = data["Time"]        # execution time

plt.plot(x, y, marker='o')
plt.xlabel("Array Size (n)")
plt.ylabel("Execution Time (ns)")
plt.title("Recursive Sum Performance")
plt.grid(True)
plt.savefig("sum_graph.png")
plt.show()
