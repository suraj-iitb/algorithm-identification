N = int(input())
A = list(map(int, input().split() ) )

print( ' '.join(map(str, A)) )

for i in range(1, N):
    val = A[i]
    j = i - 1
    while j >= 0 and A[j] > val :
        A[j+1] = A[j]
        j -= 1
    A[j+1] = val
    print( ' '.join(map(str, A)) )
