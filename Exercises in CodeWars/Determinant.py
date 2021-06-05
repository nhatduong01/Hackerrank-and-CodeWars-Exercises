'''
The link of this exercise is :
https://www.codewars.com/kata/52a382ee44408cea2500074c/train/python
'''
import numpy as np


def determinant(matrix):
    if len(matrix) == 1:
        return matrix[0][0]
    if len(matrix) == 2:
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]
    a1 = np.array(matrix)
    result = 0
    for i in range(0, len(matrix)):
        temp = np.concatenate((a1[1:, :i], a1[1:, i+1:]), axis=1)
        # print(temp)
        result += a1[0][i]*determinant(temp)*pow(-1, i)
        #print("The value at this moment is : ", result)
    return result


print(determinant([[1, 2, 3, 5], [4, -9, 6, 5], [7, 8, 9, 5], [2, 3, 4, -11]]))
