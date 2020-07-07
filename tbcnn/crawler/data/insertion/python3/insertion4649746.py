import sys
input = sys.stdin.readline


def insertionSort(A):
    for i in range(len(A)):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print(" ".join([str(a) for a in A]))


def main():
    _ = int(input().strip())
    A = [int(i) for i in input().strip().split()]
    insertionSort(A)


if __name__ == "__main__":
    main()

