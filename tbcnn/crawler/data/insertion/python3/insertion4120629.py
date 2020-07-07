N = int(input())
A = list(map(int, input().split()))
s = ''
for a in A:
    s += str(a) + ' '
print(s.rstrip())

for i in range(1, N):
    for j in range(0, i):
        if A[i] < A[j]:
            A.insert(j, A.pop(i))
            break
    s = ''
    for a in A:
        s += str(a) + ' '
    print(s.rstrip())

