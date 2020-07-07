def main():
    N = int(input())
    A = list(map(int, input().split()))
    bubbleSort(A, N)

def bubbleSort(A, N):
    flag = 1
    i = 0
    while flag:
        flag = 0
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                flag = 1
                i += 1

    print(' '.join(map(str, A)))
    print(i)

if __name__ == '__main__':
    main()
