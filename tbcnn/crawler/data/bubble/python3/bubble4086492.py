def bubble_sort(N, A):
    num = 0
    for k in range(0, N-1):
        for i in range(N-1, k, -1):
            if A[i] < A[i-1]:
                A[i], A[i-1] = A[i-1], A[i]
                num += 1
    return [num, *A]

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    ans = bubble_sort(N, A)
    print(*ans[1:])
    print(ans[0])
