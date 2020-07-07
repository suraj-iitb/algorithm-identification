def countingSort(A,n,k):
    B = [0]*(n)
    C = [0]*(k+1)

    for i in A:
        C[i] += 1
    
    for i in range(1, k):
        C[i] += C[i-1]
    
    for a in reversed(A):
        B[C[a]-1] = a
        C[a] -= 1

    return B

def main():
    n = int(input())
    A = list(map(int, input().split()))

    B = countingSort(A,n,10000)

    print(*B)
             
if __name__ == "__main__":
    main()
