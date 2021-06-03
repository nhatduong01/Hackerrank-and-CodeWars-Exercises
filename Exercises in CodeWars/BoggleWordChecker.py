# def location(board, character):
#     for i in range(0, len(board)):
#         if character in board[i]:
#             return i, board[i].index(character)
#     return -1, -1


# def FindLocation(board, character, row, column):
#     for i in range(max(0, row-1), min(len(board), row+2)):
#         for j in range(max(0, column-1), min(len(board), column+2)):
#             if board[i][j] == character:
#                 return i, j
#     return -1, -1


# def find_word(board, word):
#     idx_word = 0
#     row = 0
#     column = 0
#     row, column = location(board, word[idx_word])
#     print("The first location is :", row, " ", column)
#     if row == -1:
#         return False
#     idx_word += 1
#     while(idx_word != len(word)):
#         row, column = FindLocation(board, word[idx_word], row, column)
#         print("The next location is :", row, " ", column)
#         if row == -1:
#             return False
#         idx_word += 1
#     return True
found = False

str = ""


def FindUntil(board, flag, row, column, word):
    global str
    print(flag)
    print("The string is : ", str)
    flag[row][column] = True
    str = str + board[row][column]
    if str == word:
        global found
        found = True
    for i in range(max(0, row-1), min(len(board), row+2)):
        for j in range(max(0, column-1), min(len(board), column+2)):
            if flag[i][j] == False:
                FindUntil(board, flag, i, j, word)
    str = str[: len(str) - 1]
    flag[row][column] = False


def find_word(board, word):
    flag = [[False]*len(board)]*len(board)
    for i in range(0, len(board)):
        for j in range(0, len(board)):
            FindUntil(board, flag, i, j, word)
    return found


print(find_word([["E", "A", "R", "A"],
                 ["N", "L", "E", "C"],
                 ["I", "A", "I", "S"],
                 ["B", "Y", "O", "R"]], "BAILER"))
