# import pandas as pd
# import matplotlib.pyplot as plt

# data = pd.read_csv("sum_csv.txt")

# x = data["ArraySize"]   # input size
# y = data["Time"]        # execution time

# plt.plot(x, y, marker='o')
# plt.xlabel("Array Size (n)")
# plt.ylabel("Execution Time (ns)")
# plt.title("Recursive Sum Performance")
# plt.grid(True)
# plt.savefig("sum_graph.png")
# plt.show()
import pandas as pd
import matplotlib.pyplot as plt

# Read CSV
data = pd.read_csv("sum_csv.txt")

x = data["Size"]        # Input size (n)
rec_time = data["RecTime"]
iter_time = data["IterTime"]

plt.figure()
plt.plot(x, rec_time, marker='o', label="Recursive Sum")
plt.plot(x, iter_time, marker='s', label="Iterative Sum")

plt.xlabel("Array Size (n)")
plt.ylabel("Execution Time (ns)")
plt.title("Recursive vs Iterative Sum Performance")

# Time complexity text
plt.text(0.6*max(x), 0.8*max(max(rec_time), max(iter_time)),
         "Time Complexity: O(n)", fontsize=12)

plt.legend()
plt.grid(True)
plt.savefig("sum_graph.png")
plt.show()

