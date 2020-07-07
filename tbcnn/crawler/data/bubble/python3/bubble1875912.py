# Bubble sort
def bubble_sort(A,N):
    count = 0
    flag = 1 # ????????£??\????´?????????¨??????
    while flag:
        flag = 0
        for j in range(N-1,0,-1):
            if A[j] < A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                flag = 1
                count += 1
    return count
N = int(input())
A = [int(i) for i in input().split(' ')]
c = bubble_sort(A,N)
print(' '.join(list(map(str, A))))
print(c)
