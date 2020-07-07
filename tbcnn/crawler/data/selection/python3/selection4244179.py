def swap(A, i, j):
    temp = A[i]
    A[i] = A[j]
    A[j] = temp

def selection(A):
    N = len(A)
    count = 0
    for i in range(N):
        min_j = i
        for j in range(i, N):
            if A[j] < A[min_j]:
                min_j = j
        if (min_j != i):
            swap(A, i, min_j)
            count += 1
    print(" ".join(map(str, A)))
    print(count)

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    selection(A)

