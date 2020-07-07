def selectionsort(A,N):
    cnt = 0
    for i in range(N-1):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if minj > i:
            A[i],A[minj] = A[minj],A[i]
            cnt += 1
    print(*A)
    print(cnt)

def main():
    N = int(input())
    A = list(map(int,input().split()))
    selectionsort(A,N)

if __name__ == "__main__":
    main()
