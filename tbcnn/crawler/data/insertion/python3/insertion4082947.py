from sys import stdin
#stdin = open("input.txt")

def insertionSort(A, N):
    for i in range(N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j += -1
        A[j+1] = v
        
        print(*A)

if __name__ == "__main__":
    N = int(stdin.readline())
    A = [int(item) for item in stdin.readline().split()]
    
    insertionSort(A, N)
