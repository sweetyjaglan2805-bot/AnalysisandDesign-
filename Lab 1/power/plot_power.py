import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("power_csv.txt")

data = data.sort_values(by="Exponent")

plt.figure()

plt.plot(data["Exponent"], data["Time"], marker='o')

plt.xlabel("Exponent (n)")
plt.ylabel("Execution Time (nanoseconds)")

plt.title("Fast Exponentiation Time vs Exponent\nTime Complexity: O(log n)")

plt.grid(True)

plt.savefig("power_graph.png")
plt.show()
