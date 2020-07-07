# ALDS1_1_A - Insertion Sort
def main():
    N, *A = map(int, open(0).read().split())
    print(*A)
    for i in range(1, N):
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = key
        print(*A)


if __name__ == "__main__":
    main()
