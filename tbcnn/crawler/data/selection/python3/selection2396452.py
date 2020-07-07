def selection_sort(A, N):
    sw = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if minj != i:
            sw += 1
            A[i], A[minj] = A[minj], A[i]
    return sw


def main():
    N = int(input().rstrip())
    A = list(map(int, input().rstrip().split()))
    
    sw = selection_sort(A, N)
    
    print(' '.join(map(str, A)))
    print(sw)
    
    
if __name__ == '__main__':
    main()
