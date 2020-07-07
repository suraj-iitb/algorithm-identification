def counting_sort(A, B, k):
    C=[0 for i in range(k)]
    for j in range(n):
        C[A[j]] += 1
    for i  in range(1,k):
        C[i] = C[i] + C[i-1]
    for j in range(n-1,-1, -1):
        B[C[A[j]]-1] = A[j]
        C[A[j]] -= 1

if __name__ == "__main__":
    n=int(input())
    A=list(map(int,input().split()))
    B=[-1 for i in range(n)]
    counting_sort(A,B,max(A)+1)
    print(*B)
