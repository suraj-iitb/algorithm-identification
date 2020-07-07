N = int(input())
A = list(map(int, input().split()))

def bubble_sort(A,N):
    flag = True
    cnt  = 0
    while flag:
        flag = False
        for j in range(N-1,1-1,-1): #j=N-1 to 1
            if A[j] < A[j-1]:
                A[j],A[j-1] = A[j-1],A[j]
                cnt += 1
                flag = True
    return A, cnt
    
sorted_A, cnt = bubble_sort(A,N)
print(*A)
print(cnt)
