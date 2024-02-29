# A mcCulloch-Pitts neural network using Adaline Learning considering bipolar case

import numpy as np

class Adaline:

    def __init__(self, num_inputs, learning_rate=0.1):
        self.weights = np.random.rand(num_inputs)
        self.bias = np.random.rand()
        self.learning_rate = learning_rate

    def activate(self, inputs):
        net_inputs = np.dot(inputs, self.weights) + self.bias

        return 1 if net_inputs > 0 else -1
    
    def train(self, inputs, target):
        output = self.activate(inputs)
        error = target - output
        self.weights += self.learning_rate * error * inputs
        self.bias += self.learning_rate * error

    def getUpdates(self):
        print(f"Weights: {self.weights} Bias: {self.bias} Learning Rate: {self.learning_rate} \n")


def main():
    ch = input("1. AND \n 2. OR \n 3. NAND \n 4. NOR \n:")

    inputs = np.array([[-1, -1], [-1, 1], [1, -1], [1, 1]])

    if(ch == '1'):
        targets = np.array([-1, -1, -1, 1])
    elif(ch == '2'):
        targets = np.array([-1, 1, 1, 1])
    elif(ch == '3'):
        targets = np.array([1, 1, 1, -1])
    elif(ch == '4'):
        targets = np.array([1, -1, -1, -1])
    else:
        print("Error!")
        exit()
        
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