def selection_sort(N, A):
    num = 0
    for i in range(N):
        minimum = A[i]
        flag = False
        for j in range(i+1, N):
            if A[j] < minimum:
                minimum = A[j]
                index = j
                flag = True
        if flag:
            A[i], A[index] = A[index], A[i]
            num += 1
    return [num, *A]

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    ans = selection_sort(N, A)
    print(*ans[1:])
    print(ans[0])
