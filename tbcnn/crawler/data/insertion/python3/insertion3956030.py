L, A = int(input()), input()
print(A)

A = [int(i) for i in A.split()]
for i in range(1, L):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    l = [str(k) for k in A]
    l = ' '.join(l)
    print(l)


