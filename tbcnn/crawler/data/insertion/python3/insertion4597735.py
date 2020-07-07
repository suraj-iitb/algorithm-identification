def main():
    N = int(input())
    A = list(map(int,input().split()))

    print(' '.join(map(str,A)))

    for i in range(1,N):
        for j in range(i-1,-1,-1):
            if A[j+1] >= A[j]:
                break
            elif A[j+1] < A[j]:
                temp = A[j+1]
                A[j+1] = A[j]
                A[j] = temp
        print(' '.join(map(str,A)))

main()

