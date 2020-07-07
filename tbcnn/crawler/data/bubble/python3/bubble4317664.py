def bubble_sort(A, N):
    flag = True
    cnt = 0
    while flag:
        flag = False
        for i in range(N-1, 0, -1):
            if A[i] < A[i-1]:
                A[i], A[i-1] = A[i-1], A[i]
                cnt += 1
                flag = True
    print(*A, sep=' ')
    print(cnt)


def main():
    N = int(input())
    A = list(map(int, input().split()))
    bubble_sort(A, N)


if __name__ == "__main__":
    main()
