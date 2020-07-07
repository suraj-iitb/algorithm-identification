num = int(input())
line = list(map(int, input().split()))
count = 0
for i in range(1,num):
    for j in range(i):
        if line[i-j] < line[i-j-1]:
            a = line[i-j]
            line[i-j] = line[i-j-1]
            line[i-j-1] = a
            count+= 1
        else:
            break
line_str = [str(k) for k in line]
print(' '.join(line_str))
print(count)
