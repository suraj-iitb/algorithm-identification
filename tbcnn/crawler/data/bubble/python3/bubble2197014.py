def bubbleSort(A,N):
    count = 0
    flag = 1
    while flag:
        flag = 0
        for i in range(1,N):
            if A[N-i] < A[N-i-1]:
                A[N-i] , A[N-i-1] = A[N-i-1] , A[N-i]
                flag = 1
                count += 1
    return (count)

n = int(input())
data = [int(i) for i in input().split()]
a = bubbleSort(data,n)
print(" ".join(map(str,data)))
print(a)
