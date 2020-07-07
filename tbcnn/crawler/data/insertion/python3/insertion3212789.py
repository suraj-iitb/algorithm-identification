def main():
    N = int(input())
    A = list(map(int,input().split()))
    insertionSort(A, N)

def insertionSort(A, N):
    print(*A)
    for i in range(1,N):
        v = A[i]
        j = i - 1
        while j>= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print(*A)

if __name__ == '__main__':
    main()
