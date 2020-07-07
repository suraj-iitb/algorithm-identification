N = int(input())
A = list(map(int,input().split()))
def bubble_sort(A):
    cnt = 0
    flag = 1
    i = 0
    while flag:
        flag = 0
        for j in range(len(A)-1,i,-1):
            if A[j] < A[j-1]:
                [A[j],A[j-1]] = [A[j-1],A[j]]
                cnt += 1
                flag = 1
        i += 1
    print(*A)
    print(cnt)
    return A

bubble_sort(A)
