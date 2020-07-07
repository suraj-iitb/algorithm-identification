def selectionSort(A, N):
    swap = 0

    for i in range(N):
        minj = i

        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j

        if i != minj:
            A[i], A[minj] = A[minj], A[i]
            swap += 1

    print(" ".join(list(map(str, A))))
    print(swap)

def main():
    N = int(input())
    A = [int(i) for i in input().split()]

    selectionSort(A, N)

main()


