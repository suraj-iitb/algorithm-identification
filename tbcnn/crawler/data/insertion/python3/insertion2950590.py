def insertionSort(A,N):
    print(' '.join([str(a) for a in A]))
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print(' '.join([str(a) for a in A]))

def run():
    N = int(input())
    A = [int(i) for i in input().split()]
    insertionSort(A,N)

if __name__ == '__main__':
    run()
