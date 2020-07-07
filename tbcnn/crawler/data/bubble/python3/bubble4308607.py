# ALDS1_2_A: Bubble Sort
#N = 5
#A = [int(x) for x in "5 3 2 4 1".split()]

N = int(input())
A = list(map(int, input().split())) 


def bubbleSort(A, N):
    flag = True
    i = 0
    while(flag):
        flag = False
        for j in reversed(range(1, N)):
            if A[j] < A[j-1]:                
                A[j], A[j-1] = A[j-1], A[j]
                flag = True
                i += 1
                #print(A)
    print(" ".join(map(str, A)))
    print(i)
    
bubbleSort(A, N)
