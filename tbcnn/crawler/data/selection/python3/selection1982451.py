N = int(input())
A = [int(a) for a in input().split(" ")]
swapnum = 0
for i in range(N):
    mini = i
    swap = False
    for j in range(i, N):
        if A[j] < A[mini]:
            mini = j
            swap = True
    if swap:
        tmp = A[i]
        A[i] = A[mini]
        A[mini] = tmp
        swapnum += 1
print(" ".join([str(a) for a in A]))
print(swapnum)
