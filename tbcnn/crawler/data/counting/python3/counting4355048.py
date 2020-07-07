def main():
    n = int(input())
    A = list(map(int,input().split()))
    m = 10001
    B = [0]*n
    C = [0]*m
    for a in A:C[a]+=1
    for i in range(1,m):
        C[i] = C[i]+C[i-1]
    for j in range(n):
        B[C[A[j]]-1] = A[j]
        C[A[j]] -= 1
    print (' '.join(map(str,B)))


if __name__ == '__main__':
    main()


