N=int(input())
A=list(map(int,input().split(" ")))
print(" ".join(list(map(str,A))))
for i in range(1,N):
    tmp=A[i]
    j=i-1
    while(j>=0 and A[j]>tmp):
        A[j+1]=A[j]
        j-=1
    A[j+1]=tmp
    print(" ".join(list(map(str,A))))
