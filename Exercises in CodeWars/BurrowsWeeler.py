def encode(s):
    all_words = []
    for i in range(0, len(s)):
        all_words.append(s[i:])
    all_words.sort()
    idx = []
    for i in all_words:
        idx.append(len(s) - len(i))
    loc = all_words.index(s)

    words = list(s)
    List = []

    for i in range(len(words)):
        word = s[-1] + s[:-1]
        new = ''.join(word)
        s = new
        List.append(new)
        i += 1
    # print(List)

    sort = sorted(List)
    # print(sort)
    result = ""
    for i in range(len(words)):
        element = sort[i]
        last = element[- 1]
        i = i + 1
        result += last
    return result, loc


def decode(s, n):
    sorted_s = ''.join(sorted(s))
    # print(sorted_s)
    frequency = {}
    for i in range(0, len(s)):
        if frequency.get(s[i]) != None:
            frequency[s[i]].append(i)
        else:
            frequency[s[i]] = []
            frequency[s[i]].append(i)
    # print(frequency)
    sorted_header = sorted(frequency)
    l_shift = []
    for i in sorted_header:
        l_shift += (frequency.get(i))
    # print(l_shift)
    result = ""
    while(len(result) != len(s)):
        n = l_shift[n]
        result += s[n]
    return result


#print(decode("ww MYeelllloo", 1))
# a = {"a":[1,2,3], "A" : [2,34], "c" : 2, "B":[90,100]}
print(encode("Humble Bundle"))
