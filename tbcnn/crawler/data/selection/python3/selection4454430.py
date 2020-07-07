n = int(input())
As = input().split()
A = [int(i) for i in As]
c = 0

for i in range(n-1):
    mini = i
    j = i
    while n > j:
        if A[j] < A[mini]:
            mini = j
        j += 1
    if i != mini:
        w = A[i]
        A[i] = A[mini]
        A[mini] = w
        c += 1

for i in range(n-1):
    print("{} ".format(A[i]), end="")
print(A[n-1])
print(c)

