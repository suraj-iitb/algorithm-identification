def selectionSort(A, N):
    c = 0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if A[i] != A[minj]:
            A[i],A[minj] = A[minj],A[i]
            c += 1
    return A,c
num = int(input())
li1 = [int(e) for e in input().split()]
li2 = selectionSort(li1,num)
print(*li2[0],sep=" ")
print(li2[1])
