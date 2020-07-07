n = int(input())
a = [int(i) for i in input().split(" ")]

print(" ".join([str(i) for i in a]))
for i in range(1, n, 1):
    for j in range(i):
        if a[i] < a[j]:
            a.insert(j, a[i])
            a.pop(i+1)
    print(" ".join([str(i) for i in a]))
