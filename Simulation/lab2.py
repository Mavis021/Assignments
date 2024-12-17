
import matplotlib.pyplot as plt
import numpy as np

def response(A11, A21, A22, B1, B2, h):
    n = 500
    V1 = np.zeros(n)
    V2 = np.zeros(n)

    for i in range(n - 1):
        # V1 RK4
        k1_v1 = A11 * V1[i] + B1 * ein[i]
        k2_v1 = A11 * (V1[i] + h * k1_v1 / 2) + B1 * ein[i]
        k3_v1 = A11 * (V1[i] + h * k2_v1 / 2) + B1 * ein[i]
        k4_v1 = A11 * (V1[i] + h * k3_v1) + B1 * ein[i]
        V1[i + 1] = V1[i] + h * (k1_v1 + 2 * k2_v1 + 2 * k3_v1 + k4_v1) / 6

        # V2 RK4
        k1_v2 = A21 * V1[i] + A22 * V2[i] + B2 * ein[i]
        k2_v2 = A21 * (V1[i] + h * k1_v1 / 2) + A22 * (V2[i] + h * k1_v2 / 2) + B2 * ein[i]
        k3_v2 = A21 * (V1[i] + h * k2_v1 / 2) + A22 * (V2[i] + h * k2_v2 / 2) + B2 * ein[i]
        k4_v2 = A21 * (V1[i] + h * k3_v1) + A22 * (V2[i] + h * k3_v2) + B2 * ein[i]
        V2[i + 1] = V2[i] + h * (k1_v2 + 2 * k2_v2 + 2 * k3_v2 + k4_v2) / 6
    return V1, V2


def plot_response(V1, V2):
    plt.plot(t, V1, label="V1 (Input Side)")
    plt.plot(t, V2, label="V2 (Output Side)")
    plt.xlabel("Time (s)")
    plt.ylabel("Voltage (V)")
    plt.title("LAB 2")
    plt.legend()
    plt.show()

A11, A21, A22 = -50, -10000, -21.5
B1, B2 = 50, 10000
h = 0.0002
n = 500

t = np.linspace(0, n * h, n)

ein = np.ones(n) * 1.5 # e_in(t) = 1.5 for t >= 0
V1, V2 = response(A11, A21, A22, B1, B2, h)
plot_response(V1, V2)