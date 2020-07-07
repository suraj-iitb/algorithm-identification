n = int(input())
a = [int(i) for i in input().split()]

count = 0
flag = True
while flag:
    flag = False
    for i in range(n - 1):
        if a[i] > a[i + 1]:
            a[i + 1], a[i] = a[i], a[i + 1]
            count += 1
            flag = True

print(" ".join([str(i) for i in a]))
print(count)
