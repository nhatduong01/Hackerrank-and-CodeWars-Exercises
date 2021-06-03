def isFloat(str_val):
    try:
        float(str_val)
        return True
    except ValueError:
        return False


def prec(Operator):
    if (Operator == '/' or Operator == '*'):
        return 2
    elif Operator == '+' or Operator == '-':
        return 1
    elif Operator == '(' or Operator == ')':
        return 0


def to_postfix(infix):
    stack = []
    result = []
    i = 0
    while i < len(infix):
        if infix[i] == ' ':
            i += 1
            continue
        if infix[i].isnumeric():
            num = ""
            while(i < len(infix) and (infix[i].isnumeric() or infix[i] == '.')):
                num += infix[i]
                i += 1
            result.append(float(num))
            continue
        elif prec(infix[i]) == 0:
            if infix[i] == '(':
                stack.append(infix[i])
            else:
                while stack[-1] != '(':
                    result.append(stack.pop())
                stack.pop()
        else:
            if(len(stack) == 0):
                stack.append(infix[i])
            else:
                while(len(stack) != 0 and prec(infix[i]) <= prec(stack[-1])):
                    result.append(stack.pop())
                stack.append(infix[i])
        i += 1
    while(len(stack) != 0):
        result.append(stack.pop())
    return result


class Calculator(object):

    def evaluate(self, string):
        new_stack = to_postfix(string)
        storage_stack = []
        for i in new_stack:
            if isFloat(i):
                storage_stack.append(float(i))
            else:
                first = storage_stack.pop()
                second = storage_stack.pop()
                result = 0
                if i == '+':
                    result = second + first
                elif i == '-':
                    result = second - first
                elif i == '*':
                    result = second*first
                else:
                    result = second/first
                storage_stack.append(result)
        return storage_stack.pop()


print(Calculator().evaluate("1.1 * 2.2 * 3.3"))
#print(to_postfix("1.1 + 2.2 + 3.3"))
