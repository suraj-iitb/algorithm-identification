N = int(input())
A = list(map(int,input().split()))

def sort():
    flag = 1
    swap = 0
    while flag:
        flag = 0
        for j in range(N-1,0,-1):
            if A[j] < A [j-1]:
                temp = A[j]
                A[j] = A[j-1]
                A[j-1] = temp
                swap += 1
                flag = 1
    pr(A)
    print(swap)

def pr(list):
    n = len(list)
    for i in range(n):
        if i < n-1:
            print(list[i],end=" ")
        else:
            print(list[i],end="\n")

sort()

