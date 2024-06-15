# Implementing a Tic-Tac-Toe bot in Python

import enum

class Player(enum.Enum):
    x = 1
    o = 2

    @property
    def other(self):
        return Player.x if self == Player.o else Player.o
    

import copy

MARKER_TO_CHAR = {
    None : ' . ',
    Player.x : ' x ',
    Player.o: ' o '
}

class Board():
    def __init__(self):
        self.dimension = 3
        self.grid = [[None for _ in range(self.dimension)] for _ in range(self.dimension)]
        self.moves = []

    def print(self):
        print()
        for row in range(self.dimension):
            line = []
            for col in range(self.dimension):
                line.append(MARKER_TO_CHAR[self.grid[row][col]])
            print('%s' % ('|'.join(line)))

    def has_won(self):
        # least move needed is 5 untile one of the player makes the win
        if (len(self.moves) < 5):
            return None
        
        # Row check
        for row in range(self.dimension):
            unique_rows = set(self.grid[row])
            if len(unique_rows) == 1 and None not in unique_rows:
                return unique_rows.pop()
            
        # Column check
        for col in range(self.dimension):
            unique_cols = set()
            for row in range(self.dimension):
                unique_cols.add(self.grid[row][col])

            if len(unique_cols) == 1 and None not in unique_cols:
                return unique_cols.pop()
            
        # Forward and Backward Diagonal check
        forward_diagonal = set()
        forward_diagonal.add(self.grid[2][0])
        forward_diagonal.add(self.grid[1][1])
        forward_diagonal.add(self.grid[0][2])

        if len(forward_diagonal) == 1 and None not in forward_diagonal:
            return forward_diagonal.pop()
        
        backward_diagonal = set()
        backward_diagonal.add(self.grid[0][0])
        backward_diagonal.add(self.grid[1][1])
        backward_diagonal.add(self.grid[2][2])

        if len(backward_diagonal) == 1 and None not in backward_diagonal:
            return backward_diagonal.pop()
        
        return None
    
    def make_move(self, row, col, player):
        if self.is_space_empty(row, col):
            self.grid[row][col] = player
            self.moves.append((row, col))
        else:
            raise Exception('Invalid Move')
        
    def last_move(self):
        return self.moves[-1]
    
    def is_space_empty(self, row, col):
        return self.grid[row][col] == None
    
    def get_legal_moves(self):
        choices = []
        for row in range(self.dimension):
            for col in range(self.dimension):
                if self.is_space_empty(row, col):
                    choices.append([row, col])
        return choices
    
    def __deepcopy__(self, memodict={}):
        new_board = Board()
        new_board.grid = copy.deepcopy(self.grid)
        new_board.moves = copy.deepcopy(self.moves)
        return new_board


class Game():
    def __init__(self, num_of_games):
        self.num_of_games = num_of_games
        self.x_wins = 0
        self.o_wins = 0
        self.ties = 0

    def simulate(self, xbot, obot, print_game = False):
        for _ in range(self.num_of_games):
            board = Board()
            
            current_turn = Player.x
            winner = None

            for i in range(9):
                choice = []

                if current_turn == xbot.player:
                    choice = xbot.select_move(board)

                    board.make_move(choice[0], choice[1], current_turn)
                    board.print()
                else:
                    choice = obot.select_move(board)
                    
                    board.make_move(choice[0], choice[1], current_turn)
                    board.print()

                winner = board.has_won()

                if winner is not None:
                    if winner == Player.x:
                        print("BOT WINS\n")
                    else:
                        print("HUMAN WINS \n")
                    break
                elif i == 8:
                    print('Tie')
                    break

                current_turn = current_turn.other

            # if winner == Player.x:
            #     self.x_wins = self.x_wins + 1
            # elif winner == Player.o:
            #     self.o_wins = self.o_wins + 1
            # else:
            #     self.ties  = self.ties + 1

            # print('X wins: %d, O wins: %d, Ties: %d' % (self.x_wins, self.o_wins, self.ties))


import random

class RandomBot():
    def __init__(self, player):
        self.player = player

    def select_move(self, board):
        candidates = board.get_legal_moves()

        clear_screen()
        print ("\n PLAYER 1 : NOOB BOT's Turn")
        return random.choice(candidates)

class Choice():
    def __init__(self, move, value, depth):
        self.move = move
        self.value = value
        self.depth = depth

    def __str__(self):
        return 'Choice(%s, %s, %s)' % (self.move, self.value, self.depth)

class MinimaxBot():
    def __init__(self, player):
        self.player = player

    def minmax(self, board, is_max, current_player, depth):
        winner = board.has_won()
        if winner == self.player:
            return Choice(board.last_move(), 10 - depth, depth)
        elif winner == self.player.other:
            return Choice(board.last_move(), -10 + depth, depth)
        elif len(board.moves) == 9:
            return Choice(board.last_move(), 0, depth)
        
        candidate_choices = []
        candidates = board.get_legal_moves()

        for i in range(len(candidates)):
            row = candidates[i][0]
            col = candidates[i][1]
            newboard = copy.deepcopy(board)
            newboard.make_move(row, col, current_player)
            result = self.minmax(newboard, not is_max, current_player.other, depth + 1)
            result.move = newboard.last_move()
            candidate_choices.append(result)

        max_choice = None
        max_value = -100
        min_choice = None
        min_value = 100

        for i in range(len(candidate_choices)):
            choice = candidate_choices[i]
            if (is_max and choice.value > max_value):
                max_choice = choice
                max_value = choice.value
            elif not is_max and choice.value < min_value:
                min_choice = choice
                min_value = choice.value
        
        if is_max:
            return max_choice
        else:
            return min_choice
        
    def select_move(self, board):
        clear_screen()
        print ("\n PLAYER 1 : PRO BOT's Turn")
        choice = self.minmax(board, True, self.player, 0)
        return choice.move




coordinates = [[0, 0], [0, 1], [0, 2], [1, 0], [1, 1], [1, 2], [2, 0], [2, 1], [2, 2], [3, 3]]

class Human():
    def __init__(self, player):
        self.player = player

    def select_move(self, board):
        candidates = board.get_legal_moves()
        index = 0

        # print('Legal Moves: ', candidates)
        index = int(input('Select index: '))
        index = index - 1

        while coordinates[index] not in candidates:
            print('Invalid Move')
            index = int(input('Select index: '))

            if index > 0 and index < 10:
                index = index - 1
            else:
                index = 9
                continue
        

        clear_screen()
        print ("\n Player O: YOUR MOVE ")
        return coordinates[index]



import os
from datetime import datetime

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def main():
    dateTimeObj = datetime.now()
    print(dateTimeObj)

    clear_screen()
    obot = Human(Player.o)
    print("Welcome to Ticticbot game! \n You are Player o \n  | 1 | 2 | 3 | \n  | 4 | 5 | 6 | \n  | 7 | 8 | 9 |")


    game = Game(1)
    prompt = input(" CHOOSE YOUR OPPONENT: \n 1 : Play with noob bot\n 2 : Play with pro bot \n 3 : Quit \n Choose One : ")
    while prompt != '3':
        if prompt == '1':
            xbot = RandomBot(Player.x)
            print("noobBot vs Human")
        elif prompt == '2':
            xbot = MinimaxBot(Player.x)
            print("proBot vs Human")
        else:
            print("Invalid Choice")
            continue


        game.simulate(xbot, obot, True)
        prompt = input(" CHOOSE YOUR OPPONENT: \n 1 : Play with noob bot\n 2 : Play with pro bot \n 3 : Quit \n Choose One : ")
        clear_screen()

    dateTimeObj = datetime.now()
    print(dateTimeObj)

if __name__ == '__main__':
    main()