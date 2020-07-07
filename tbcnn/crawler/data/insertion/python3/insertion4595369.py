from sys import stdin


def insertion_sort(A, N):
    for i in range(1,N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        
        for j in range(N-1):
            print(A[j], end=" ", sep=" ")
        print(A[N-1])
            

def main():
    read = stdin.readline
    N = int(read())
    data = list(map(int, read().split(" ")))
    for j in range(N-1):
        print(data[j], end=" ", sep=" ")
    print(data[N-1])
    insertion_sort(data, N)
    
if __name__ == "__main__":
    main()
    
