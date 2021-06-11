'''
This data can be found on:
https://www.codewars.com/kata/5296bc77afba8baa690002d7/train/python
'''


def find_empty(puzzle):
    for i in range(0, 9):
        for j in range(0, 9):
            if puzzle[i][j] == 0:
                return i, j
    return None, None


def is_valid(puzzle, row, column, guess):
    # check column
    column_values = [puzzle[i][column] for i in range(0, 9)]
    if guess in column_values:
        return False
    row_values = puzzle[row]
    if guess in row_values:
        return False
    start_row = (row // 3)*3
    start_column = (column//3)*3
    for i in range(start_row, start_row + 3):
        for j in range(start_column, start_column + 3):
            if puzzle[i][j] == guess:
                return False
    return True


def solve_sudoku(puzzle):
    row, column = find_empty(puzzle)
    if row is None:
        return True
    for guess in range(1, 10):
        if is_valid(puzzle, row, column, guess):
            puzzle[row][column] = guess
            if solve_sudoku(puzzle):
                return True
        puzzle[row][column] = 0
    return False


def sudoku(puzzle):
    """return the solved puzzle as a 2d array of 9 x 9"""
    solve_sudoku(puzzle)
    return puzzle


if __name__ == '__main__':
    puzzle = [
        [5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0],
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 1, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9]]

    solution = [
        [5, 3, 4, 6, 7, 8, 9, 1, 2],
        [6, 7, 2, 1, 9, 5, 3, 4, 8],
        [1, 9, 8, 3, 4, 2, 5, 6, 7],
        [8, 5, 9, 7, 6, 1, 4, 2, 3],
        [4, 2, 6, 8, 5, 3, 7, 9, 1],
        [7, 1, 3, 9, 2, 4, 8, 5, 6],
        [9, 6, 1, 5, 3, 7, 2, 8, 4],
        [2, 8, 7, 4, 1, 9, 6, 3, 5],
        [3, 4, 5, 2, 8, 6, 1, 7, 9]]

    puzzle2 = [
        [5, 6, 0, 8, 4, 7, 0, 0, 0],
        [3, 0, 9, 0, 0, 0, 6, 0, 0],
        [0, 0, 8, 0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 8, 0, 0, 4, 0],
        [7, 9, 0, 6, 0, 2, 0, 1, 8],
        [0, 5, 0, 0, 3, 0, 0, 9, 0],
        [0, 0, 0, 0, 0, 0, 2, 0, 0],
        [0, 0, 6, 0, 0, 0, 8, 0, 7],
        [0, 0, 0, 3, 1, 6, 0, 5, 9]]

    solution2 = [
        [5, 6, 1, 8, 4, 7, 9, 2, 3],
        [3, 7, 9, 5, 2, 1, 6, 8, 4],
        [4, 2, 8, 9, 6, 3, 1, 7, 5],
        [6, 1, 3, 7, 8, 9, 5, 4, 2],
        [7, 9, 4, 6, 5, 2, 3, 1, 8],
        [8, 5, 2, 1, 3, 4, 7, 9, 6],
        [9, 3, 5, 4, 7, 8, 2, 6, 1],
        [1, 4, 6, 2, 9, 5, 8, 3, 7],
        [2, 8, 7, 3, 1, 6, 4, 5, 9]]

    puzzle3 = [
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 1, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9],
        [5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0]]

    solution3 = [
        [8, 5, 9, 7, 6, 1, 4, 2, 3],
        [4, 2, 6, 8, 5, 3, 7, 9, 1],
        [7, 1, 3, 9, 2, 4, 8, 5, 6],
        [9, 6, 1, 5, 3, 7, 2, 8, 4],
        [2, 8, 7, 4, 1, 9, 6, 3, 5],
        [3, 4, 5, 2, 8, 6, 1, 7, 9],
        [5, 3, 4, 6, 7, 8, 9, 1, 2],
        [6, 7, 2, 1, 9, 5, 3, 4, 8],
        [1, 9, 8, 3, 4, 2, 5, 6, 7]]
    if sudoku(puzzle3) == solution3:
        print("yes")
