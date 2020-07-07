from sys import stdin


def selection_sort(A, N):
    count = 0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[minj] > A[j]:
                minj = j
        
        if A[minj] != A[i]:
            count += 1
            A[minj], A[i] = A[i], A[minj]
        
    return count
                
def main():
    read = stdin.readline
    N = int(read())
    data = list(map(int, read().split(' ')))
    count = selection_sort(data, N)
    for i in range(N-1):
        print(data[i], end=' ')
    print(data[N-1])
    print(count)

if __name__ == '__main__':
    main()
