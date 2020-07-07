def main():
    N = int(input())
    A = list(map(int, input().split(' ')))

    insertion_sort(A, N)

def insertion_sort(A, N):
    print(' '.join([str(n) for n in A]))

    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v

        print(' '.join([str(n) for n in A]))

    return A

if __name__ == '__main__':
    main()
