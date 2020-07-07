# Algorithm and Data Structures 1
# Name: Ryuya Asada
# ID: s1260064


def InsertionSort(A: list):
    for i in range(1, len(A)):
        key = A[i]
        j = i - 1
        print(*A, sep=" ")
        while (j >= 0 and A[j] > key):
            A[j+1] = A[j]
            j -= 1
        A[j+1] = key


def main():
    length = int(input())
    A = [int(e) for e in input().split(" ")]

    InsertionSort(A)
    print(*A, sep=" ")


if __name__ == "__main__":
    main()


