'''
This kata can be found on :
https://www.codewars.com/kata/5a0573c446d8435b8e00009f/train/cpp
'''
# Implement using linear transformation
import numpy as np
result = np.array([[0], [0]])
current_dir = np.array([[-1], [0]])
rotate_left = np.array([[0, -1], [1, 0]])
rotate_right = np.array([[0, 1], [-1, 0]])
rotate_back = np.array([[-1, 0], [0, -1]])


def i_am_here(path):
    global result
    global current_dir
    i = 0
    while(i < len(path)):
        steps = ""
        if path[i].isnumeric():
            while(i < len(path) and path[i].isnumeric()):
                steps += path[i]
                i += 1
            result += current_dir*int(steps)
        else:
            if path[i] == 'r':
                current_dir = np.dot(rotate_right, current_dir)
            elif path[i] == 'l':
                current_dir = np.dot(rotate_left, current_dir)
            else:
                current_dir = np.dot(rotate_back, current_dir)
            i += 1
            while(i < len(path) and path[i].isnumeric()):
                steps += path[i]
                i += 1
            if steps != '':
                result += current_dir*int(steps)
    a = [result[0][0], result[1][0]]
    return a


print(i_am_here(""))
print(i_am_here("RLrl"))
print(i_am_here("r5L2l4"))
print(i_am_here("r5L2l4"))
print(i_am_here("10r5r0"))
print(i_am_here("10r5r0"))
