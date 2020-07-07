def bubbleSort(A, N) :
    kaisu = 0
    flag = 1
    while flag :
        flag = 0
        for j in range(N-1, 0, -1) :
            if A[j]  < A[j-1] :
                A[j], A[j-1] = A[j-1], A[j]
                flag = 1
                kaisu += 1
    return kaisu

N = int(input())
A = list(map(int, input().split()))
kaisu = bubbleSort(A, N)
for i in range(N) :
    print(A[i], end="")
    if i != N-1 :
        print(" ", end="")
print()
print(kaisu)

