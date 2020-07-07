n = int(input())
A = input().split(' ')

#for i in range(n):
#    A[i] = int(A[i])
print(" ".join(A))

for i in range(1, n):
    v = A[i]
    j = i - 1

    while j >= 0 and int(A[j]) > int(v):
        A[j+1] = A[j]
        j -= 1
        A[j+1] = v
    print(" ".join(A))
