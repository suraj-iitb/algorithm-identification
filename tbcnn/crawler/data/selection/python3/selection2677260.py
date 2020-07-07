def sel_sort(A, N):
    ''' 選択ソート '''
    count = 0
    for n in range(N):
        minm = n
        for m in range(n, N):
            if A[m] < A[minm]:
                minm = m
            
        if minm != n:
            A[n], A[minm] = A[minm], A[n]
            count += 1
    
    return (A, count)


if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split(' ')))

    ans = sel_sort(A, N)

    print(' '.join([str(x) for x in ans[0]]))
    print(ans[1])
