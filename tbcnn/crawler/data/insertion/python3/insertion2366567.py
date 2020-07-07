N = int(input())
s = input().split(" ")
A = list(map(int,s))
for i in range(N):
    if i == N-1:
        print(A[i])
    else:
        print(A[i],end=" ")
for i in range(1,N):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j + 1] = A[j]
        j -= 1
    A[j + 1] = v
    for i in range(N):
        if i == N-1:
            print(A[i])
        else:
            print(A[i],end=" ")
