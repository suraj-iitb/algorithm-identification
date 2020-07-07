def selectionSort():
    l = int(input())
    A = list(map(int, input().split(" ")))
    count = 0
    for i in range(l-1):
        mini = i
        for j in range(i, l-1):
            if (A[mini]>A[j+1]):
                mini = j+1
        if (i != mini):
            temp = A[mini]
            A[mini] = A[i]
            A[i] = temp
            count += 1
    print(" ".join(map(str, A)))
    print(count)
selectionSort()
