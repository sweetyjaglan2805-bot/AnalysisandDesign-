import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("ball_csv.txt")
data = data.sort_values("Velocity")
x = data["Velocity"]
y = data["Time"]

plt.plot(x, y, marker='o')
plt.xlabel("Initial Velocity")
plt.ylabel("Execution Time (ns)")
plt.title("Ball Tips Simulation Performance")
plt.grid(True)
plt.savefig("ball_graph.png")
plt.show()
