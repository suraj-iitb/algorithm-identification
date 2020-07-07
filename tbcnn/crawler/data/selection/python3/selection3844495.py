# ALDS1_2_B - Selection Sort
def main():
    N, *A = map(int, open(0).read().split())
    swap = 0
    for i in range(N):
        mi = i
        for j in range(i, N):
            if A[j] < A[mi]:
                mi = j
        if i != mi:
            A[i], A[mi] = A[mi], A[i]
            swap += 1
    print(*A)
    print(swap)


if __name__ == "__main__":
    main()
