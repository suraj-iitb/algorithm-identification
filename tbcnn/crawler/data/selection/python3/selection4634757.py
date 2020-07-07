N = int(input())
A = [int(x) for x in input().split()]


while True:
    if len(A) == N:
        break
    else:
        print("Input again!")
        A = [int(x) for x in input().split()]


def SelectionSort(A,N):
    count = 0
    for i in range(0,N,1):
        #print(i)
        minj = i
        for j in range(i+1,N,1):
            if A[j] < A[minj]:
                minj = j
        A[i],A[minj] = A[minj],A[i]
        #count += 1
        if i != minj:
            count += 1
    return A,count

A,count = SelectionSort(A,N)
print(" ".join(map(str,A)))
print(count)
