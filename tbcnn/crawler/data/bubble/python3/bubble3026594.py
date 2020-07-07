# Bubble Sort
n = int(input())
line = [int(i) for i in input().rstrip().split()]
# print(line)

count = 0
for i in range(n - 1):
    a = n - 1
    while a > i:
        if line[a - 1] > line[a]:
            line[a - 1], line[a] = line[a], line[a - 1]
            # print(line)
            count += 1
        a -= 1

for i in range(n):
    print(line[i], end = "")
    if i < n - 1:
        print(" ", end = "")
print()
# print(line)
print(count)

