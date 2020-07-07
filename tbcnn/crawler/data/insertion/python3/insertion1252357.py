def insertion_sort(A, N):
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j = j-1
        A[j+1] = v

        print(*A)

if __name__ == '__main__':
    N = int(input())
    A = [int(_) for _ in input().split()]

    print(*A)

    insertion_sort(A, N)
