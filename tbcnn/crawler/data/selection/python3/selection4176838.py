n = int(input())
a = list(map(int, input().split()))
numSwap = 0

for i in range(n):
    minj = i
    for j in range(i,n):
        if a[j] < a[minj]:
            minj = j
    if minj != i:
        numSwap += 1
        a[i],a[minj] = a[minj],a[i]
a = [str(s) for s in a]
print(' '.join(a))
print(numSwap)
