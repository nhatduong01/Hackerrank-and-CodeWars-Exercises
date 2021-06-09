import random
import math


class Player:
    def __init__(self, letter):
        self.letter = letter

    def get_move(self, game):
        pass


class RandomComputerPlayer(Player):
    def __init__(self, letter):
        super().__init__(letter)

    def get_move(self, game):
        square = random.choice(game.available_move())
        return square


class HumanPlayer(Player):
    def __init__(self, letter):
        super().__init__(letter)

    def get_move(self, game):
        valid_square = False
        while not valid_square:
            square = input(self.letter + '\'s turn. Input move (0-8) :')
            try:
                val = int(square)
                if val not in game.available_move():
                    raise ValueError
                valid_square = True
            except:
                print('Invalid square. Try to play again.')
        return val
# I want to use Minimax to implement a smart Computer


class AwesomeComputer(Player):
    def __init__(self, letter):
        super().__init__(letter)

    def get_move(self, game):
        if (len(game.available_move())) == 9:
            square = random.choice(game.available_move())
            # we just random choose one
        else:
            # we use the minimax algorithm
            square = self.minimax(game, self.letter)['position']
        return square

    def minimax(self, state, player):
        max_player = self.letter  # yourself
        other_player = 'O' if player == 'X' else 'X'

        # first we want to check if the previous move is a winner
        max_player = self.letter
        other_player = 'O' if player == 'X' else 'X'
        if state.current_winner == other_player:
            return {'position': None, 'score': 1 * (state.num_empty_squares() + 1) if other_player ==
                    max_player else -1 * (state.num_empty_squares()+1)}
        elif not state.empty_square():
            return {'position': None, 'score': 0}
        if player == max_player:
            best = {'position': None, 'score': -math.inf}
        else:
            best = {'position': None, 'score': math.inf}
        for possible_moves in state.available_move():
            state.make_move(possible_moves, player)
            sim_score = self.minimax(state, other_player)
            state.board[possible_moves] = ' '
            state.current_winner = None
            sim_score['position'] = possible_moves
            # update the dictionary if necessary
            if player == max_player:
                if sim_score['score'] > best['score']:
                    best = sim_score
            else:
                if sim_score['score'] < best['score']:
                    best = sim_score
        return best
