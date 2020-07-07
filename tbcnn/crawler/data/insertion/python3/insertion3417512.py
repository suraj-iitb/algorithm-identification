N = int(input())
A = list(map(int, input().split()))
for h in range(len(A)):
    if h == len(A)-1:
        print(A[h])
    else:
        print(A[h], "", end="")
def insertionSort(A, N):
    for i in range(1, N):
        temp = A[i]
        j = i -1
        while j >= 0 and temp < A[j]:
            A[j+1] = A[j]
            j -= 1
        A[j + 1] = temp
        for k in range(len(A)):
            if k == len(A)-1:
                print(A[k])
            else:
                print(A[k], "", end="")

insertionSort(A, N)
