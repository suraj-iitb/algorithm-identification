from sys import stdin
 
n = int(stdin.readline().rstrip())
A = [int(x) for x in stdin.readline().rstrip().split()]
print(*A)
for i in range(1, n):
    v = A[i]
    j = i-1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j = j-1
    else:
        A[j+1] = v
        print(*A)
