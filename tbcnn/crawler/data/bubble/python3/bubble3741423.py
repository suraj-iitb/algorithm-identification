N = int(input())
A = list(map(int, input().split()))

def bubbleSort(A, N):
    counter = 0
    flag = 1
    i = 0
    while flag:
        flag = 0
        for j in range(N-1, i, -1):
            if A[j] < A[j-1]:
                temp = A[j-1]
                A[j-1] = A[j]
                A[j] = temp
                counter += 1
                flag = 1
        i +=1
    return A,counter
    
A, counter = bubbleSort(A, N)

print(' '.join(repr(e) for e in A))
print(counter)

