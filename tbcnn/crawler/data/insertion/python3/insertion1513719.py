n = int(input())
A = []
s = input()
A = list(map(int,s.split()))
for i in range(1,len(A)):
    v = A[i]
    j = i-1

    for k in range(0,len(A)-1):
        print(A[k],end=" ")
    print(A[len(A)-1])

    while(j >= 0 and A[j] > v):
        A[j+1] = A[j]
        j -= 1
        A[j+1] = v

for k in range(0,len(A)-1):
    print(A[k],end=" ")
print(A[len(A)-1])
