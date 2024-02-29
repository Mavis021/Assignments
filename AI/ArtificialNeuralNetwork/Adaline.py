# A McCulloch-Pitts neural network which behaves as AND function using Adaline Learning. Considering a Unipolar case

import numpy as np

# Adaline Learning
class Adaline:

    def __init__(self, num_inputs, learning_rate = 0.1 ):
        self.weights = np.random.rand(num_inputs)
        self.bias = np.random.rand()
        self.learning_rate = learning_rate

    def activate(self, inputs):
        net_inputs = np.dot(inputs, self.weights) + self.bias
        return 1 if net_inputs > 0 else 0
    

    def train(self, inputs, target):
        output = self.activate(inputs)
        error = target - output
        self.weights += self.learning_rate * error * inputs
        self.bias += self.learning_rate * error

    def getUpdates(self):
        
        print("Weights : ", self.weights, "\n bias : ", self.bias, "\n learning rate: ", self.learning_rate, "\n ")

def andData():
    # Inputs and Target Outputs of a AND function
    inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
    targets = np.array([0, 0, 0, 1])

    return inputs, targets

def orData():
    # Inputs and Target Outputs of a AND function
    inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
    targets = np.array([0, 1, 1, 1])

    return inputs, targets

def nandData():
    # Inputs and Target Outputs of a AND function
    inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
    targets = np.array([1, 1, 1, 0])

    return inputs, targets

def norData():
    # Inputs and Target Outputs of a AND function
    inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
    targets = np.array([1, 0, 0, 0])

    return inputs, targets

function_map = {
    '1': 'andData',
    '2': 'orData',
    '3': 'nandData',
    '4': 'norData'
}

def main():
    ch = input("1. AND \n 2. OR \n 3. NAND \n 4. NOR \n:")
    function = globals().get(function_map.get(ch))
    if function:
        inputs, targets = function()
    else:
        print("Function not found")
        exit()


    # A varing range of Neural Network parameters
    learning_rates = [0.01, 0.1, 0.5]
    epochs_list = [100, 500, 1000]

    for learning_rate in learning_rates:

        for epochs in epochs_list:

            Anding = Adaline(num_inputs=2, learning_rate=learning_rate)

            print("\n \n Before Training: ")
            Anding.getUpdates()

            # Training
            for epoch in range(epochs):
                for input_data, target in zip(inputs, targets):
                    Anding.train(input_data, target)
                
            print(f"After Training with {epochs} epoch cycle ")
            Anding.getUpdates()

            # Testing 
            for input_data, target in zip(inputs, targets):
                output = Anding.activate(input_data)
                print("Input:", input_data, "Target:", target, "Output:", output)


if __name__ == "__main__":
    main()