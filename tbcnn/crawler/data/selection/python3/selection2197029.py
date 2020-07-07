def selection_Sort(A,N):
    count = 0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            A[i],A[minj] = A[minj],A[i]
            count += 1
    return (count)

if __name__ == '__main__':
    n = int(input())
    data = [int(i) for i in input().split()]
    result = selection_Sort(data,n)
    print(" ".join(map(str,data)))
    print(result)
