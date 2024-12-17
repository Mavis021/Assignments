import matplotlib.pyplot as plt
from scipy import signal
import numpy as np

k = 10  
m = 11 
D = [4, 8, 16, 20, 40, 80]  

# Critical Damping Coefficient
D_c = 2 * ((m * k) ** 0.5)

if D_c not in D:
    D.append(D_c)
    D.sort()

t = np.linspace(0, 11, 1000) 

plt.figure(figsize=(10, 6))

for i in range(len(D)):
    # State-space matrices
    A = [[0, 1], [-k / m, -D[i] / m]]  
    B = [[0], [k / m]]                
    C = [1, 0]                       
    D_matrix = [0]                   
    
    my_ss = signal.StateSpace(A, B, C, D_matrix)
    
    t_out, y_out= signal.step(my_ss, T=t)
    
    if D[i] == D_c:
        plt.plot(t_out, y_out, label=f'D = {D[i]:.2f} (Critical Damping)', linestyle='--', color='red', linewidth=2)
    else:
        plt.plot(t_out, y_out, label=f'D = {D[i]}')

plt.title("Mass-Spring-Damper System - Step Response")
plt.xlabel("Time (s)")
plt.ylabel("Displacement (m)")
plt.legend()
plt.grid()
plt.show()
