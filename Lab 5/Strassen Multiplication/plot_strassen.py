import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("strassen_csv.txt")
x = data["Size"]
y = data["Time"]

plt.plot(x, y, marker='o')
plt.xlabel("Order of matrix")
plt.ylabel("Execution Time (ns)")
plt.title("Strassen Performance")
plt.text(0.6*max(x),0.9* max(y), "Time Complexity: O(n^2.81)", fontsize=12)
plt.grid(True)
plt.savefig("strassen_graph.png")
plt.show()