# Implementing a minmax search in python

class Node():
    def __init__ (self, value):
        self.value = value
        self.left = None
        self.right = None

class Choice():
    def __init__ (self, move, value):
        self.move = move
        self.value = value

    def __str__ (self):
        return "Move: " + str(self.move) + " Value: " + str(self.value)
    

def build_tree(data):
    if not data:
        return None
    
    node = Node(data[0])
    if len(data) > 1:
        node.left = build_tree(data[1])
    if len(data) > 2:
        node.right = build_tree(data[2])
    return node

tree_data = [
    None,   # Root
    [
        -2, # 2nd layer Left
        [
            3, # 3rd layer Left
            [-8], # 4th layer Left
            [7] # 4th layer Right
        ],
        [
            20, # 3rd layer Right
            [15], # 4th layer Left
            [14] # 4th layer Right
        ]
    ],
    [
        10, # 2nd layer Right
        [
            -8, # 3rd layer Left
            [8], # 4th layer Left
            [-5] # 4th layer Right
        ],
        [
            -1, # 3rd layer Right
            [1],    # 4th layer Left
            [0] # 4th layer Right
        ]
    ]
]

root = build_tree(tree_data)

def print_tree(node, level=0):
    if node is not None:
        print_tree(node.right, level + 1)
        print(' ' * 4 * level + '->', node.value)
        print_tree(node.left, level + 1)

print_tree(root)


def minmax(node, ismax):
    if node.left is None and node.right is None:
        return Choice("end", node.value)
    
    left_choice = minmax(node.left, not ismax)
    right_choice = minmax(node.right, not ismax)

    if ismax:
        if left_choice.value > right_choice.value:
            return Choice("left", left_choice.value)
        else:
            return Choice("right", right_choice.value)
        
    else:
        if left_choice.value < right_choice.value:
            return Choice("left", left_choice.value)
        else:
            return Choice("right", right_choice.value)
        
# Simulation to play the minmax game
current_node = root
ismax = True

while (True):

    choice = minmax(current_node, ismax)
    
    if choice.move == "left":
        print("Player{} :: Move: Left with Value: {}".format( 1 if ismax else 2, str(current_node.left.value)))
        current_node = current_node.left

    elif choice.move == "right":
        print("Player{} :: Move: Right with Value: {}".format( 1 if ismax else 2, str(current_node.right.value)))
        current_node = current_node.right

    elif choice.move == "end":
        print ("Game ends with a score of " + str(choice.value))
        break

    # flip player turn
    ismax = not ismax