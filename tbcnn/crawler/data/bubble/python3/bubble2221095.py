def bubbleSort():
    l = int(input())
    A = list(map(int, input().split(" ")))
    count = 0
    for i in range(l-1):
        for j in range(l-1-i):
            if (A[j]>A[j+1]):
                temp = A[j]
                A[j] = A[j+1]
                A[j+1] = temp
                count += 1
    print(" ".join(map(str, A)))
    print(count)

bubbleSort()
