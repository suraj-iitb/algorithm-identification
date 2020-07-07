n = int(input())
A = input().split()
for i in range(n):
    A[i] = int(A[i])

for i in range(n-1):
    print(A[i],end=" ")
print(A[n-1])


for i in range(1,n):
    v = A[i]
    j = i-1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j = j-1
    A[j+1] = v
    for i in range(n-1):
        print(A[i],end=" ")
    print(A[n-1])
