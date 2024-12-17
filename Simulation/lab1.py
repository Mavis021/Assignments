# SIMULATION OF THE CHEMICAL REACTION

import matplotlib.pyplot as plt
import numpy as np

# Ch1 + Ch2 = Ch3

# For simplicity we assume constant Temperature, pressure, humidity i.e. they have no effect in the rate of formation or decomposition


# Let A1, A2, A3 be the amount of Ch1, Ch2, and Ch3 respectively at any instant of time t.


iter = 200
A1 = np.ones(shape=(iter)) * 1
A2 = np.ones(shape=(iter)) * 2
A3 = np.ones(shape=(iter)) * 8

dt = 0.001
i = 0

k1 = 5
k2 = 3

for t in range(1, iter):
    A1[t] = A1[t-1] + (k2 * A3[t-1]-k1 * A1[t-1] * A2[t-1]) * dt
    A2[t] = A2[t-1] + (k2 * A3[t-1]-k1 * A1[t-1] * A2[t-1]) * dt
    A3[t] = A3[t-1] + (2* k1 * A1[t-1] * A2[t-1] - 2 * k2 * A3[t-1]) * dt

figure = plt.figure()
plt.plot(A1, label = "Amount of Ch1")
plt.plot(A2, label = "Amount of Ch2")
plt.plot(A3, label = "Amount of Ch3")

plt.legend()
plt.show()