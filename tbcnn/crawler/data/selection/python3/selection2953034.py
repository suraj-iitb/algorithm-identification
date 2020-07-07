def selectionSort(A,N):
    n_swap = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if minj != i:
            A[i], A[minj] = A[minj], A[i]
            n_swap += 1
    return n_swap, A

def run():
    n = int(input())
    a = list(map(int, input().split()))
    c, a = selectionSort(a,n)
    print(' '.join([str(i) for i in a]))
    print(c)

if __name__ == '__main__':
    run()
