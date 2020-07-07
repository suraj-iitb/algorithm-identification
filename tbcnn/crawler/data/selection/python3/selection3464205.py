N = int(input())
A = list(map(int, input().split()))
c = 0

for i in range(len(A)):
    minA = i
    for j in range(i, len(A)):
        if A[j] < A[minA]:
            minA = j

    if i != minA:
        p = A[i]
        A[i] = A[minA]
        A[minA] = p
        c += 1

print(" ".join(map(str, A)))
print(c)
