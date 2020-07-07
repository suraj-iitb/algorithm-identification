def sSort(A):
    count = 0
    for i in range(len(A)):
        minj = i
        for j in range(i, len(A)):
            if A[j] < A[minj]:
                minj = j
        if minj != i:
            count += 1
        tmp = A[i]
        A[i] = A[minj]
        A[minj] = tmp
    return A, count

if __name__ == '__main__':
    length = input()
    data = [int(x) for x in input().split()]
    data_s, c = sSort(data)
    print (' '.join([str(x) for x in data_s]))
    print (c)
