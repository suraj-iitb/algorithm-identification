n = int(input())
a = list(map(int, input().split()))
flag = True
c = 0
j = 0
while flag:
    flag = False
    for i in range(n - 1, j, -1):
        if a[i] < a[i - 1]:
            a[i], a[i - 1] = a[i - 1], a[i]
            c += 1
            flag = True
    j += 1
print(" ".join(map(str, a)))
print(c)
    
