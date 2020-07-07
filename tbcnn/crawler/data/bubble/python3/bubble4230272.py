def main(N, A):
    count = 0
    flag = True
    i = 0
    while flag:
        flag = False
        for j in list(reversed(list(range(i + 1, N)))):
            a = A[j-1]
            b = A[j]
            if a > b:
                A[j-1] = b
                A[j] = a
                count += 1
                flag = True
        i += 1
    print(' '.join(map(str, A)))
    print(count)
    return (A, count)


if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    main(N, A)

