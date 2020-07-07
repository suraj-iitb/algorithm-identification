n=int(input())
A=[int(i) for i in input().split()]

def show():
    maplist=map(str, A)
    maplist=' '.join(maplist)
    print(maplist)
show()
for i in range(1,n):
    key=A[i]
    j=i-1
    while j>=0 and A[j]>key:
        A[j+1]=A[j]
        j-=1
    A[j+1]=key
    show()
    
