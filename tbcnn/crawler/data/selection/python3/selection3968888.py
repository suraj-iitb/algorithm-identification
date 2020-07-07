N = int(input())
A = list(map(int,input().split()))

def selection_sort(A):
    cnt = 0
    for i in range(len(A)-1):
        minj = i
        for j in range(i+1,len(A)):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            cnt += 1
        A[minj],A[i] = A[i],A[minj]
    print(*A)
    print(cnt)

selection_sort(A)
