data_num = int(input())
data = [int(n) for n in input().split(' ')]
changed = 0

for i in range(0, data_num):
    minj = i
    for j in range(i, data_num):
        if data[j] < data[minj]:
            minj = j
    data[i], data[minj] = data[minj], data[i]
    if i != minj:
        changed += 1

print(' '.join([str(i) for i in data]))
print(changed)
