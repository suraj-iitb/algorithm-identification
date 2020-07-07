def insertion_sort(A):
    n = len(A)
    print(*A)
    for i in range(1, n):
        item = A[i]
        cur_idx = i - 1
        while cur_idx >= 0 and A[cur_idx] > item:
            A[cur_idx], A[cur_idx + 1] = A[cur_idx + 1], A[cur_idx]
            cur_idx -= 1
        print(*A)


if __name__ == "__main__":
    N = int(input())
    A = [int(elem) for elem in input().split()]
    insertion_sort(A)

