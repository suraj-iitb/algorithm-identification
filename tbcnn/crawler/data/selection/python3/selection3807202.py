
N = int(input())

A = list(map(int,input().split()))

num = 0

for i in range(N):

    minj = i

    for j in range(N-i):

        j += i

        if A[j] < A[minj]:

            minj = j

    if minj != i:
        num += 1

    oai = A[i]
    A[i] = A[minj]
    A[minj] = oai

print (" ".join(map(str,A)))
print (num)        

