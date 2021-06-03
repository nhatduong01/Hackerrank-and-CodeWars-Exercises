def prec(Operator):
    if(Operator == '^'):
        return 3
    elif (Operator == '/' or Operator == '*'):
        return 2
    elif Operator == '+' or Operator == '-':
        return 1
    elif Operator == '(' or Operator == ')':
        return 0
    else:
        return -1


def to_postfix(infix):
    stack = []

    """Convert infix to postfix"""
    result = ""
    for i in infix:
        if i == ' ':
            continue
        if prec(i) == -1:
            result += i
        elif prec(i) == 0:
            if i == '(':
                stack.append(i)
            else:
                while(stack[-1] != '('):
                    result += stack.pop()
                stack.pop()
        else:
            if (len(stack) == 0):
                stack.append(i)
            elif (i == '^' and stack[-1] == '^'):
                stack.append(i)
            else:
                while len(stack) != 0 and prec(i) <= prec(stack[-1]):
                    result += stack.pop()
                stack.append(i)
    while(len(stack) != 0):
        result += stack.pop()
    return result


print(to_postfix("( ( ( ( 1 ) * 2 ) ) )"))
'''
test.assert_equals(to_postfix("12+7*5"), "275*+")
test.assert_equals(to_postfix("3*3/(7+)"), "33*71+/")
test.assert_equals(to_postfix("5+(6-2)*9+3^(7-1)"), "562-9*+371-^+")
test.assert_equals(to_postfix("(5-4-1)+9/5/2-7/1/7"), "54-1-95/2/+71/7/-")
test.assert_equals(to_postfix("1^2^3"), "123^^")
'''
