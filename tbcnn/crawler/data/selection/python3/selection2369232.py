N = int(input())
a = list(map(int, input().split()))

count = 0
for i in range(N):
    minj = i
    for j in range(i, N):
        if(a[j] < a[minj]):
            minj = j
    hold = a[i]
    a[i] = a[minj]
    a[minj] = hold
    if(minj != i): count += 1

print(" ".join(list(map(str, a))))
print(count)
