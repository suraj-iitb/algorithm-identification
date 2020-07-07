#bubble sort

N=int(input())
A=list(map(int,input().split()))
counter=0
flag=True
string=""
while flag:
    flag=False
    for j in range(N-1,0,-1):
        if A[j]<A[j-1]:
            A[j],A[j-1]=A[j-1],A[j]
            counter+=1
            flag=True

A_str=map(str,A)
string=" ".join(A_str)
print(string)
print(counter)

