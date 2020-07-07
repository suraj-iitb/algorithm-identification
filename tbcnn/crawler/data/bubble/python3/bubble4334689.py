def bubblesort(A):
    N = len(A)
    cnt = 0
    for i in range(N):
        for j in range(N-1):
            if A[j] > A[j+1]:
                A[j],A[j+1] = A[j+1],A[j]
                cnt += 1
    print(*A)
    print(cnt)
            

def main():
    N = int(input())
    A = list(map(int,input().split()))
    bubblesort(A)

if __name__ == "__main__":
    main()
