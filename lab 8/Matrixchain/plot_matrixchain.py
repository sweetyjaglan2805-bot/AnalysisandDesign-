import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("matrixchain_csv.txt")
x = data["N"]
y = data["Time"]

plt.plot(x, y, marker='o')
plt.xlabel("Number of matrices")
plt.ylabel("Execution Time (ns)")
plt.title("Matrix Chain Graph Performance")

plt.grid(True)
plt.savefig("matrixchain_graph.png")
plt.show()