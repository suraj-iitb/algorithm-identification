
N = int(input())

A = list(map(int,input().split()))

num = 0

flag = True

while flag:

    flag = False

    for j in range(N-1):

        j = N-1-j

        if A[j] < A[j-1]:

            oaj = A[j]

            A[j] = A[j-1]
            A[j-1] = oaj

            flag = True

            num += 1

print (" ".join(map(str,A)))
print (num)

