# Perceptron with two input units

import numpy as np

# Perceptron class
class Perceptron:

    def __init__(self, num_inputs, learning_rate = 0.1):
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
        
        print("Weights : ", self.weights, "\n bias : ", self.bias, "\n learning rate: ", self.learning_rate)


def main():

    # Defining the inputs and targets for OR function
    inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
    targets = np.array([0, 0, 0, 1])     

    # creating a perceptron model with 2 inputs units
    perceptron = Perceptron(num_inputs= 2, learning_rate= 0.1)

    print("Before Training : \n", perceptron.getUpdates())

    # Training the perceptron model
    epochs = 100
    for each in range(epochs):
        for input_data, target in zip(inputs, targets):
            perceptron.train(input_data, target)

    print("After Training : \n", perceptron.getUpdates())


    # Testing the trained model
    for input_data, target in zip(inputs, targets):
        output = perceptron.activate(input_data)
        print("Input:", input_data, "Target: ", target, "Output: ", output)


if __name__ == "__main__":
    main()