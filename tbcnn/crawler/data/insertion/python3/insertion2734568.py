def showlist(A):
    for i in range(len(A)):
        if i==len(A)-1:
            print(A[i])
        else:
            print(A[i], end=' ')

N = eval(input())
A = list(map(int, input().split()))
showlist(A)
for i in range(1,N):
    v = A[i]
    j = i - 1;
    while j>=0 and A[j] > v:
        A[j+1] = A[j]
        j = j - 1
    A[j+1] = v
    showlist(A)
