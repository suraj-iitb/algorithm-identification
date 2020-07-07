N = int(input())
A = list(map(int, input().split()))
s = [str(a) for a in A]
s = ' '.join(s)
print(s)

for i in range(1, N):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j + 1] = A[j]
        j -= 1
    A[j + 1] = v
    s = [str(a) for a in A]
    s = ' '.join(s)
    print(s)

