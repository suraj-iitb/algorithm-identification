def bubble_sort(A):
    global N
    flag = True
    i = 0 
    cnt = 0
    while flag:
        flag = False
        for j in range(N-1, i, -1):
            if A[j] < A[j-1]:
                A[j],A[j-1] = A[j-1],A[j]
                cnt += 1
                flag = True
        i += 1
    return cnt

N = int(input())
A = list(map(int, input().split()))
cnt = bubble_sort(A)
print(' '.join(list(map(str, A))))
print(cnt)

