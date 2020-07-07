n = int(input())
A = [int(x) for x in input().split()]
print(" ".join([str(x) for x in A]))

for i in range(1, n):
    key = A[i]
    j = i-1
    while j >=0 and A[j] > key:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = key
    print(" ".join([str(x) for x in A]))
