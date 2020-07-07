n = int(input())
A = list(map(int, input().split()))

def bucketsort(A, B):
    C = [0] * (max(A) + 1)
    
    for i in A:
        C[i] += 1
    
    for i in range(1, max(A) + 1):
        C[i] += C[i - 1]
    
    for i in (reversed(A)):
        B[C[i] - 1] = i
        C[i] -= 1
    return B

B = [0] * len(A)
ans = bucketsort(A, B)
ans = [str(i) for i in ans]
print(' '.join(ans))
