def main():
    N = int(input())
    A = list(map(int, input().split()))
    bubbleSort(A, N)


def bubbleSort(A, N):
    count = 0
    flag = 1
    while flag:
        flag = 0
        for i in reversed(range(1, N)):
            if A[i] < A[i - 1]:
                x = A[i]
                y = A[i - 1]
                A[i] = y
                A[i - 1] = x
                flag = 1

                count += 1

    print(*A)
    print(count)

main()
