def selectionSort(n, A):
    cnt =0
    for i in range(n):
        minj = i
        for j in range(i,n):
            if A[minj] > A[j]:
                minj = j
        if i != minj:
            A[i],A[minj] = A[minj],A[i]
            cnt += 1
    print(*A)
    print(cnt)

if __name__ == '__main__':
    n = int(input())
    A = list(map(int, input().split()))
    selectionSort(n,A)
