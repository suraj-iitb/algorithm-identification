def Insertion_Sort(A, N):
    print(A)
    A = list(map(int, A.split()))
    for i in range(1,N):
        v = A[i]  
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print(" ".join(map(str,A)))

N = int(input())
A = input()
Insertion_Sort(A, N)
