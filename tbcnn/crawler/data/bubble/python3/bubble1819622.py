data_num = int(input())
data = [int(n) for n in input().split(' ')]
data_len = len(data)

flag = True
i = 0
changed = 0

while flag:
    flag = False
    for j in range(data_len-1, i, -1):
        if data[j] < data[j-1]:
            data[j], data[j-1] = data[j-1], data[j]
            changed += 1
            flag = True
    i += 1
print(' '.join(str(i) for i in data))

print(changed)
