n = int(input())

a = input().split()

a = [int(x) for x in a]

flag = True
i = 0
count = 0

while flag:
    flag = False

    for j in range(n-1, i, -1):
        if a[j] < a[j-1]:
            tmp = a[j]
            a[j] = a[j-1]
            a[j-1] = tmp
            count += 1
            flag = True

    i += 1

for i,x in enumerate(a):
    if i != len(a)-1:
        print(x, end=" ")
    else:
        print(x, end="")
print()
print(count)
