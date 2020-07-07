def insertion_sort(A: list, N: int):
    print(*A, sep=" ")
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
        print(*A, sep=" ")


if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    insertion_sort(A, N)

