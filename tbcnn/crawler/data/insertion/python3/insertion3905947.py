def main():
    def insertSort(A):
        N = len(A)
        for i in range(1,N):
            print(*A)
            val = A[i]
            j = i - 1
            while j >= 0 and A[j] > val:
                A[j+1] = A[j]
                j -= 1
            A[j+1] = val
        else:
            print(*A)

    N = int(input())
    A = [int(i) for i in input().split()]
    insertSort(A)

if __name__ == "__main__":
    main()
