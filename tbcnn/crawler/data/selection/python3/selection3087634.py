def SelectionSort(A):
    n = len(A)
    ans = 0
    for i in range(n-1):
        mini = i
        for j in range(i+1, n):
            if A[j] < A[mini]:
                mini = j
        if i != mini:
            A[i], A[mini] = A[mini], A[i]
            ans += 1
    print(' '.join([str(i) for i in A]))
    print(ans)

_ = input()
SelectionSort([int(i) for i in input().split()])
