N = int(input())
b = input().split()
a = [int(n) for n in b]

c = 0
for i in range(N):
    minj = i
    for j in range(i,N):
        if a[j] < a[minj]:
            minj = j
    if i != minj:
        c+=1
    v = a[i]
    a[i] = a[minj]
    a[minj] = v
print(" ".join([str(n) for n in a]))
print(c)
