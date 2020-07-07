N = int(input())
A = list(map(int, input().split()))

def insertionSort(A,N):
    for i in range(1,N):
        print(" ".join(map(str, A)))
        v = A[i]
        j = i -1
        
        while (j >= 0) & (A[j]>v):
            A[j+1] = A[j]
            j -= 1
            
        A[j+1] = v
    print(" ".join(map(str, A)))
    
insertionSort(A, N)
