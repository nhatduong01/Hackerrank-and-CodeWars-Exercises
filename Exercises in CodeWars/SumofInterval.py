def sum_of_intervals(intervals):
    all_pairs = []
    for i in intervals:
        for j in range(i[0], i[1]):
            if [j, j+1] not in all_pairs:
                all_pairs.append([j, j+1])
    return len(all_pairs)


print(sum_of_intervals([
    [1, 5],
    [10, 20],
    [1, 6],
    [16, 19],
    [5, 11]
]))
