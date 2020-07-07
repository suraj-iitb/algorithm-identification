if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    count=0
    flag = True
    while(flag):
        flag = False
        for i in range(N-1):
            if A[i] > A[i+1]:
                A[i], A[i+1] = A[i+1], A[i]
                count += 1
                flag = True
    print(*A)
    print(count)
