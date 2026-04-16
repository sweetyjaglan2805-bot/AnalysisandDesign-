import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("ball_csv.txt")
x = data["InitialVelocity"]
y = data["Time"]

plt.plot(x, y, marker='o')
plt.xlabel("Initial Velocity")
plt.ylabel("Execution Time (ns)")
plt.title("Ball Tips Simulation Performance")
plt.text(0.6*max(x),0.9* max(y), "Time Complexity: O(log n)", fontsize=12)
plt.grid(True)
plt.savefig("ball_graph.png")
plt.show()
