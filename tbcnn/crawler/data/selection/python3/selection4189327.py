n = int(input())
a = [int(i) for i in input().split(" ")]

count = 0
for i in range(n):
    minv = a[i]
    mini = i
    for j in range(i+1, n, 1):
        if minv > a[j]:
            minv = a[j]
            mini = j
    if i != mini:
        a[i], a[mini] = a[mini], a[i]
        count += 1
print(" ".join([str(i) for i in a]))
print(count)
