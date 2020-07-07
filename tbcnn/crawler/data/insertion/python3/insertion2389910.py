def insertion_sort(A, N):
    for i  in range(N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
        
        print(' '.join(map(str, A)))

def main():
    N = int(input().rstrip())
    A = list(map(int, input().rstrip().split()))
    
    insertion_sort(A, N)
    
if __name__ == '__main__':
    main()
