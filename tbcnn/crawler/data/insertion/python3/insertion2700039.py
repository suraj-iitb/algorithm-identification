def insertionsort(A):
    for i in range(1,len(A)):
        v = A[i]
        j = i-1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
            A[j+1] = v
        print(*A,sep=" ")
    return A

N = int(input())
A = [int(i) for i in input().split()]
print(*A,sep=" ")
insertionsort(A)
