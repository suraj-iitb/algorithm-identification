def insertion_sort(A, N, gap):
    global cnt
    for i in range(gap, N):
        tmp = A[i]
        j = i - gap
        while j>=0 and A[j] > tmp:
            A[j+gap] = A[j]
            j = j - gap
            cnt += 1
        A[j+gap] = tmp

def shell_sort(A, N):
    gaps = [int((3**item-1)/2) for item in range(1, 100) if int((3**item-1)/2) <= N][::-1]
    m = len(gaps)
    for gap in gaps:
        insertion_sort(A, N, gap)
    print(m)
    print(' '.join([str(gap) for gap in gaps]))
    print(cnt)
    print('\n'.join([str(item) for item in A]))

cnt = 0
N = int(input())
A = [int(input()) for i in range(N)]

shell_sort(A, N)
