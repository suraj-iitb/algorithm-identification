k = 10000+1
def counting_sort(A, B, k):
    C = [0] * k
    n = len(A)-1
    for j in range(n):
        C[A[j+1]] += 1
    for i in range(1, k):
        C[i] += C[i-1]
    for j in range(n, 0, -1):
        # print('j = {0}'.format(j))
        # print('A[{0}] = {1}'.format(j, A[j]))
        # print('C[A[j]] = {0}'.format(C[A[j]]))
        B[C[A[j]]] = A[j]
        C[A[j]] -= 1


if __name__ == '__main__':
    # ??????????????\???
    # array_size = 7
    # A = [999, 2, 5, 1, 3, 2, 3, 0]
    array_size = int(input())
    A = [int(x) for x in input().split(' ')]
    A.insert(0, 9999999)
    B = A[:]

    # ????????????????????????
    counting_sort(A, B, k)

    # ???????????????
    # print('A = {0}'.format(' '.join(map(str, A[1:]))))
    print('{0}'.format(' '.join(map(str, B[1:]))))
