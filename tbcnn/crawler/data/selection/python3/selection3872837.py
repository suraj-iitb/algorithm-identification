#Selection sort

N=int(input())
A=list(map(int,input().split()))
counter=0

for i in range(N):
    minj=i
    for j in range(i,N):
        if A[j]<A[minj]: #最小値探し
            minj=j
    A[i],A[minj]=A[minj],A[i]
    if minj!=i:
        counter+=1

A_str=map(str,A)
string=" ".join(A_str)
print(string)
print(counter)

