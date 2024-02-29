import matplotlib.pyplot as plt

def draw_xor_mlp():
    # Create the figure and axis objects
    fig, ax = plt.subplots(figsize=(8, 6))

    # Plot the XOR MLP
    ax.scatter(0, 0.6, marker='o', s=100, label='Input A')
    ax.scatter(0, 0.4, marker='o', s=100, label='Input B')
    ax.scatter(0.5, 0.8, marker='o', s=100, label='Hidden Neuron 1')
    ax.scatter(0.5, 0.2, marker='o', s=100, label='Hidden Neuron 2')
    ax.scatter(1, 0.5, marker='o', s=100, label='Output Neuron')

    # Annotate the connections
    ax.annotate('', xy=(0, 0.6), xytext=(0.5, 0.8), arrowprops=dict(arrowstyle='->'))
    ax.annotate('', xy=(0, 0.4), xytext=(0.5, 0.8), arrowprops=dict(arrowstyle='->'))
    ax.annotate('', xy=(0, 0.6), xytext=(0.5, 0.2), arrowprops=dict(arrowstyle='->'))
    ax.annotate('', xy=(0, 0.4), xytext=(0.5, 0.2), arrowprops=dict(arrowstyle='->'))
    ax.annotate('', xy=(0.5, 0.8), xytext=(1, 0.5), arrowprops=dict(arrowstyle='->'))
    ax.annotate('', xy=(0.5, 0.2), xytext=(1, 0.5), arrowprops=dict(arrowstyle='->'))

    # Set axis limits and labels
    ax.set_xlim([-0.1, 1.1])
    ax.set_ylim([0, 1])
    ax.set_xticks([])
    ax.set_yticks([])
    ax.set_aspect('equal')
    ax.legend(loc='upper left')

    # Show the plot
    plt.title('XOR Multi-Layer Perceptron (MLP)')
    plt.show()

draw_xor_mlp()