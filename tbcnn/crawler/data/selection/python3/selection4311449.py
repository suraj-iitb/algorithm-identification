# ALDS1_2_B: Selection Sort 
#N = 6
#A = [int(x) for x in "5 6 4 2 1 3".split()]

N = int(input())
A = list(map(int, input().split())) 


def selectionSort(A, N):
    e = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            A[i], A[minj] = A[minj], A[i]
            e += 1
            #print(A)
    print(" ".join(map(str, A)))
    print(e)
    
selectionSort(A, N)
