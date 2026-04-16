import pandas as pd
import matplotlib.pyplot as plt

# Read CSV file
data = pd.read_csv("knap_csv.txt")

# Separate methods
weight = data[data["Method"] == "Weight"]
profit = data[data["Method"] == "Profit"]
ratio  = data[data["Method"] == "Ratio"]

plt.figure()

plt.plot(weight["Size"], weight["Time(sec)"], marker='o')
plt.plot(profit["Size"], profit["Time(sec)"], marker='s')
plt.plot(ratio["Size"],  ratio["Time(sec)"], marker='^')

plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (seconds)")
plt.title("Quick Sort + Knapsack Execution Time Comparison")

plt.legend(["Weight", "Profit", "Ratio"])
plt.grid(True)
plt.text(
    max(data["Size"]) * 0.6,
    max(data["Time(sec)"]) * 0.8,
    "Time Complexity: O(n log n)",
    fontsize=10,
)

# Save graph
plt.savefig("execution_time.png")

plt.show()