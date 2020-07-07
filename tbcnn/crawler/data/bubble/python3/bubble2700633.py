def bSort(A):
    flag = 1
    i = 0
    count = 0
    while flag:
        flag = 0
        for j in range(len(A)-1, i, -1):
            if A[j] < A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                flag = 1
                count += 1
        i += 1
    return A, count

if __name__ == '__main__':
    length = input()
    data = [int(x) for x in input().split()]
    data_s, c = bSort(data)
    print (' '.join([str(x) for x in data_s]))
    print (c)
