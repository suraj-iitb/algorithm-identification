n = int(input())
A = list(map(int, input().split()))
count = 0

for i in range(n):
    minA = i
    flag = False
    for j in range(i, n):
        if A[j] < A[minA]:
            minA = j
            flag = True
    
    if flag:
        v = A[i]
        A[i] = A[minA]
        A[minA] = v
        count += 1


print(" ".join(map(str, A)))
print(count)
