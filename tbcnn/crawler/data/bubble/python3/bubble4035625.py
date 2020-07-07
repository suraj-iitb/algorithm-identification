n = int(input())
a = list(map(int, input().split()))
flag = 1
count = 0
i = 0
while flag:
    flag = 0
    for j in reversed(range(i+1,n)):
        if a[j] < a[j-1]:
            c = a[j]
            a[j] = a[j-1]
            a[j-1] = c
            flag = 1
            count += 1
    i += 1

b = [str(i) for i in a]
print(" ".join(b))
print(count)
