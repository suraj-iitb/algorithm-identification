def min_index(A):
    index = 0
    m = A[0]
    for i in range(1,len(A)):
        if A[i] < m:
            m = A[i]
            index = i
    return index

def selectionsort(A,N):
    count = 0
    for i in range(N-1):
        j = min_index(A[i+1:])
        if A[i] > A[i+j+1]:
            #A[i],A[i+j+1] = A[i+j+1],A[i]
            count += 1
            A[i],A[i + min_index(A[i+1:]) + 1] = A[i + min_index(A[i+1:]) + 1],A[i]
    return A,count

if __name__ == '__main__':
    N = int(input())
    A = [int(i) for i in input().split()]
    ans,count = selectionsort(A,N)
    for i in range(N):
        if i != N - 1:
            print(ans[i],end = " ")
        else:
            print(ans[i])
    print(count)

