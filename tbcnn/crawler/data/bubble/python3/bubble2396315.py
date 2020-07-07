def bubble_sort(A, N):
    sw = 0
    flag = True
    while flag:
        flag = False
        for j in range(1, N):
            if A[j - 1] > A[j]:
                A[j - 1], A[j] = A[j], A[j - 1]
                sw += 1
                flag = True
    return sw


def main():
    N = int(input().rstrip())
    A = list(map(int, input().rstrip().split()))
    
    sw = bubble_sort(A, N)

    print(' '.join(map(str, A)))
    print(sw)


if __name__ == '__main__':
    main()
