'''
This kata can be found on :
https://www.codewars.com/kata/52a78825cdfc2cfc87000005/train/python
'''


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


def analyse(string):
    index = 0
    if ' ' in string:
        while(index < len(string)):
            if string[index] == ' ':
                string = string[:index] + string[index+1:]
            index += 1
    while (string[0] == '(' and string[len(string) - 1] == ')'):
        stack = []
        stack.append(string[0])
        counter = 1
        while len(stack):
            if string[counter] == '(':
                stack.append(string[counter])
            elif string[counter] == ')':
                stack.pop()
            counter += 1
        if counter == len(string):
            string = string[1:len(string)-1]
        else:
            break
    i = 0
    while(i < len(string)):
        if string[i] == '-':
            last_oper = i - 1
            if string[i+1] == '(':
                stack = []
                stack.append(string[i+1])
                j = i+2
                while len(stack):
                    if string[j] == '(':
                        stack.append(string[j])
                    elif string[j] == ')':
                        stack.pop()
                    j += 1
                new_string = string[i+2:j - 1]
                new_string = analyse(new_string)
                # if (j < len(string) and (string[j] == '*' or string[j] == '/')):
                #     i += 1
                #     continue
                idx = 0
                while(idx < len(new_string)):
                    if new_string[idx] == '(':
                        stack.append(new_string[idx])
                    elif new_string[idx] == ')':
                        stack.pop()
                    elif new_string[idx] == '+' and len(stack) == 0:
                        new_string = new_string[:idx] + \
                            '-' + new_string[idx+1:]
                    elif new_string[idx] == '-' and len(stack) == 0:
                        new_string = new_string[:idx] + \
                            '+' + new_string[idx+1:]
                    idx += 1
                if (last_oper >= 0 and (string[last_oper] == '*' or string[last_oper] == '/')) or (j < len(string) and (string[j] == '*' or string[j] == '/')):
                    if '-' in new_string or '+' in new_string:
                        string = string[:i]+'(' + new_string + string[j-1:]
                    else:
                        string = string[:i+1] + new_string + string[j:]
                    i = j
                    continue
                idx = i + 2
                next_char = string[idx]
                if next_char.isnumeric():
                    string = string[:i+1] + new_string + string[j:]
                else:
                    string = string[:i] + new_string + string[j:]
            else:
                idx = i + 1
                next_char = string[idx]
                if (next_char == '+'):
                    string = string[:i] + '-' + string[idx+1:]
                elif(next_char == '-'):
                    string = string[:i] + '+' + string[idx + 1:]
        elif (string[i] == '+'):
            last_oper = i-1
            idx = i + 1
            next_char = string[idx]
            if (next_char == '+' or next_char == '-'):
                string = string[:i] + string[idx:]
                i -= 1
            elif(next_char == '('):
                stack = []
                stack.append(next_char)
                j = i + 2
                while j < len(string) and len(stack):
                    if (string[j] == '('):
                        stack.append(string[j])
                    elif string[j] == ')':
                        stack.pop()
                    j += 1
                if (j < len(string) and (string[j] == '*' or string[j] == '/')):
                    i += 1
                    continue
                string = string[:i+1] + string[i+2:j-1] + string[j:]
                i -= 1
        i += 1
    return string


def to_postfix(infix):
    infix = analyse(infix)
    stack = []
    result = []
    i = 0
    oper = True
    while i < len(infix):
        if infix[i] == '+' and oper:
            last_oper = i-1
            num = ""
            temp = i
            i += 1
            while(i < len(infix) and (infix[i].isnumeric() or infix[i] == '.')):
                num += infix[i]
                i += 1
            if (last_oper >= 0 and (infix[last_oper] == '*' or infix[last_oper] == '/' or infix[last_oper] == '(')) or temp == 0:
                result.append(float(num))
            else:
                i = temp
            oper = False
            continue
        if infix[i] == '-' and oper:
            last_oper = i - 1
            num = "-"
            temp = i
            i += 1
            while(i < len(infix) and (infix[i].isnumeric() or infix[i] == '.')):
                num += infix[i]
                i += 1
            if (last_oper >= 0 and (infix[last_oper] == '*' or infix[last_oper] == '/' or infix[last_oper] == '(')) or temp == 0:
                result.append(float(num))
            else:
                i = temp
            oper = False
            continue
        if infix[i].isnumeric():
            num = ""
            while(i < len(infix) and (infix[i].isnumeric() or infix[i] == '.')):
                num += infix[i]
                i += 1
            result.append(float(num))
            oper = False
            continue
        elif prec(infix[i]) == 0:
            oper = True
            if infix[i] == '(':
                stack.append(infix[i])
            else:
                while stack[-1] != '(':
                    result.append(stack.pop())
                stack.pop()
        else:
            if(infix[i] == '*' or infix[i] == '/'):
                oper = True
            else:
                oper = False
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


def calc(string):
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


#print(calc("1 - -1"))
#print(analyse("4 - (6 + 9 - ( 7- 12 )  -8 -(6*10) ) +-23 -(- 24) "))
tests = [
    ['12*-1', -12],
    ['12* 123/-(-5 + 2)', 492],
    ['((80 - (19)))', 61],
    ['(1 - 2) + -(-(-(-4)))', 3],
    ['1 - -(-(-(-4)))', -3],
    ['12* 123/(-5 + 2)', -492],
    ['(123.45*(678.90 / (-2.5+ 11.5)-(((80 -(19))) *33.25)) / 20) - (123.45*(678.90 / (-2.5+ 11.5)-(((80 -(19))) *33.25)) / 20) + (13 - 2)/ -(-11) ', 1],
    ['1+1', 2],
    ['1 - 1', 0],
    ['1* 1', 1],
    ['1 /1', 1],
    ['-123', -123],
    ['123', 123],
    ['2 /2+3 * 4.75- -6', 21.25],
    ['12* 123', 1476],
    ['12 * -123', -1476],
    ['2 / (2 + 3) * 4.33 - -6', 7.732],
    ['((2.33 / (2.9+3.5)*4) - -6)', 7.45625],
    ["2 + 3 * 4 / 3 - 6 / 3 * 3 + 8", 8],
    ["1 + 2 * 3 * 3 - 8", 11],
    ["1 + 2 * 3 * (5 - 2) - 8", 11],
    ["1 + 2 * 3 * (5 - (3 - 1)) - 8", 11],
    ["4 + -(1)", 3],
    ["4 - -(1)", 5],
    ["4 * -(1)", -4],
    ["4 / -(1)", -4],
    ["-1", -1],
    ["-(-1)", 1],
    ["-(-(-1))", -1],
    ["-(-(-(-1)))", 1],
    ["(((((-1)))))", -1],
    ["5 - 1", 4],
    ["5- 1", 4],
    ["5 -1", 4],
    ["-(-5) - (12 - -89 + -(45)) * (16 / -((((-19 / 18)))) - 28)", 724.157894]
]
for test in tests:
    print(calc(test[0]))
print(calc("(-86) - (-71 + 59 * (60)) * (88 + ((((88 / 43)))) / -78)"))
print(calc("(1 - 2) + -(-(-(-4)))"))
print(calc("-(-59) + (-100 - -38 / -(66)) - (44 - -((((-72 * -16)))) - 58)"))
print(calc("(-29) / (-14 / 60 + (59)) * (-93 * ((((-84 * -91)))) + 70)"))
print(calc("(41) / (-51 / 84 / -(72)) + (-23 * -((((-32 - -96)))) / -62)"))
print(calc("-(-80) * (-9 * 8 / -(3)) - (67 * -(((-(44 / -36)))) * -77)"))
print(calc("(-36) - (93 - -35 + -(25)) - (-58 / ((((-49 - 24)))) - -49)"))
print(calc("-23 * -((((-32 - -96)))) / -62"))
