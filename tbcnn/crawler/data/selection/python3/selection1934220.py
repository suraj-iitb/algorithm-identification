n = int(input())
A = input().split(' ')
count = 0

for i in range(0, n):
    minj = i

    for j in range(i, n):
        if int(A[j]) < int(A[minj]):
            minj = j

    if i != minj:
        (A[i], A[minj]) = (A[minj], A[i])
        count += 1

print(" ".join(A))
print(count)
