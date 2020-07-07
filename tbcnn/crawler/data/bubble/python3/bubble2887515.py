def BS(A, N):
    A = list(map(int, A.split()))
    flag = 1
    count = 0 
    while flag:
        flag = 0
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                unk = A[j]
                A[j] = A[j-1]
                A[j-1] = unk
                flag = 1
                count = count +1
    print(" ".join(map(str,A)))
    print(count)
 
N = int(input())
A = input()
BS(A, N)
