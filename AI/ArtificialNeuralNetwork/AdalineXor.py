# Implmention of XOR logic function using 2 layers

import numpy as np

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
        

def train_perceptron(perceptron, inputs, targets):

    print("Before Training : ",)
    perceptron.getUpdates()

    # Training the perceptron model
    epochs = 100
    for each in range(epochs):
        for input_data, target in zip(inputs, targets):
            perceptron.train(input_data, target)

    print("After Training : ")
    perceptron.getUpdates()

    output_list = []
    # Testing the trained model
    for input_data, target in zip(inputs, targets):
        output = perceptron.activate(input_data)
        output_list.append(output)
        print("Input:", input_data, "Target: ", target, "Output: ", output)
    
    return output_list


def main():

    # creating a perceptron model with 2 inputs units
    perceptron = Adaline(num_inputs= 2, learning_rate= 0.1)

    inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])


    targets = [0, 0, 1, 0]
    z1 = train_perceptron(perceptron, inputs, targets)

    targets = [0, 1, 0, 0]
    z2 = train_perceptron(perceptron, inputs, targets)

    # Train for OR 
    targets = [0, 1, 1, 1]
    temp = train_perceptron(perceptron, inputs, targets)

    # now that the weights and biases are updated for OR function, sending the intermediate inputs for ORring 
    intermediate = np.array( [[z1,z2] for z1, z2 in zip(z1,z2)])
    targets = [0, 1, 1, 0]

    print("XOR OUTPUT:")
    for input_data, target, actual_input in zip(intermediate, targets, inputs):
        output = perceptron.activate(input_data)
        print("Input:", actual_input, "Intermediate: ", input_data, "Target: ", target, "Output: ", output)


if __name__ == "__main__":
    main()