if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    print(*A)
    for i in range(1, N):
        while(i >= 1 and A[i-1] > A[i]):
            A[i], A[i-1] = A[i-1], A[i]
            i -= 1
        print(*A)
