
if __name__ == '__main__':
    N = (int)(input())
    A = list(map(int,input().split()))

    swapOperation = 0

    flag = 1
    while flag == 1:
        flag = 0
        for j in range( N-1, 0, -1):
            if A[j] < A[j-1]:
                v = A[j]
                A[j]=A[j-1]
                A[j-1]=v
                flag = 1
                swapOperation += 1
    print(" ".join(map(str,A)))
    print(swapOperation)
