n=int(input())
A=list(map(int, input().split()))
#A=input().split()

print(" ".join([str(i) for i in A]))
for i in range(1,len(A)):
    v=A[i]
    j=i-1
    while j>=0 and A[j]>v:
        A[j+1]=A[j]
        j-=1
    A[j+1]=v
    print(" ".join([str(i) for i in A]))

