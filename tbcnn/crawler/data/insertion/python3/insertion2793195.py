def insertionsort(A, n):
    for i in range(1, n):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        prt(A)

def prt(A):
    for i in A:
        if i != A[len(A)-1]: print(i, end=" ")
        else: print(i)

n = int(input())
A = input().split()
A = [int(i) for i in A]
prt(A)
insertionsort(A, n)
