# implementing a simple neuron in python

import numpy as np

# a Neuron class
class Neuron:

    def __init__(self, num_inputs):
        self.weights = np.random.rand(num_inputs)   # Iniitalizing with random weights
        self.bias = np.random.rand()    # Initializing bias randomly

    
    def activate(self, inputs):
        print(self.weights, self.bias)
        summation = np.dot(inputs, self.weights) + self.bias
        print("summation: ", summation)
        return 1 if summation > 0 else 0
    

# A neuron with 3 inputs
neuron = Neuron(3)

inputs = np.array([0.5, 0.3, 0.1])

output = neuron.activate(inputs)

print("OUTPUT: ", output)