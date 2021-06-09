from player import HumanPlayer, RandomComputerPlayer, AwesomeComputer


class TicTacToe:
    def __init__(self):
        self.board = [' ' for _ in range(9)]
        self.current_winner = None

    def print_board(self):
        for row in [self.board[i*3: (i+1)*3] for i in range(3)]:
            print("| " + " | ".join(row) + ' |')

    @staticmethod
    def print_board_num():
        number_board = [[str(i) for i in range(j*3, (j+1)*3)]
                        for j in range(3)]
        for row in number_board:
            print("| " + " | ".join(row) + ' |')

    def available_move(self):
        moves = []
        for (i, x) in enumerate(self.board):
            if x == ' ':
                moves.append(i)
        return moves

    def empty_square(self):
        return ' ' in self.board

    def num_empty_squares(self):
        return len(self.board)

    def make_move(self, square, letter):
        if self.board[square] == ' ':
            self.board[square] = letter
            if self.winner(square, letter):
                self.current_winner = letter
            return True
        return False

    def winner(self, square, letter):
        row_idx = square // 3
        row = self.board[row_idx*3: (row_idx+1)*3]
        if all([spot == letter for spot in row]):
            return True
        col_idx = square % 3
        column = [self.board[col_idx + i * 3] for i in range(3)]
        if all([spot == letter for spot in column]):
            return True

        # Check the diagonal of the board
        fist_diagonal = [self.board[0], self.board[4], self.board[8]]
        if all([spot == letter for spot in fist_diagonal]):
            return True
        second_diagonal = [self.board[2], self.board[4], self.board[6]]
        if all([spot == letter for spot in second_diagonal]):
            return True
        return False


def play(game, x_player, o_player,  print_game=True):
    if print_game:
        game.print_board_num()
    letter = 'X'
    while game.empty_square():
        if letter == 'O':
            square = o_player.get_move(game)
        else:
            square = x_player.get_move(game)
        if game.make_move(square, letter):
            if print_game:
                print(letter + f' makes a move to square  {square}')
                game.print_board()
                print(' ')
            if game.current_winner:
                if print_game:
                    print(letter + ' won')
                return letter
            letter = 'O' if letter == 'X' else 'X'
    if print_game:
        print('It\'s a tie!')


if __name__ == '__main__':
    x_player = HumanPlayer('X')
    o_player = AwesomeComputer('O')
    t = TicTacToe()
    play(t, x_player, o_player, True)
