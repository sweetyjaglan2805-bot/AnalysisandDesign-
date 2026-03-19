import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("linearsearch_csv.txt")

# Separate cases
worst = data[data["Case"] == "Worst"]
average = data[data["Case"] == "Average"]

plt.figure(figsize=(8, 6))

plt.plot(worst["Size"], worst["Time"], marker='o', label="Worst Case")
plt.plot(average["Size"], average["Time"], marker='o', label="Average Case")

plt.xlabel("Array Size (n)")
plt.ylabel("Execution Time (ns)")
plt.title("Linear Search Performance")

# Write time complexity on graph
plt.text(max(worst["Size"]) * 0.4,
         max(worst["Time"]) * 0.8,
         "Time Complexity: O(n)",
         fontsize=12)

plt.legend()
plt.grid(True)
plt.savefig("linearsearch_graph.png")
plt.show()

