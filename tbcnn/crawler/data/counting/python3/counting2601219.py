def countingSort(A):
    minA = min(A)
    maxA = max(A)
    C = [0]*10001

    for x in A:
        C[x] += 1
    for x in range(1,10001):
        C[x] += C[x-1]
    B = [0]*(len(A)+1)

    for j in range(len(A)-1,-1,-1):
        B[C[A[j]]]=A[j]
        C[A[j]]-=1
    return B

if __name__ == '__main__':
    n = (int)(input())
    A = list(map(int,input().split()))

    B = countingSort(A)
    print(*B[1:])
