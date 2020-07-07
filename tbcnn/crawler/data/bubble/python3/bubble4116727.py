def Bubble_Sort(A, N):
    count = 0
    for i in range(N):
        for j in reversed(range(i+1,N)):
            if A[j] < A[j-1]:
                a = A[j]
                A[j] = A[j-1]
                A[j-1] = a
                count += 1
    
    return(A, count)

N = int(input())
A = list(map(int,input().split()))

ans1, ans2 = Bubble_Sort(A, N)
print(' '.join(map(str, ans1)))
print(ans2)
