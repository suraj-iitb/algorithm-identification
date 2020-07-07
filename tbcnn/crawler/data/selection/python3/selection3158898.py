def SelectionSort(A):
    n = 0
    for i in range(len(A)):
        mini = i
        for j in range(i, len(A)):
            if A[j]<A[mini]:
                mini=j
        if i!=mini:
            A[i], A[mini] = A[mini], A[i]
            n += 1
    print(' '.join(map(str, A)), n, sep='\n')

input()
SelectionSort(list(map(int, input().split())))
