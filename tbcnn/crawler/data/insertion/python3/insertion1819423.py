data_num = int(input())
data = [int(n) for n in input().split(' ')]

for i in range(0, data_num):
    v = data[i]
    j = i - 1
    while j >= 0 and data[j] > v:
        data[j + 1] = data[j]
        j -= 1
    data[j + 1] = v
    print(' '.join([str(n) for n in data]))
