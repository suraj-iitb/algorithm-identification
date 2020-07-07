def counting(A, **k):
    n = len(A)
    k = max(A)
    B = [0]*(n)
    C = [0]*(k+1)
    
    for j in A:
        C[j] += 1
    for i in range(k):
        C[i+1] += C[i]
    for j in A[::-1]:
        B[C[j]-1] = j
        C[j] -= 1
    
    return B

if __name__ == "__main__":
    input()
    A = list(map(int, input().strip().split()))
    B = counting(A)
    print(" ".join(map(str, B)))
