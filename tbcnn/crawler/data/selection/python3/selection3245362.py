n = int(input())

a = input().split()

a = [int(x) for x in a]

count = 0

for i in range(0, n):
    minj = i
    for j in range(i, n):
        if a[j] < a[minj]:
            minj = j
   
    if i != minj:
        tmp = a[i]
        a[i] = a[minj]
        a[minj] = tmp
        count += 1

for i,x in enumerate(a):
    if i != len(a)-1:
        print(x, end=" ")
    else:
        print(x, end="")
print()
print(count)

