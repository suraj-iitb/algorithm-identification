if __name__ == '__main__':
    n = int(input())
    A = list(map(int, input().split()))

    B = [0] * n
    C = [0] * 10001

    for i in A:
        C[i] += 1

    for i in range(1, len(C)):
        C[i] += C[i - 1]

    for i in A:
        B[C[i] - 1] = i
        C[i] -= 1
    
    print(' '.join(map(str, B)))

