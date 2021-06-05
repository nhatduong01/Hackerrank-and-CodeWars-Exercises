'''This kata can be found on :
https://www.codewars.com/kata/525c7c5ab6aecef16e0001a5/train/python '''


def parse_int(string):
    all_values = {"zero": 0, "one": 1, "two": 2, "three": 3, "four": 4, "five": 5, "six": 6,
                  "seven": 7, "eight": 8, "nine": 9, "ten": 10,
                  "eleven": 11, "twelve": 12, "thirteen": 13, "fourteen": 14, "fifteen": 15,
                  "sixteen": 16, "seventeen": 17, "eighteen": 18, "nineteen": 19,
                  "twenty": 20, "thirty": 30, "forty": 40, "fifty": 50, "sixty": 60,
                  "seventy": 70, "eighty": 80, "ninety": 90}
    result = 0
    chunks = string.split(' ')
    final_chunks = []
    for i in chunks:
        i = i.split('-')
        for j in i:
            final_chunks.append(j)
    i = 0
    while(i < len(final_chunks)):
        if final_chunks[i] == "and":
            i += 1
            continue
        if i + 1 != len(final_chunks) and final_chunks[i+1] == "hundred":
            result += all_values.get(final_chunks[i])*100
            i += 2
            continue
        elif final_chunks[i] == "thousand":
            result *= 1000
        elif final_chunks[i] == "million":
            result *= 1000000
        else:
            result += all_values.get(final_chunks[i])
        i += 1
    return result


print(parse_int("two hundred forty-five million six hun"))
