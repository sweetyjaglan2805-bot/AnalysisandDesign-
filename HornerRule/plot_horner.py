import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("horner_csv.txt")

x = data["Degree"]
y = data["Time"]

plt.plot(x, y, marker='o')
plt.xlabel("Degree of Polynomial")
plt.ylabel("Execution Time (seconds)")
plt.title("Horner's Rule Performance (Recursive)")

# Text annotation on graph
plt.text(0.6 * max(x), 0.9 * max(y), "Time Complexity: O(n)", fontsize=12)

plt.grid(True)
plt.savefig("horner_graph.png")
plt.show()
