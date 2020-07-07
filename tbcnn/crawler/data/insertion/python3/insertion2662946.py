def insertion_sort(A, N):
    for i in range(1, N):
        for s in A:
            tmp = str(s) if A[0] == s else " "+str(s)
            print(tmp, end="")
        print()

        j = i-1
        v = A[i]
        while v < A[j] and j >= 0:
            A[j+1] = A[j]
            j = j-1
        A[j+1] = v
    for s in A: 
        tmp = str(s) if A[0] == s else " "+str(s) 
        print(tmp, end="")
    print()
    
if __name__ == "__main__":
    N = int(input())
    A = [int(x) for x in input().split()]

    insertion_sort(A, N)
    
